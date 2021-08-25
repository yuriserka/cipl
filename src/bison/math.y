%define lr.type canonical-lr
%define api.header.include {"bison/grammar.h"}
%{
	#include <stdio.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
%}

%union {
	struct cipl_ast *ast;
    struct cipl_symbol *sym;
	double real;
	int integer;
}

%token<integer> NUMBER_INT
%token<real> NUMBER_REAL
%token LET
%token LT LE GT GE EQ NE
%token<sym> NAME

%type<ast> external_declaration declaration declarator
%type<ast> expression assign_expr eq_expr rel_expr add_expr primary_expr id constant
%type<ast> mult_expr cast_expr postfix_expr arg_expr_list arg_expr_list.opt

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
    ;

declaration: LET declarator '=' eq_expr ';' {
        list_push(&root->children, ast_assign_init($2, $4));
    }
    | LET declarator '=' error ';' {
        cipl_perror("expected expression before ‘;’ token");
        yyerrok;
    }
    ;

declarator: id
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

void yyerror(char *s) {
 	cipl_perror("sintatic error: %s\n", s);
 	++errors_count;
}
