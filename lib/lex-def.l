%option nounput noinput noyywrap
%option outfile="src/main.c" header-file="include/flex/scanner.h"

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>

    int curr_tab = 0;
    int reading_string = 0;
    int reading_args = 0;
    int last_act;

    char error_message[512] = {0};

    typedef struct {
        int col;
        int line;
    } cursorpos;

    cursorpos err, curr;

    #define YY_UPDT_POS if ((last_act = yy_act) != -1) update_position(&curr.line, &curr.col);
    #define YY_BREAK YY_UPDT_POS break;
    #define RET YY_UPDT_POS return
    
    void update_position(int *lnum, int *lcol) {
        extern char *yytext;
        extern int yyleng;
        for (int i = 0; i < yyleng; i++) {
            if (yytext[i] == '\n') {
                ++(*lnum);
                *lcol = 0;
            } else {
                ++(*lcol);
            }
        }
    }

    char *build_tabs();
    void rm_n_tabs(char *s, const int qtd);
    void rm_char_at(char *s, unsigned int index);

    typedef enum {
        IF = 258,
        ELSE,
        RETURN,
        BREAK,
        FOR,
        NIL,
        TYPE,
        INT_NUM,
        REAL_NUM,
        ID,
        ASSIGN,
        INCDECOP,
        LISTPUSHOP,
        BINOP8, // //
        BINOP7, // &&
        BINOP6, // |
        BINOP5, // ^
        BINOP4, // &
        BINOP3, // == !=
        BINOP2, // > < >= <=
        BINOP1, // >> <<
        UNIOP,
        STRINGLITERAL,
    } yytokentypes;
%}

DELIM [[:blank:]\n]
LETTER [[:alpha:]_]
DIGIT [[:digit:]]
LETTER_OR_DIGIT [[:alnum:]_]
HEX_DIGIT [[:xdigit:]]
CORE_TYPES "int"|"float"
NEW_TYPES "int list"|"float list"

OP_ARITHMETIC "*"|"/"|"%"|"+"|"-"
OP_BIN_BITWISE "&"|"^"|"|"|"^"
OP_BOOL "&&"|"||"
OP_COMPARISON "<="|">="|"<"|">"|"!="|"=="

WS {DELIM}+
ID {LETTER}{LETTER_OR_DIGIT}*
BINARY_OP {OP_ARITHMETIC}|{OP_COMPARISON}|{OP_BOOL}|{OP_BIN_BITWISE}|"<<"|">>"|":"
UNARY_OP "+"|"-"|"!"|"~"|"?"|"%"
OP_ASSSIGN =|{OP_ARITHMETIC}=|{OP_BIN_BITWISE}=
INCDEC_OP "++"|"--"

INTEGER_NUMBER -?(0|[1-9]{DIGIT}*)
REAL_NUMBER {INTEGER_NUMBER}(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?
OCTAL_NUMBER 0[0-7]+
HEX_NUMBER 0[Xx]{HEX_DIGIT}+

MULTILINE_COMMENT ("/"+"*")([^*]|"*"[^/])*"*/"
SINGLELINE_COMMENT "//"[^\n]*
STRING_LITERAL_ESCAPE \("\\\""|{ESCAPE}|[^"\\]|{WS}\)

TYPES {CORE_TYPES}|{NEW_TYPES}

ESCAPE "\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\0"|"\\"[xX]{HEX_DIGIT}+|"\\"{OCTAL_NUMBER}|"\\"[uU]{HEX_DIGIT}+

%x string_literal

%%
    /* eat comments */
<*>{MULTILINE_COMMENT}|{SINGLELINE_COMMENT}
    /* eat spaces if not reading a string literal */
<*>{WS} {
    if (!reading_string) {
        BEGIN(INITIAL);
    } else {
        yymore();
    }
}

<INITIAL>[\(\){};,] {
	BEGIN(INITIAL);
    char *tabs = build_tabs();

    switch (yytext[0]) {
        case '(': reading_args = 1; printf("<LPARAN> "); break;
        case ')': reading_args = 0; printf("<RPARAN> "); break;
        case '{': {
            ++curr_tab;
            tabs = build_tabs();
            printf("\n%s", tabs);
        } break;
        case '}': {
            --curr_tab;
            rm_char_at(tabs, 0);
            printf("\n%s", tabs);
        } break;
        case ',': printf("<COMMA> "); break;
        case ';': {
            printf("<EOSTMT>%s%s", reading_args ? " " : "\n", tabs);
        } break;
    }
    free(tabs);
    RET yytext[0];
}

if { printf("<IF> "); RET IF; }
else { printf("<ELSE> "); RET ELSE; }
return { printf("<RETURN> "); RET RETURN; }
break { printf("<BREAK> "); RET BREAK; }
for { printf("<FOR> "); RET FOR; }
NIL { printf("<LISTNIL> "); RET NIL; }

{TYPES} {
    printf("<TYPE, `%s`> ", yytext);
    RET TYPE;
}

{ID} {
    printf("<ID, `%s`> ", yytext);
    RET ID;
}

{INTEGER_NUMBER} {
    long int longval;
    sscanf(yytext, "%ld", &longval);
    printf("<INTNUM, `%ld`> ", longval);
    RET INT_NUM;
}

{REAL_NUMBER} {
    double doubleval;
    sscanf(yytext, "%lf", &doubleval);
    printf("<REALNUM, `%lf`> ", doubleval);
    RET REAL_NUM;
}

{HEX_NUMBER} {
    unsigned int hexval;
    sscanf(yytext, "%x", &hexval);
    printf("<HEXNUM, `%s`=`%d`> ", yytext, hexval);
    RET INT_NUM;
}

{OCTAL_NUMBER} {
    unsigned int octval;
    sscanf(yytext, "%o", &octval);
    printf("<OCTNUM, `%s`=`%d`> ", yytext, octval);
    RET INT_NUM;
}

{UNARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case '+':
        case '-': printf("<SIGNEDNUMOP, `%s`> ", token); break;
        case '!': printf("<LISTTAILOP, `%s`> ", token); break;
        case '?': printf("<LISTHEADOP, `%s`> ", token); break;
        case '%': printf("<LISTTAILPOPOP, `%s`> ", token); break;
        case '~': printf("<BITOP, `%s`> ", token); break;
    }
    RET token[0];
}

{BINARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case ':': printf("<LISTPUSHOP> "); RET LISTPUSHOP;
        case '*':
        case '/':
        case '%':
        case '+':
        case '-': printf("<ARITHOP, `%s`> ", token); RET token[0];
        case '<':
        case '>': {
            const int is_dless = !strcmp(token, "<<");
            const int is_dgreat = !strcmp(token, ">>");

            const int is_cmp = !is_dless && !is_dgreat;

            if (is_cmp) printf("<INEQOP, `%s`> ", token);
            else printf("<%s> ", is_dless ? "LISTFILTEROP" : "LISTMAPOP");
            
            RET is_cmp ? BINOP1 : BINOP2;
        } break;
        case '=': 
        case '!': printf("<EQOP, `%s`> ", token); RET BINOP3;
        case '^': printf("<BITOP, `%s`> ", token); RET BINOP5;
        case '&': {
            printf("<%s, `%s`> ", yyleng > 1 ? "BOOLOP" : "BITOP", token);
            RET yyleng > 1 ? BINOP7 : BINOP4;
        }
        case '|': {
            printf("<%s, `%s`> ", yyleng > 1 ? "BOOLOP" : "BITOP", token);
            RET yyleng > 1 ? BINOP8 : BINOP6;
        }
    }
}

{OP_ASSSIGN} {
    char *token = yytext;
    switch (token[0]) {
        case '*': printf("<MULTEQ> "); break;
        case '/': printf("<DIVEQ> "); break;
        case '%': printf("<MODEQ> "); break;
        case '+': printf("<PLUSEQ> "); break;
        case '-': printf("<MINUSEQ> "); break;
        case '&': printf("<ANDEQ> "); break;
        case '^': printf("<XOREQ> "); break;
        case '|': printf("<OREQ> "); break;
        default: printf("<EQ> ");
    }

    RET ASSIGN;
}

{INCDEC_OP} {
    char *token = yytext;
    switch (token[0]) {
        case '+': printf("<INCREMENT_OP, `%s`> ", token); break;
        case '-': printf("<DECREMENT_OP, `%s`> ", token); break;
    }

    RET INCDECOP;
}

\"/{STRING_LITERAL_ESCAPE}*\" {
	BEGIN(string_literal);
	reading_string = 1;
	yymore();
}

<string_literal>"\\\""   |
<string_literal>{ESCAPE} |
<string_literal>[^"\\]   { yymore(); }

<string_literal>\" {
    BEGIN(INITIAL);
    reading_string = 0;

    char *const_string = yytext;
    printf("<STRINGLITERAL, `%s`> ", const_string);

    RET STRINGLITERAL;
}

%%

char *build_tabs() {
    char *v = calloc(curr_tab + 1, sizeof(char));
    for (int i = 0; !reading_args && i < curr_tab; ++i) strcat(v, "\t"); 
    return v;
}

void rm_char_at(char *str, unsigned int index) {
    memmove(&str[index], &str[index + 1], strlen(str) - index);
}

void rm_n_tabs(char *str, int n) {
    for (int i = 0; i < n; ++i) rm_char_at(str, 0);
}
