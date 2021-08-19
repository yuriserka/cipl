%define lr.type canonical-lr

%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);
%}
/* declare tokens */
%union {
	int value;
}

%token<value> NUMBER
%token ADD SUB MUL DIV ABS
%token EOL
%token OP CP

%type<value> calclist exp factor term

%left ADD SUB
%left MUL DIV
%right ABS
%%

calclist: { /* nothing */ }
 | calclist exp EOL
 ;

exp: factor
 | exp ADD factor { $$ = $1 + $3; printf("ADD = %d\n", $$); }
 | exp SUB factor { $$ = $1 - $3; printf("SUB = %d\n", $$); }
 ;

factor: term
 | factor MUL term { $$ = $1 * $3; printf("MUL = %d\n", $$); } 
 | factor DIV term { $$ = $1 / $3; printf("DIV = %d\n", $$); } 
 ;

term: NUMBER
 | ABS term { $$ = $2 >= 0? $2 : - $2; printf("ABS = %d\n", $$); }
 | OP exp CP { $$ = $2; printf("HIGH_PRIOR_VALUE = %d\n", $$); }
 ;

%%

int main(int argc, char **argv) {
	return yyparse();
}

int yyerror(char *s) {
 fprintf(stderr, "error: %s\n", s);
 return 1;
}
