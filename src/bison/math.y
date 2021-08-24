%define lr.type canonical-lr

%{
	#include <stdio.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"
%}

%union {
	struct cipl_ast *ast;
    struct cipl_symbol *sym;
	double real;
	int integer;
}

%token<integer> NUMBER_INT
%token<real> NUMBER_REAL
%token EOL LET
%token<sym> NAME

%type<ast> expr factor term stmt calclist

%right '!' '='
%left '+' '-'
%left '*' '/'

%start calclist
%%

calclist: %empty { $$ = NULL; }
    | calclist stmt EOL {
        AST *ast = $2;
        printf("expr_total = %lf\n", ast_eval(ast));
        printf("{ ast: { "); ast_print(ast); printf("}, }\n");
        ast_free(ast);
    }
    | calclist LET NAME '=' stmt EOL {
        AST *ast = $$;
        ast = ast_assign_init(ast_symref_init($3), $5);
        printf("defined %s = %lf\n", $3->name, ast_eval(ast)); 
        printf("{ ast: { "); ast_print(ast); printf("}, }\n");
        ast_free(ast);
    }
    | calclist EOL /* blank line or a comment */
    ;

stmt: expr
    ;

expr: factor
    | expr '+' factor { $$ = ast_binop_init('+', $1, $3); }
    | expr '-' factor { $$ = ast_binop_init('-', $1, $3); }
    ;

factor: term
    | factor '*' term { $$ = ast_binop_init('*', $1, $3); }
    | factor '/' term { $$ = ast_binop_init('/', $1, $3); }
    ;

term: NUMBER_REAL { $$ = ast_number_init(REAL, (NumberValue){ .real=$1 }); }
    | NUMBER_INT { $$ = ast_number_init(INTEGER, (NumberValue){ .integer=$1 }); }
    | '!' term { $$ = ast_uniop_init('!', $2); }
    | '-' term { $$ = ast_uniop_init('-', $2); }
    | '(' expr ')' { $$ = $2; }
    ;

%%

void yyerror(char *s) {
 	cipl_perror("sintatic error: %s\n", s);
 	++errors_count;
}
