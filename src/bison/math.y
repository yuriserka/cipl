%define lr.type canonical-lr
%define api.header.include {"bison/grammar.h"}
%{
    #include <stdarg.h>
	#include <stdio.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/scope.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    Scope *current_scope;
    cursor_position error_cursor;
    ListNode *scopes;
%}

%union {
	struct cipl_ast *ast;
    struct cipl_symbol *sym;
    struct cipl_list_node *list;
	double real;
	int integer;
}

%token<integer> NUMBER_INT
%token<real> NUMBER_REAL
%token LET
%token LT LE GT GE EQ NE
%token<sym> NAME

%type<ast> external_declaration declaration declarator func_declaration
%type<ast> expression assign_expr eq_expr rel_expr add_expr primary_expr id constant
%type<ast> mult_expr cast_expr postfix_expr arg_expr_list arg_expr_list.opt

%type<list> id_list.opt id_list

%right '!' '='
%left '+' '-'
%left '*' '/'

%start prog
%%

prog: declarations
    ;

declarations: external_declaration declarations
    | %empty
    ;

external_declaration: declaration
    | func_declaration
    ;

declaration: LET declarator '=' eq_expr ';' {
        list_push(&root->children, ast_assign_init($2, $4));
    }
    | LET declarator '=' error ';' {
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", error_cursor);
        yyerrok;
        ast_free($2);
    }
    ;

func_declaration: LET declarator '(' id_list.opt ')' '=' eq_expr ';' {
        Scope *func_scope = scope_init();
        scope_add_child(current_scope, func_scope);
        list_push(&scopes, func_scope);
        AST *func = ast_userfunc_init(func_scope, $2, ast_params_init($4));
        list_push(&root->children, ast_assign_init(func, $7));
    }
    | LET declarator '(' id_list.opt ')' '=' error ';' {
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", error_cursor);
        yyerrok;
        ast_free($2);
        list_free($4, ast_child_free);
    }
    ;

declarator: id
    ;

id_list: id_list ',' id { list_push(&$$, $3); }
    | id { $$ = list_node_init($1); }
    ;

id_list.opt: %empty { }
    | id_list
    ;

expression: assign_expr
    ;

assign_expr: eq_expr
    | cast_expr '=' assign_expr
    ;

eq_expr: rel_expr
    | eq_expr EQ rel_expr { $$ = ast_cmpop_init("==", $1, $3); }
    | eq_expr NE rel_expr { $$ = ast_cmpop_init("!=", $1, $3); }
    ;

rel_expr: add_expr
    | rel_expr LT add_expr { $$ = ast_cmpop_init("<", $1, $3); }
    | rel_expr LE add_expr { $$ = ast_cmpop_init("<=", $1, $3); }
    | rel_expr GT add_expr { $$ = ast_cmpop_init(">", $1, $3); }
    | rel_expr GE add_expr { $$ = ast_cmpop_init(">=", $1, $3); }
    ;

add_expr: mult_expr
    | add_expr '+' mult_expr { $$ = ast_binop_init('+', $1, $3); }
    | add_expr '-' mult_expr { $$ = ast_binop_init('-', $1, $3); }
    ;

mult_expr: cast_expr
    | mult_expr '*' cast_expr { $$ = ast_binop_init('*', $1, $3); }
    | mult_expr '/' cast_expr { $$ = ast_binop_init('/', $1, $3); }
    ;

cast_expr: postfix_expr
    | '!' cast_expr { $$ = ast_uniop_init('!', $2); }
    | '-' cast_expr { $$ = ast_uniop_init('-', $2); }
    ;

postfix_expr: primary_expr
    | postfix_expr '(' arg_expr_list.opt ')'
    ;

arg_expr_list: assign_expr
    | arg_expr_list ',' assign_expr
    ;

arg_expr_list.opt: arg_expr_list
    | %empty { $$ = NULL; }
    ;

primary_expr: id
    | constant
    | '(' expression ')' { $$ = $2; }
    ;

id: NAME { $$ = ast_symref_init($1); }
    ;

constant: NUMBER_REAL { $$ = ast_number_init(REAL, (NumberValue){ .real=$1 }); }
    | NUMBER_INT { $$ = ast_number_init(INTEGER, (NumberValue){ .integer=$1 }); }
    ;

%%

void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    /* CIPL_PERROR("%s\n", s); */
}
