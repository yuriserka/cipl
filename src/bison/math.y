%define lr.type canonical-lr

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "data-structures/ast/ast.h"
    #include "utils/io.h"
	#include "utils/cursor-position.h"

	extern int errors_count;
    extern char *filename;

	extern int yylex();
    extern int yyparse();
    extern void yyerror(char* message);
    extern int yylex_destroy();
    extern FILE* yyin;
%}

%union {
	struct cipl_ast *ast;
	double real;
	int integer;
}

%token<integer> NUMBER_INT
%token<real> NUMBER_REAL
%token EOL

%type<ast> expr factor term

%left '+' '-'
%left '*' '/'
%right '!'
%%

calclist: %empty /* noop on epsilon */
    | calclist expr EOL {
        AST *ast = $2;
        printf("expr_total = %lf\n", ast_eval(ast));
        printf("{ ast: { "); ast_print(ast); printf("}, }\n");
        ast_free(ast);
    }
    | calclist EOL /* blank line or a comment */
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

int main(int argc, char **argv) {
	if (argc < 2) {
        cipl_printf_color(RED, "error: ");
        cipl_printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *pfile = fopen(argv[1], "r");

    if (!pfile) {
        cipl_printf_color(RED, "error: ");
        cipl_printf("could not open file at: %s\n", argv[1]);
        return 1;
    }

    yyin = pfile;
    (filename = strrchr(argv[1], '/')) ? ++filename : (filename = argv[1]);

    yyparse();

    if (errors_count) {
        cipl_printf_color(
            RED,
            "\n%d error%s generated.\n",
            errors_count, errors_count > 1 ? "s" : ""
        );
    }

    fclose(yyin);
    yylex_destroy();

    return errors_count > 0;
}

void yyerror(char *s) {
 	cipl_perror("sintatic error: %s\n", s);
 	++errors_count;
}
