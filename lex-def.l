%option nounput noinput noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>

    int curr_tab = 0;
    int reading_string = 0;
    int reading_args = 0;

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

MULTILINE_COMMENT "/*"([^*]|"*"[^/])*"*/"
SINGLELINE_COMMENT "//"[^\n]*

TYPES {CORE_TYPES}|{NEW_TYPES}

ESCAPE "\\\\"|"\\0"|"\\a"|"\\b"|"\\t"|"\\n"|"\\v"|"\\f"|"\\r"|"\\e"|"\\"[xX]{HEX_DIGIT}+|"\\"{OCTAL_NUMBER}

%x expect_string

%%

<*>{MULTILINE_COMMENT}|{SINGLELINE_COMMENT}
<*>{WS} {
    if (!reading_string) {
        BEGIN(INITIAL);
    } else {
        yymore();
    }
}

<INITIAL>[\(\){};,] {
	BEGIN(INITIAL);
    const char punct = yytext[0];
    char *tabs = build_tabs();

    switch (punct) {
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
    return punct;
}

if { printf("<IF> "); return IF; }
else { printf("<ELSE> "); return ELSE; }
return { printf("<RETURN> "); return RETURN; }
break { printf("<BREAK> "); return BREAK; }
for { printf("<FOR> "); return FOR; }
NIL { printf("<LISTNIL> "); return NIL; }

{TYPES} {
    printf("<TYPE, `%s`> ", yytext);
    return TYPE;
}

{ID} {
    printf("<ID, `%s`> ", yytext);
    return ID;
}

{INTEGER_NUMBER} {
    long int longval;
    sscanf(yytext, "%ld", &longval);
    printf("<INTNUM, `%ld`> ", longval);
    return INT_NUM;
}

{REAL_NUMBER} {
    double doubleval;
    sscanf(yytext, "%lf", &doubleval);
    printf("<REALNUM, `%lf`> ", doubleval);
    return REAL_NUM;
}

{HEX_NUMBER} {
    unsigned int hexval;
    sscanf(yytext, "%x", &hexval);
    printf("<HEXNUM, `%s`=`%d`> ", yytext, hexval);
    return INT_NUM;
}

{OCTAL_NUMBER} {
    unsigned int octval;
    sscanf(yytext, "%o", &octval);
    printf("<OCTNUM, `%s`=`%d`> ", yytext, octval);
    return INT_NUM;
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
    return token[0];
}

{BINARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case ':': printf("<LISTPUSHOP> "); return LISTPUSHOP;
        case '*':
        case '/':
        case '%':
        case '+':
        case '-': printf("<ARITHOP, `%s`> ", token); return token[0];
        case '<':
        case '>': {
            const int is_dless = !strcmp(token, "<<");
            const int is_dgreat = !strcmp(token, ">>");

            const int is_cmp = !is_dless && !is_dgreat;

            if (is_cmp) printf("<INEQOP, `%s`> ", token);
            else printf("<%s> ", is_dless ? "LISTFILTEROP" : "LISTMAPOP");
            
            return is_cmp ? BINOP1 : BINOP2;
        } break;
        case '=': 
        case '!': printf("<EQOP, `%s`> ", token); return BINOP3;
        case '^': printf("<BITOP, `%s`> ", token); return BINOP5;
        case '&': {
            printf("<%s, `%s`> ", yyleng > 1 ? "BOOLOP" : "BITOP", token);
            return yyleng > 1 ? BINOP7 : BINOP4;
        }
        case '|': {
            printf("<%s, `%s`> ", yyleng > 1 ? "BOOLOP" : "BITOP", token);
            return yyleng > 1 ? BINOP8 : BINOP6;
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

    return ASSIGN;
}

{INCDEC_OP} {
    char *token = yytext;
    switch (token[0]) {
        case '+': printf("<INCREMENT_OP, `%s`> ", token); break;
        case '-': printf("<DECREMENT_OP, `%s`> ", token); break;
    }

    return INCDECOP;
}

\"/\("\\\""|{ESCAPE}|[^"\\]|{WS}\)*\" {
	BEGIN(expect_string);
	reading_string = 1;
	yymore();
}

<expect_string>"\\\""   |
<expect_string>{ESCAPE} |
<expect_string>[^"\\]   { yymore(); }

<expect_string>\" {
    BEGIN(INITIAL);
    reading_string = 0;

    char *const_string = yytext;
    printf("<CONSTSTR, `%s`> ", const_string);
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
