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
    #include <stdbool.h>

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
    StackNode *parent_stacknode_ref;
    char *last_line_ref;
    bool p_ctx_name = true, is_fn_blck = false;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

    #define show_error_end(__R__, __FMT__, ...) {                  \
        Cursor beg = (Cursor){                                     \
            .line=__R__.first_line,                                \
            .col=__R__.last_column                                 \
        };                                                         \
        yyerror(beg.line, beg.col, NULL);                          \
        beg.line = (beg.line - 1) > 0 ? (beg.line - 1) : beg.line; \
        LineInfo *li = list_peek(&lines, beg.line - 1);            \
        li = li ? li : curr_line_info;                             \
        beg.col = strlen(li->text) + 1;                            \
        CIPL_PERROR_CURSOR(                                        \
            __FMT__,                                               \
            li->text,                                              \
            beg,                                                   \
            ##__VA_ARGS__                                          \
        );                                                         \
        yyerrok;                                                   \
    }

    #define show_error_range(__R__, __FMT__, ...) {                             \
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
%token<sym> NAME
%token<pchar> MULT ADD REL AND OR EQ COLON DL_DG EXCLAMATION PERCENT QUESTION STR_LITERAL
%token<pchar> INT FLOAT LIST READ WRITE
%token IF ELSE FOR RETURN

%type<pchar> unary_ops type

%type<ast> external_declaration var_declaration func_declaration block_item statement else_error
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
%destructor { LIST_FREE($$, { ast_free(__IT__->data); });  } <list>
%%

prog: external_declaration_list
    | %empty { show_error(@$, "ISO C-IPL forbids an empty translation unit\n"); }
    | error {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end(@1, "expected " WHT "';'" RESET " \n");
    }
    ;

external_declaration_list: external_declaration_list external_declaration { list_push(&root->children, $2); }
    | external_declaration { list_push(&root->children, $1); }
    ;

external_declaration: func_declaration
    | var_declaration
    | statement {
        show_error_range(@$, "statements are not allowed at top level\n");
        ast_free($1);
        $$ = NULL;
    }
    ;

var_declaration: type id ';' {
        Symbol *sym = context_has_symbol(current_context, $2);
        SymbolTypes decl_type = symbol_type_from_str($1);
        if (sym) {
            if (sym->scope) {
                show_error_range(@2, "redeclaration of " BCYN "'%s'\n" RESET, $2->name);
            } else if (sym->kind == FUNC) {
                show_error_range(@2, BBLU "'%s'" RESET " redeclared as different kind of symbol\n", $2->name);
            } else if (sym->type != decl_type) {
                show_error_range(@1, "conflicting types for " BCYN "'%s'\n" RESET, $2->name);
            }
            $$ = NULL;
        }
        else {
            symbol_update_type($2, decl_type);
            symbol_update_temp($2, current_context->t9n->temp++);
            $2->kind = VAR;
            $$ = ast_declaration_init(@$, 
                ast_symref_init(@2, context_declare_variable(current_context, $2))
            );
        }
        symbol_free($2);
        free($1);
    }
    | type ';' {
        show_error_range(@1, "useless " BGRN "'%s'" RESET " in empty declaration\n", $1);
        free($1);
        $$ = NULL;
    }
    | type id '=' error {
        show_error_range(@3, "expected " WHT "';'" RESET "\n");
        free($1);
        symbol_free($2);
        $$ = NULL;
    }
    | id id '=' error {
        show_error_range(@1, "unknown type name " BGRN "'%s'" RESET "\n", $1->name);
        symbol_free($1);
        symbol_free($2);
        $$ = NULL;
    }
    | id id ';' {
        show_error_range(@1, "unknown type name " BGRN "'%s'" RESET "\n", $1->name);
        symbol_free($1);
        symbol_free($2);
        $$ = NULL;
    }
    ;

func_declaration: type id '(' <ast>{
        p_ctx_name = true;
        Symbol *sym = context_has_symbol(current_context, $2);
        SymbolTypes decl_type = symbol_type_from_str($1);

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init($2->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            if (!sym->kind == FUNC) {
                show_error(@2, BCYN "'%s'" RESET " redeclared as different kind of symbol\n", $2->name);
            } else if (sym->type != decl_type) {
                show_error(@1, "conflicting types for " BBLU "'%s'\n" RESET, $2->name);
            } else {
                show_error(@2, "redefinition of " BBLU "'%s'\n" RESET, $2->name);
            }
            $$ = NULL;
        } else {
            symbol_update_type($2, decl_type);
            $2->kind = FUNC;
            Symbol *declared = context_declare_variable(previous_context, $2);
            if (!declared) {
                show_error(@2, BCYN "'%s'" RESET " redeclared as different kind of symbol\n", $2->name);
                $$ = NULL;
            } else {
                $$ = ast_symref_init(@2, declared);
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free($2);
        free($1);
    } param_list.opt { is_fn_blck = true; } ')' compound_stmt {
        $$ = ast_userfunc_init(@$, current_context, $4, ast_params_init(@5, $5), $8);
        current_context = previous_context;
        p_ctx_name = true;
    }
    | type '(' {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    } param_list.opt { is_fn_blck = true; } ')' compound_stmt {
        show_error_range(@2, "expected identifier before " WHT "'('" RESET "\n");
        free($1);
        LIST_FREE($4, { ast_free(__IT__->data); });
        ast_free($7);
        $$ = NULL;
        current_context = previous_context;
    }
    ;

param_list.opt: %empty { $$ = NULL; }
    | params_list
    ;

params_list: params_list ',' param_decl { list_push(&$1, $3); $$ = $1; }
    | param_decl { $$ = list_node_init($1); }
    | error {
        show_error_range(@1, "invalid list of parameters\n");
        $$ = NULL;
    }
    ;

param_decl: type id {
        Symbol *sym = context_has_symbol(current_context, $2);
        if (sym) {
            show_error_range(@2, "redefinition of parameter " BCYN "'%s'\n" RESET , $2->name);
            $$ = NULL;
        } else {
            symbol_update_type($2, symbol_type_from_str($1));
            symbol_update_temp($2, current_context->t9n->param++);
            $2->kind = PARAM;
            $$ = ast_symref_init(@$, context_declare_variable(current_context, $2));
        }
        symbol_free($2);
        free($1);
    }
    | type {
        show_error_range(@1, "expected identifier after " BGRN "'%s'" RESET "\n", $1);
        free($1);
        $$ = NULL;
    }
    | id {
        show_error_range(@1, "unknown type name for " BCYN "'%s'\n" RESET , $1->name);
        symbol_free($1);
        $$ = NULL;
    }
    ;

compound_stmt: '{' {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) {
            context_push_scope(current_context);
        } else {
            Scope *fn_scope = list_peek_reverse(&current_context->scopes, 1);
            scope_fill(
                fn_scope,
                context_found_scope(previous_context, fn_scope->last_parent)
            );
        }
        is_fn_blck = false;
    } block_item_list.opt '}' {
        $$ = ast_blockitems_init(@$, $3);
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
    ;

block_item_list.opt: block_item_list { $$ = $1; }
    | %empty { $$ = NULL; }
    ;

block_item_list: block_item_list block_item { list_push(&$1, $2); $$ = $1; }
    | block_item { $$ = list_node_init($1); }
    ;

block_item: var_declaration
    | statement
    | else_error
    ;

statement: expr_stmt
    | compound_stmt
    | cond_stmt
    | jmp_stmt
    | iter_stmt
    | io_stmt
    ;

io_stmt: READ '(' id ')' ';' {
        Symbol *param = context_search_symbol_scopes(current_context, $3);
        if (!param) {
            show_error_range(@3, BCYN "'%s'" RESET " undeclared (first use in this function)\n", $3->name);
            $$ = NULL;
        } else {
            $$ = ast_builtinfn_init(@$, $1, ast_symref_init(@3, param));
        }
        free($1);
        symbol_free($3);
    }
    | WRITE '(' expression ')' ';' {
        $$ = ast_builtinfn_init(@$, $1, $3);
        free($1);
    }
    | WRITE '(' string_literal ')' ';' {
        $$ = ast_builtinfn_init(@$, $1, $3);
        free($1);
    }
    | WRITE '(' error ')' ';' {
        show_error_range(@4, "expected expression before " WHT "')'" RESET " token\n");
        free($1);
        $$ = NULL;
    }
    | READ '(' error ')' ';' {
        show_error_range(@4, "expected identifier before " WHT "')'" RESET " token\n");
        free($1);
        $$ = NULL;
    }
    | READ '(' id ')' error {
        show_error_end(@5, "expected " WHT "';'" RESET " \n");
        free($1);
        symbol_free($3);
        $$ = NULL;
    }
    | WRITE '(' expression ')' error {
        show_error_end(@5, "expected " WHT "';'" RESET " \n");
        free($1);
        ast_free($3);
        $$ = NULL;
    }
    | WRITE '(' string_literal ')' error {
        show_error_end(@5, "expected " WHT "';'" RESET " \n");
        free($1);
        ast_free($3);
        $$ = NULL;
    }
    | WRITE error {
        show_error_range(@2, "expected " WHT "'('" RESET " token\n");
        free($1);
        $$ = NULL;
    }
    | READ error {
        show_error_range(@2, "expected " WHT "'('" RESET " token\n");
        free($1);
        $$ = NULL;
    }
    ;

expr_stmt: expression ';' { $$ = $1; }
    | error ';' {
        show_error_range(@1, "expected expression before " WHT "';'" RESET "\n");
        $$ = NULL;
    }
    ;

cond_stmt: IF '(' expression ')' statement %prec THEN {
        $$ = ast_flow_init(@$, current_context, $3, $5, NULL);
    }
    | IF '(' expression ')' statement ELSE statement {
        $$ = ast_flow_init(@$, current_context, $3, $5, $7);
    }
    | IF '(' expression ')' ELSE statement {
        show_error_range(@5, "expected expression before " WHT "'else'" RESET "\n");
        ast_free($3);
        ast_free($6);
        $$ = NULL;
    }
    | IF '(' error ')' statement %prec THEN {
        show_error_range(@3, "expected expression before " WHT "')'" RESET " token\n");
        ast_free($5);
        $$ = NULL;
    }
    | IF '(' error ')' statement ELSE statement {
        show_error_range(@3, "expected expression before " WHT "')'" RESET " token\n");
        ast_free($5);
        ast_free($7);
        $$ = NULL;
    }
    | IF '(' error ')' ELSE statement {
        show_error_range(@3, "expected expression before " WHT "')'" RESET " token\n");
        ast_free($6);
        $$ = NULL;
    }
    | IF error {
        show_error(@2, "expected " WHT "'('" RESET " token\n");
        $$ = NULL;
    }
    ;

else_error: ELSE statement {
        show_error_range(@1, WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free($2);
        $$ = NULL;
    }
    | error ELSE statement {
        show_error_range(@2, WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free($3);
        $$ = NULL;
    }

jmp_stmt: RETURN expression ';' { $$ = ast_jmp_init(@$, $2); }
    | RETURN error ';' {
        show_error_range(@2, "expected expression before " WHT "';'" RESET " token\n");
        $$ = NULL;
    }
    ;

iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement {
        $$ = ast_iter_init(@$, current_context, $3, $5, $7, $9);
    }
    | FOR '(' error ';' expression.opt ';' expression.opt ')' statement {
        show_error_range(@3, "expected expression before " WHT "';'" RESET " token\n");
        ast_free($5);
        ast_free($7);
        ast_free($9);
        $$ = NULL;
    }
    | FOR '(' expression.opt ';' error ';' expression.opt ')' statement {
        show_error_range(@5, "expected expression before " WHT "';'" RESET " token\n");
        ast_free($3);
        ast_free($7);
        ast_free($9);
        $$ = NULL;
    }
    | FOR '(' expression.opt ';' expression.opt ';' error ')' statement {
        show_error_range(@7, "expected expression before " WHT "')'" RESET " token\n");
        ast_free($3);
        ast_free($5);
        ast_free($9);
        $$ = NULL;
    }
    | FOR '(' error ')' {
        show_error(@4, "expected " WHT "';'" RESET " before " WHT "')'" RESET " token\n");
        $$ = NULL;
    }
    | FOR error {
        show_error(@2, "expected " WHT "'('" RESET " token\n");
        $$ = NULL;
    }
    ;

expression: logical_or_expr
    | unary_expr '=' logical_or_expr { $$ = ast_assign_init(@$, $1, $3); }
    | unary_expr '=' error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free($1);
        $$ = NULL;
    }
    | error '=' logical_or_expr {
        show_error_range(@1, "expected expression before " WHT "'='" RESET " token\n");
        ast_free($3);
        $$ = NULL;
    }
    ;

expression.opt: %empty { $$ = NULL; }
    | expression
    ;

logical_or_expr: logical_and_expr
    | logical_or_expr OR logical_and_expr {
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | logical_or_expr OR error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | logical_and_expr AND error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | eq_expr EQ error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | rel_expr REL error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | add_expr COLON list_expr {
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | add_expr DL_DG error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err($2, $1);
        $$ = NULL;
    }
    | add_expr COLON error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | add_expr ADD error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_binop_init(@$, $2, $1, $3);
        free($2);
    }
    | mult_expr MULT error {
        show_error_range(@3, "expected expression before " WHT "'%c'" RESET " token\n", yychar);
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
        $$ = ast_uniop_init(@$, $1, $2);
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
        AST *params = ast_params_init(@3, $3);
        if (!sym) {
            show_error_range(@1, "implicit declaration of function " BBLU "'%s'\n" RESET, $1->name);
            $$ = NULL;
            ast_free(params);
        } else {
            if (!sym->kind == FUNC) {
                show_error_range(@1, "called object " BCYN "'%s'" RESET " is not a function\n", sym->name);
                $$ = NULL;
                ast_free(params);
            } else {
                $$ = ast_funcall_init(@$, ast_symref_init(@1, sym), params);
            }
        }
        symbol_free($1);
    }
    ;

arg_expr_list: arg_expr_list ',' expression { list_push(&$1, $3); $$ = $1; }
    | expression { $$ = list_node_init($1); }
    | error {
        show_error_range(@1, "invalid list of arguments\n");
        $$ = NULL;
    }
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
            $$ = ast_symref_init(@$, sym);
        }
        symbol_free($1);
    }
    | constant
    | '(' expression ')' {
        if ($2) {
            --$2->rule_pos.first_column;
            ++$2->rule_pos.last_column;
        }
        $$ = $2;
    }
    | '(' error ')' {
        show_error_range(@2, "expected expression\n");
        $$ = NULL;
    }
    | id error {
        show_error_range(@2, "expected " WHT "';'" RESET "\n");
        symbol_free($1);
        $$ = NULL;
    }
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

constant: NUMBER_REAL { $$ = ast_number_init(@$, K_REAL, (NumberValue){ .real=$1 }); }
    | NUMBER_INT { $$ = ast_number_init(@$, K_INTEGER, (NumberValue){ .integer=$1 }); }
    | NIL { $$ = ast_number_init(@$, K_NIL, (NumberValue){ .integer=$1 }); }
    ;

string_literal: STR_LITERAL {
        $$ = ast_str_init(@$, $1);
        free($1);
    }
    ;

%%

void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) {
        CIPL_PRINTF_COLOR(BRED, "%s\n" BYEL "%s:%d:%d: at line: %s" RESET "\n",
                          s, filename, cursor.line, cursor.col, last_line_ref);
    } */
    
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
