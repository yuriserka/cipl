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

    char *build_tabs();
    void rm_n_tabs(char *s, const int qtd);
    void rm_char_at(char *s, unsigned int index);
    void string_literal_rm_dquote(char *s);
%}

DELIM [[:blank:]\n]
LETTER [[:alpha:]_]
DIGIT [[:digit:]]
LETTER_OR_DIGIT [[:alnum:]_]
HEX_DIGIT [[:xdigit:]]
TYPES "int list"|"float list"|"int"|"float"

OP_BIN_ARITHMETIC "*"|"/"|"%"|"+"|"-"
OP_BIN_BITWISE "&"|"^"|"|"|"^"|"<<"|">>"
OP_BIN_BOOL "&&"|"||"
OP_BIN_COMPARISON "<="|">="|"<"|">"|"!="|"=="
OP_BIN_LIST "<<"|">>"|":" 

OP_UNI_ARITHMETIC "-"|"++"|"--"
OP_UNI_BOOL "!"
OP_UNI_BITWISE "~"
OP_UNI_LIST "?"|"%"|"!"

WS {DELIM}+
ID {LETTER}{LETTER_OR_DIGIT}*
BINARY_OP {OP_BIN_ARITHMETIC}|{OP_BIN_COMPARISON}|{OP_BIN_BOOL}|{OP_BIN_BITWISE}|{OP_BIN_LIST}
UNARY_OP {OP_UNI_ARITHMETIC}|{OP_UNI_BOOL}|{OP_UNI_BITWISE}|{OP_UNI_LIST}
OP_ASSSIGN =|{OP_BIN_ARITHMETIC}=|{OP_BIN_BITWISE}=

INTEGER_NUMBER -?(0|[1-9]{DIGIT}*)
REAL_NUMBER {INTEGER_NUMBER}(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?
OCTAL_NUMBER 0[0-7]+
HEX_NUMBER 0[Xx]{HEX_DIGIT}+

MULTILINE_COMMENT ("/"+"*")([^*]|"*"[^/])*"*/"
SINGLELINE_COMMENT "//"[^\n]*

STRING_LITERAL \"([^"\\]|\\.)*\"

/* ESCAPE "\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\0"|"\\"[xX]{HEX_DIGIT}+|"\\"{OCTAL_NUMBER}|"\\"[uU]{HEX_DIGIT}+ */

%%
    /* eat comments */
<*>{MULTILINE_COMMENT}|{SINGLELINE_COMMENT}
<*>{WS} {}

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
            printf("<SEMI>%s%s", reading_args ? " " : "\n", tabs);
        } break;
    }
    free(tabs);
}

if { printf("<IF> "); }
else { printf("<ELSE> "); }
return { printf("<RETURN> "); }
break { printf("<BREAK> "); }
for { printf("<FOR> "); }
NIL { printf("<NIL> "); }

{TYPES} {
    printf("<TYPE, `%s`> ", yytext);
}

{ID} {
    printf("<ID, `%s`> ", yytext);
}

{INTEGER_NUMBER} {
    long int longval;
    sscanf(yytext, "%ld", &longval);
    printf("<INTNUM, `%ld`> ", longval);
}

{REAL_NUMBER} {
    double doubleval;
    sscanf(yytext, "%lf", &doubleval);
    printf("<REALNUM, `%lf`> ", doubleval);
}

{HEX_NUMBER} {
    unsigned int hexval;
    sscanf(yytext, "%x", &hexval);
    printf("<HEXNUM, `%s`=`%d`> ", yytext, hexval);
}

{OCTAL_NUMBER} {
    unsigned int octval;
    sscanf(yytext, "%o", &octval);
    printf("<OCTNUM, `%s`=`%d`> ", yytext, octval);
}

{UNARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case '-': {
            printf("<%s, `%s`> ", yyleng > 1 ? "DECREMENT_OP" : "SIGNCHANGEOP", token);
        } break;
        case '+': printf("<INCREMENT_OP, `%s`> ", token); break;
        // só será possivel decidir a ação na analise semantica
        // se !int = NOTOP senao !list = LISTTAILOP
        case '!': printf("<EXCLAMATIONOP, `%s`> ", token); break;
        case '?': printf("<QUESTIONMARKOP, `%s`> ", token); break;
        case '%': printf("<PERCENTOP, `%s`> ", token); break;
        case '~': printf("<BITOP, `%s`> ", token); break;
    }
}

{BINARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case ':': printf("<COLONOP> "); break;
        case '*':
        case '/':
        case '%':
        case '+':
        case '-': printf("<ARITHOP, `%s`> ", token); break;
        case '<':
        case '>': {
            const int is_dless = !strcmp(token, "<<");
            const int is_dgreat = !strcmp(token, ">>");

            const int is_cmp = !is_dless && !is_dgreat;

            if (is_cmp) printf("<INEQOP, `%s`> ", token);
            else printf("<%s> ", is_dless ? "DLESSOP" : "DGREATOP");
        } break;
        case '=': 
        case '!': printf("<EQOP, `%s`> ", token); break;
        case '^': printf("<BITOP, `%s`> ", token); break;
        case '&': printf("<%s, `%s`> ", yyleng > 1 ? "BOOLOP" : "BITOP", token); break;
        case '|': printf("<%s, `%s`> ", yyleng > 1 ? "BOOLOP" : "BITOP", token); break;
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
        case '>': printf("<RSHIFTEQ> "); break;
        case '<': printf("<LSHIFTEQ> "); break;
        default: printf("<EQ> ");
    }
}

{STRING_LITERAL} {
    char *str_dup = strdup(yytext);
    string_literal_rm_dquote(str_dup);
    printf("<STRINGLITERAL, `%s`> ", str_dup);
    free(str_dup);
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

void string_literal_rm_dquote(char *s) {
    unsigned int len = strlen(s);
    rm_char_at(s, 0); --len;
    rm_char_at(s, len - 1); --len;
    s = realloc(s, sizeof(char) * (len + 1));
}