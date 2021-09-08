%define lr.type canonical-lr
%define parse.error detailed
%define api.header.include {"bison/grammar.h"}
%define parse.lac full
%locations
%parse-param {int line}
%parse-param {int col}

%{
    #include <stdarg.h>
	#include <stdio.h>
    #include <string.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/stack.h"
    #include "data-structures/context.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    StackNode *scopes;
    ListNode *contexts;
    Cursor error_cursor;
    Context *current_context;
    Context *previous_context;
    Scope *params_scope;
    StackNode *parent_stacknode_ref;
    char *last_line_ref;
    int p_ctx_name = 1;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

    #define p_error_ctx_info {                                                       \
        if (p_ctx_name) {                                                            \
            if (current_context->current_scope) {                                    \
                CIPL_PRINTF(WHT "%s:" RESET " In function " BBLU "'%s'" RESET ":\n", \
                            filename, current_context->name);                        \
            } else {                                                                 \
                CIPL_PRINTF(WHT "%s:" RESET " At top level:\n", filename);           \
            }                                                                        \
            p_ctx_name = 0;                                                          \
        }                                                                            \
    }

    #define show_error_range(__R__, __FMT__, ...) {                             \
        p_error_ctx_info;                                                       \
        Cursor beg = (Cursor){.line=__R__.first_line, .col=__R__.first_column}; \
        Cursor end = (Cursor){.line=__R__.last_line, .col=__R__.last_column};   \
        yyerror(end.line, end.col, NULL);                                       \
        LineInfo *li = list_peek(&lines, beg.line - 1);                         \
        li = li ? li : curr_line_info;                                          \
        CIPL_PERROR_CURSOR_RANGE(                                               \
            __FMT__,                                                            \
            li->text,                                                           \
            beg,                                                                \
            end,                                                                \
            ##__VA_ARGS__                                                       \
        );                                                                      \
        yyerrok;                                                                \
    }

    #define show_error(__R__, __FMT__, ...) {                  \
        p_error_ctx_info;                                      \
        yyerror(__R__.last_line, __R__.last_column, NULL);     \
        LineInfo *li = list_peek(&lines, __R__.last_line - 1); \
        li = li ? li : curr_line_info;                         \
        CIPL_PERROR_CURSOR(                                    \
            __FMT__,                                           \
            li->text,                                          \
            error_cursor,                                      \
            ##__VA_ARGS__                                      \
        );                                                     \
        yyerrok;                                               \
    }

    #define cleanup_expr_err(__OP__, __AST__) \
        { free(__OP__); ast_free(__AST__); }

%}

%union {
	struct cipl_ast *ast;
    struct cipl_symbol *sym;
    struct cipl_list_node *list;
    char *pchar;
	double real;
	int integer;
}

%token<integer> NUMBER_INT NIL
%token<real> NUMBER_REAL
%token<sym> NAME READ WRITE
%token<pchar> MULT ADD REL AND OR EQ COLON DL_DG EXCLAMATION PERCENT QUESTION STR_LITERAL
%token<pchar> INT FLOAT LIST
%token IF ELSE FOR RETURN

%type<pchar> unary_ops type

%type<ast> external_declaration var_declaration func_declaration block_item statement
%type<ast> expression eq_expr rel_expr add_expr primary_expr constant string_literal
%type<ast> mult_expr unary_expr postfix_expr compound_stmt logical_and_expr logical_or_expr
%type<ast> expr_stmt jmp_stmt cond_stmt expression.opt iter_stmt list_expr param_decl io_stmt

%type<list> block_item_list block_item_list.opt arg_expr_list arg_expr_list.opt
%type<list> params_list param_list.opt

%type<sym> id

%nonassoc THEN
%nonassoc ELSE

%start prog

%destructor { free($$); } <pchar>
%destructor { symbol_free($$); } <sym>
%destructor { ast_free($$); } <ast>
%%

prog: external_declaration_list
    | %empty { show_error(@$, "ISO C-IPL forbids an empty translation unit\n"); }
    ;

external_declaration_list: external_declaration_list external_declaration { list_push(&root->children, $2); }
    | external_declaration { list_push(&root->children, $1); }
    ;

external_declaration: func_declaration
    | var_declaration
    | statement {
        show_error_range(@$, "statements are not allowed at top level\n");
        $$ = NULL;
        ast_free($1);
    }
    ;

var_declaration: type id <ast>{
        Symbol *sym = context_has_symbol(current_context, $2);
        SymbolTypes decl_type = symbol_type_from_str($1);
        if (sym) {
            if (sym->scope) {
                show_error_range(@2, "redeclaration of " BCYN "'%s'\n" RESET, $2->name);
            } else if (sym->is_fn) {
                show_error_range(@2, BBLU "'%s'" RESET " redeclared as different kind of symbol\n", $2->name);
            } else if (sym->type != decl_type) {
                show_error_range(@1, "conflicting types for " BCYN "'%s'\n" RESET, $2->name);
            }
            $$ = NULL;
        }
        else {
            Symbol *declared = context_declare_variable(current_context, $2);
            symbol_update_type(declared, decl_type);
            $$ = ast_symref_init(symbol_init_copy(declared));
        }
        symbol_free($2);
        free($1);
    } ';' {
        $$ = $3 ? ast_declaration_init($3) : NULL;
    }
    | type ';' {
        show_error_range(@1, "useless " BGRN "'%s'" RESET " in empty declaration\n", $1);
        $$ = NULL;
        free($1);
    }
    ;

func_declaration: type id '(' <ast>{
        p_ctx_name = 1;
        Symbol *sym = context_has_symbol(current_context, $2);
        SymbolTypes decl_type = symbol_type_from_str($1);

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init($2->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            if (!sym->is_fn) {
                show_error(@2, BCYN "'%s'" RESET " redeclared as different kind of symbol\n", $2->name);
            } else if (sym->type != decl_type) {
                show_error(@1, "conflicting types for " BBLU "'%s'\n" RESET, $2->name);
            } else {
                show_error(@2, "redefinition of " BBLU "'%s'\n" RESET, $2->name);
            }
            $$ = NULL;
        } else {
            Symbol *declared = context_declare_function(previous_context, $2);
            if (!declared) {
                show_error(@2, BCYN "'%s'" RESET " redeclared as different kind of symbol\n", $2->name);
                $$ = NULL;
            } else {
                symbol_update_type(declared, decl_type);
                $$ = ast_symref_init(symbol_init_copy(declared));
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free($2);
        free($1);
    } param_list.opt ')' {
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    } compound_stmt {
        $$ = ast_userfunc_init(current_context, $4, ast_params_init($5), $8);
        current_context = previous_context;
        p_ctx_name = 1;
    }
    ;

param_list.opt: %empty { $$ = NULL; }
    | params_list
    ;

params_list: params_list ',' param_decl { list_push(&$$, $3); }
    | param_decl { $$ = list_node_init($1); }
    ;

param_decl: type id {
        symbol_update_context($2, current_context);
        symbol_update_type($2, symbol_type_from_str($1));
        Symbol *sym = context_has_symbol(current_context, $2);
        if (sym) {
            show_error_range(@2, "redefinition of parameter " BCYN "'%s'\n" RESET , $2->name);
            $$ = NULL;
        } else {
            context_declare_variable(current_context, $2);
            $$ = ast_symref_init(symbol_init_copy($2));
        }
        symbol_free($2);
        free($1);
    }
    ;

compound_stmt: '{' {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        // hack to update the current scope
        if (params_scope) {
            stack_push(&current_context->scopes, params_scope);
            current_context->current_scope = ((Scope *)stack_peek(&current_context->scopes))->index;
            params_scope = NULL;
        } else {
            context_push_scope(current_context);
        }
    } block_item_list.opt '}' {
        $$ = ast_blockitems_init($3);
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
    ;

block_item_list.opt: block_item_list { $$ = $1; }
    | %empty { $$ = NULL; }
    ;

block_item_list: block_item_list block_item { list_push(&$$, $2); }
    | block_item { $$ = list_node_init($1); }
    ;

block_item: var_declaration
    | statement
    ;

statement: expr_stmt
    | compound_stmt
    | cond_stmt
    | jmp_stmt
    | iter_stmt
    | io_stmt
    ;

io_stmt: READ '(' id ')' ';' {
        Symbol *func = context_search_symbol_scopes(current_context, $1);
        Symbol *param = context_search_symbol_scopes(current_context, $3);
        $$ = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free($1);
        symbol_free($3);
    }
    | WRITE '(' expression ')' ';' {
        Symbol *sym = context_search_symbol_scopes(current_context, $1);
        $$ = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), $3);
        symbol_free($1);
    }
    ;

expr_stmt: expression ';' { $$ = $1; }
    ;

cond_stmt: IF '(' expression ')' compound_stmt %prec THEN {
        $$ = ast_flow_init(current_context, $3, $5, NULL);
    }
    | IF '(' expression ')' compound_stmt ELSE compound_stmt {
        $$ = ast_flow_init(current_context, $3, $5, $7);
    }
    | IF '(' error ')' compound_stmt %prec THEN {
        show_error(@3, "expected expression before " WHT "')'" RESET " token\n");
        $$ = NULL;
        ast_free($5);
        yyerrok;
    }
    | IF '(' error ')' compound_stmt ELSE compound_stmt {
        show_error(@3, "expected expression before " WHT "')'" RESET " token\n");
        $$ = NULL;
        ast_free($5);
        ast_free($7);
        yyerrok;
    }
    ;

jmp_stmt: RETURN expression ';' { $$ = ast_jmp_init($2); }
    | RETURN error ';' {
        show_error_range(@1, WHT "'return'" RESET " with no value\n");
        $$ = NULL;
        yyerrok;
    }
    ;

iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement {
        $$ = ast_iter_init(current_context, $3, $5, $7, $9);
    }
    ;

expression: logical_or_expr
    | unary_expr '=' logical_or_expr { $$ = ast_assign_init($1, $3); }
    ;

expression.opt: %empty { $$ = NULL; }
    | expression
    ;

logical_or_expr: logical_and_expr
    | logical_or_expr OR logical_and_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | logical_or_expr OR error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error OR logical_and_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

logical_and_expr: eq_expr
    | logical_and_expr AND eq_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | logical_and_expr AND error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error AND eq_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

eq_expr: rel_expr
    | eq_expr EQ rel_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | eq_expr EQ error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error EQ rel_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

rel_expr: list_expr
    | rel_expr REL list_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | rel_expr REL error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error REL list_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

list_expr: add_expr
    | add_expr DL_DG list_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | add_expr COLON list_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | add_expr DL_DG error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | add_expr COLON error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error DL_DG list_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    | error COLON list_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

add_expr: mult_expr
    | add_expr ADD mult_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | add_expr ADD error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error ADD mult_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

mult_expr: unary_expr
    | mult_expr MULT unary_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | mult_expr MULT error {
        show_error(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | error MULT unary_expr {
        show_error_range(@2, "expected expression before " WHT "'%s'" RESET " token\n", $2);
        cleanup_expr_err($2, $3);
        $$ = NULL;
    }
    ;

unary_expr: postfix_expr
    | unary_ops unary_expr {
        $$ = ast_uniop_init($1, $2);
        free($1);
    }
    ;

unary_ops: EXCLAMATION
    | PERCENT
    | ADD
    | QUESTION
    ;

postfix_expr: primary_expr
    | id '(' arg_expr_list.opt ')' {
        Symbol *sym = context_search_symbol_scopes(current_context, $1);
        if (!sym) {
            show_error_range(@1, "implicit declaration of function " BBLU "'%s'\n" RESET, $1->name);
            $$ = NULL;
        } else {
            if (!sym->is_fn) {
                show_error_range(@1, "called object " BCYN "'%s'" RESET " is not a function\n", sym->name);
                $$ = NULL;
            } else {
                $$ = ast_funcall_init(ast_symref_init(symbol_init_copy(sym)), ast_params_init($3));
            }
        }
        symbol_free($1);
    }
    ;

arg_expr_list: expression { $$ = list_node_init($1); }
    | arg_expr_list ',' expression { list_push(&$$, $3); }
    ;

arg_expr_list.opt: arg_expr_list
    | %empty { $$ = NULL; }
    ;

primary_expr: id {
        Symbol *sym = context_search_symbol_scopes(current_context, $1);
        if (!sym) {
            show_error_range(@1, BCYN "'%s'" RESET " undeclared (first use in this function)\n", $1->name);
            $$ = NULL;
        } else {
            symbol_update_context($1, current_context);
            $$ = ast_symref_init(symbol_init_copy(sym ? sym : $1));
        }
        symbol_free($1);
    }
    | constant
    | string_literal
    | '(' expression ')' { $$ = $2; }
    ;

id: NAME
    ;

type: INT
    | FLOAT
    | INT LIST {
        char *type = calloc(strlen($1) + strlen($2) + 2, sizeof(char));
        sprintf(type, "%s %s", $1, $2);
        free($1);
        free($2);
        $$ = type;
    }
    | FLOAT LIST {
        char *type = calloc(strlen($1) + strlen($2) + 2, sizeof(char));
        sprintf(type, "%s %s", $1, $2);
        free($1);
        free($2);
        $$ = type;
    }
    ;

constant: NUMBER_REAL { $$ = ast_number_init(K_REAL, (NumberValue){ .real=$1 }); }
    | NUMBER_INT { $$ = ast_number_init(K_INTEGER, (NumberValue){ .integer=$1 }); }
    | NIL { $$ = ast_number_init(K_NIL, (NumberValue){ .integer=$1 }); }
    ;

string_literal: STR_LITERAL {
        $$ = ast_str_init($1);
        free($1);
    }
    ;

%%

void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) CIPL_PERROR_CURSOR("%s\n", last_line_ref, error_cursor, s); */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
