%define lr.type canonical-lr
%define api.header.include {"bison/grammar.h"}
%{
    #include <stdarg.h>
	#include <stdio.h>

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
%token<sym> NAME

%type<ast> external_declaration declaration declarator func_declaration block_item statement
%type<ast> expression assign_expr eq_expr rel_expr add_expr primary_expr id constant
%type<ast> mult_expr cast_expr postfix_expr arg_expr_list arg_expr_list.opt compound_stmt
%type<ast> expr_stmt

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

declaration: LET declarator <ast>{
        Symbol *sym = context_has_symbol(current_context, $2->value.symref->symbol);
        if (sym) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("redeclaration of '%s'\n", error_cursor, $2->value.symref->symbol->name);
            $$ = NULL;
        } else {
            $$ = ast_symref_init(
                symbol_init_copy(context_declare_variable(current_context, $2->value.symref))
            );
        }
        ast_free($2);
    } ';' {
        $$ = $3 ? ast_declaration_init($3) : NULL;
    }
    | LET error ';' {
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        $$ = NULL;
        yyerrok;
    }
    ;

func_declaration: LET declarator '(' <ast>{
        if (current_context->current_scope) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("CIPL forbids nested functions\n", error_cursor);
            $$ = NULL;
        } else {
            Symbol *sym = context_has_symbol(current_context, $2->value.symref->symbol);
            if (sym) {
                yyerror(NULL);
                CIPL_PERROR_CURSOR("redefinition of '%s'\n", error_cursor, $2->value.symref->symbol->name);
                $$ = NULL;
            } else {
                previous_context = current_context;
                list_push(&contexts, context_init($2->value.symref->symbol->name));
                current_context = list_peek_last(&contexts);
                $$ = ast_symref_init(
                    symbol_init_copy(context_declare_function(previous_context, $2->value.symref))
                );
            }
        }
        ast_free($2);
    } id_list.opt ')' {
        LIST_FOR_EACH($5, {
            context_declare_variable(current_context, ((AST *)__IT__->data)->value.symref);
        });
    } '{' block_item_list.opt '}' {
        $$ = ast_userfunc_init(current_context, $4, ast_params_init($5), ast_blockitems_init($9));
        current_context = list_peek(&contexts, 0);
    }
    /* | LET error '(' id_list.opt ')' {
        CIPL_PERROR_CURSOR("expected identifier before '(' token\n", error_cursor);
        list_free($4, ast_child_free);
        $$ = NULL;
        yyerrok;
    } */
    ;

compound_stmt: '{' {
        // printf("found a code block on line:%d\n", cursor.line);
        // previous_scope = current_scope;
        // current_scope = scope_add(previous_scope);
        // printf("starting scope: %d\n", current_scope->index);
    } block_item_list.opt '}' {
        // printf("leaving scope: %d on line:%d\n", current_scope->index, cursor.line);
        // current_scope = previous_scope;
        $$ = ast_blockitems_init($3);
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

expr_stmt: expression ';' { $$ = $1; }
    ;

expression: assign_expr
    ;

assign_expr: eq_expr
    | cast_expr '=' assign_expr { $$ = ast_assign_init($1, $3); }
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

primary_expr: id {
        Symbol *sym = context_has_symbol(current_context, $1->value.symref->symbol);
        if (!sym) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("'%s' undeclared (first use in this function)\n", $1->value.symref->symbol->def_pos, $1->value.symref->symbol->name);
            // $$ Cant be NULL because crash everything up, the solution is push to AST an undeclared variable
            $$ = ast_symref_init(symbol_init_copy($1->value.symref->symbol)); // NULL
        } else {
            $$ = ast_symref_init(symbol_init_copy(sym));
        }
        ast_free($1);
    }
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
    /* CIPL_PERROR_CURSOR("%s\n", error_cursor, s); */
}
