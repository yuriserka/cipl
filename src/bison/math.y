%define lr.type canonical-lr
%define api.header.include {"bison/grammar.h"}
%{
    #include <stdarg.h>
	#include <stdio.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/stack.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    Scope *current_scope;
    cursor_position error_cursor;
    StackNode *scopes;
%}

%union {
	struct cipl_ast *ast;
    struct cipl_symbol *sym;
    struct cipl_list_node *list;
    char *identifier;
	double real;
	int integer;
}

%token<integer> NUMBER_INT
%token<real> NUMBER_REAL
%token LET
%token LT LE GT GE EQ NE
%token<identifier> NAME

%type<ast> external_declaration declaration declarator func_declaration block_item statement
%type<ast> expression assign_expr eq_expr rel_expr add_expr primary_expr id constant
%type<ast> mult_expr cast_expr postfix_expr arg_expr_list arg_expr_list.opt compound_stmt
%type<ast> expression_stmt

%type<list> id_list.opt id_list block_item_list block_item_list.opt prog

%right '!' '='
%left '+' '-'
%left '*' '/'

%start prog
%%

prog: prog external_declaration { list_push(&root->children, $2); }
    | external_declaration { list_push(&root->children, $1); }
    ;

external_declaration: func_declaration
    | declaration
    ;

declaration: LET declarator ';' {
        printf("found a variable\n");
        $$ = ast_declaration_init($2);
    }
    /* | LET declarator '=' error ';' {
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", error_cursor);
        yyerrok;
        ast_free($2);
    } */
    ;

func_declaration: LET declarator '(' id_list.opt ')' compound_stmt {
        printf("found a function\n");
        Scope *parent_scope = stack_peek(&scopes);
        symbol_table_insert(parent_scope->symbol_table, $2->value.symref->symbol->name);
        $$ = ast_userfunc_init(scope_add(parent_scope), $2, ast_params_init($4), $6);
    }
    /* | LET declarator '(' id_list.opt ')' ';' {
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", error_cursor);
        yyerrok;
        ast_free($2);
        list_free($4, ast_child_free);
    } */
    ;

compound_stmt: '{' block_item_list.opt '}' { $$ = ast_blockitems_init($2); }
    ;

block_item_list.opt: block_item_list { $$ = $1; }
    | %empty { $$ = NULL; }
    ;

block_item_list: block_item_list block_item { list_push(&$$, $2); }
    | block_item { $$ = list_node_init($1); }
    ;

block_item: declaration { $$ = $1; }
    | statement 
    ;

statement: expression_stmt
    ;

declarator: id
    | '(' declarator ')' { $$ = $2; }
    ;

id_list: id_list ',' id { list_push(&$$, $3); }
    | id { $$ = list_node_init($1); }
    ;

id_list.opt: %empty { $$ = NULL; }
    | id_list
    ;

expression_stmt: expression ';'
    ;

expression: assign_expr
    ;

assign_expr: eq_expr
    | cast_expr '=' assign_expr {
        printf("found assignment\n");
        $$ = ast_assign_init($1, $3);
    }
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

id: NAME {
        Scope *scope = stack_peek(&scopes);
        $$ = ast_symref_init(symbol_init($1, scope->index, cursor));
        free($1);
    }
    ;

constant: NUMBER_REAL { $$ = ast_number_init(REAL, (NumberValue){ .real=$1 }); }
    | NUMBER_INT { $$ = ast_number_init(INTEGER, (NumberValue){ .integer=$1 }); }
    ;

%%

void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    CIPL_PERROR("%s\n", s);
}
