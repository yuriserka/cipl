%define lr.type canonical-lr
%define parse.error verbose
%define api.header.include {"bison/grammar.h"}
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
    cursor_position error_cursor;
    Context *current_context;
    Context *previous_context;
    Scope *params_scope;
    int parent_scope = 0;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }
%}

%union {
	struct cipl_ast *ast;
    struct cipl_symbol *sym;
    struct cipl_list_node *list;
    char *pchar;
	double real;
	int integer;
}

%token<integer> NUMBER_INT
%token<real> NUMBER_REAL
%token<sym> NAME
%token<pchar> MULT ADD REL AND OR EQ COLON DL_DG EXCLAMATION PERCENT QUESTION STR_LITERAL
%token<pchar> INT FLOAT LIST
%token IF ELSE FOR RETURN LET NIL

%type<pchar> unary_ops type

%type<ast> external_declaration declaration declarator func_declaration block_item statement
%type<ast> expression assign_expr eq_expr rel_expr add_expr primary_expr id constant
%type<ast> mult_expr unary_expr postfix_expr compound_stmt logical_and_expr logical_or_expr
%type<ast> expr_stmt jmp_stmt cond_stmt expression.opt iter_stmt dl_dg_expr param_decl

%type<list> block_item_list block_item_list.opt prog arg_expr_list arg_expr_list.opt
%type<list> params_list param_list.opt 

%nonassoc THEN
%nonassoc ELSE

%start prog

%destructor { free($$); } <pchar>
%%

prog: prog external_declaration { list_push(&root->children, $2); }
    | external_declaration { list_push(&root->children, $1); }
    ;

external_declaration: func_declaration
    | declaration
    ;

declaration: type declarator <ast>{
        // Symbol *sym = context_has_symbol(current_context, $2->value.symref->symbol);
        // if (sym) {
        //     yyerror(NULL);
        //     CIPL_PERROR_CURSOR("redeclaration of '%s'\n", error_cursor, $2->value.symref->symbol->name);
        //     $$ = NULL;
        // } else {
        //     $$ = ast_symref_init(
        //         symbol_init_copy(context_declare_variable(current_context, $2->value.symref))
        //     );
        // }
        $$ = ast_symref_init(
            $1,
            symbol_init_copy(context_declare_variable(current_context, $2->value.symref))
        );
        ast_free($2);
        free($1);
    } ';' {
        $$ = $3 ? ast_declaration_init($3) : NULL;
    }
    | LET error ';' {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        $$ = NULL;
        yyerrok;
    }
    ;

func_declaration: type declarator '(' <ast>{
        if (current_context->current_scope > 1) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("CIPL forbids nested functions\n", error_cursor);
            $$ = NULL;
        } else {
            // Symbol *sym = context_has_symbol(current_context, $2->value.symref->symbol);
            // if (sym) {
            //     yyerror(NULL);
            //     CIPL_PERROR_CURSOR("redefinition of '%s'\n", error_cursor, $2->value.symref->symbol->name);
            //     $$ = NULL;
            // } else {
            //     previous_context = current_context;
            //     list_push(&contexts, context_init($2->value.symref->symbol->name));
            //     current_context = list_peek_last(&contexts);
            //     $$ = ast_symref_init(
            //         symbol_init_copy(context_declare_function(previous_context, $2->value.symref))
            //     );
            // }
            previous_context = current_context;
            list_push(&contexts, context_init($2->value.symref->symbol->name));
            current_context = list_peek_last(&contexts);
            $$ = ast_symref_init(
                $1,
                symbol_init_copy(context_declare_function(previous_context, $2->value.symref))
            );
        }
        ast_free($2);
        free($1);
    } param_list.opt ')' {
        context_push_scope(current_context);
        LIST_FOR_EACH($5, {
            symbol_update_context(((AST *)__IT__->data)->value.symref->symbol, current_context);
            context_declare_variable(current_context, ((AST *)__IT__->data)->value.symref);
        });
        // hack to save the scope of params and append to the scope of the body
        {
            params_scope = scope_init_copy(stack_peek(&current_context->scopes));
            stack_pop(&current_context->scopes, free_scope_cb);
        }
    } compound_stmt {
        $$ = ast_userfunc_init(current_context, $4, ast_params_init($5), $8);
        current_context = previous_context;
    }
    ;

param_list.opt: %empty { $$ = NULL; }
    | params_list
    ;

params_list: params_list ',' param_decl { list_push(&$$, $3); }
    | param_decl { $$ = list_node_init($1); }
    ;

param_decl: declarator
    ;

compound_stmt: '{' {
        parent_scope = current_context->current_scope;
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
        current_context->current_scope = parent_scope;
    }
    ;

block_item_list.opt: block_item_list { $$ = $1; }
    | %empty { $$ = NULL; }
    ;

block_item_list: block_item_list block_item { list_push(&$$, $2); }
    | block_item { $$ = list_node_init($1); }
    ;

block_item: declaration
    | statement
    ;

statement: expr_stmt
    | compound_stmt
    | cond_stmt
    | jmp_stmt
    | iter_stmt
    ;

declarator: id
    | '(' declarator ')' { $$ = $2; }
    ;

expr_stmt: expression ';' { $$ = $1; }
    ;

cond_stmt: IF '(' expression ')' statement %prec THEN {
        $$ = ast_flow_init(current_context, $3, $5, NULL);
    }
    | IF '(' expression ')' statement ELSE statement {
        $$ = ast_flow_init(current_context, $3, $5, $7);
    }
    ;

jmp_stmt: RETURN expression ';' { $$ = ast_jmp_init($2); }
    ;

iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement {
        $$ = ast_iter_init(current_context, $3, $5, $7, $9);
    }
    ;

expression: assign_expr
    ;

expression.opt: %empty { $$ = NULL; }
    | expression
    ;

assign_expr: logical_or_expr
    | unary_expr '=' assign_expr { $$ = ast_assign_init($1, $3); }
    ;

logical_or_expr: logical_and_expr
    | logical_or_expr OR logical_and_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    ;

logical_and_expr: eq_expr
    | logical_and_expr AND eq_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    ;

eq_expr: rel_expr
    | eq_expr EQ rel_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    ;

rel_expr: dl_dg_expr
    | rel_expr REL dl_dg_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    ;

dl_dg_expr: add_expr
    | add_expr DL_DG dl_dg_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    | add_expr COLON dl_dg_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    ;

add_expr: mult_expr
    | add_expr ADD mult_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
    }
    ;

mult_expr: unary_expr
    | mult_expr MULT unary_expr {
        $$ = ast_binop_init($2, $1, $3);
        free($2);
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
    | postfix_expr '(' arg_expr_list.opt ')' {
        $$ = ast_funcall_init($1, ast_params_init($3));
    }
    ;

arg_expr_list: assign_expr { $$ = list_node_init($1); }
    | arg_expr_list ',' assign_expr { list_push(&$$, $3); }
    ;

arg_expr_list.opt: arg_expr_list
    | %empty { $$ = NULL; }
    ;

primary_expr: id {
        // Symbol *sym = context_search_symbol_scopes(current_context, $1->value.symref->symbol);
        // if (!sym) {
        //     yyerror(NULL);
        //     CIPL_PERROR_CURSOR("'%s' undeclared (first use in this function)\n", $1->value.symref->symbol->def_pos, $1->value.symref->symbol->name);
        //     $$ = NULL;
        // } else {
        //     $$ = ast_symref_init(symbol_init_copy(sym));
        // }
        symbol_update_context($1->value.symref->symbol, current_context);
        $$ = ast_symref_init("int", symbol_init_copy($1->value.symref->symbol));
        ast_free($1);
    }
    | constant
    | '(' expression ')' { $$ = $2; }
    ;

id: NAME { $$ = ast_symref_init(NULL, $1); }
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

constant: NUMBER_REAL { $$ = ast_number_init(REAL, (NumberValue){ .real=$1 }); }
    | NUMBER_INT { $$ = ast_number_init(INTEGER, (NumberValue){ .integer=$1 }); }
    ;

%%

void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
