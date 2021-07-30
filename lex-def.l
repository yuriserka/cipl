%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>

    int curr_tab = 0;
%}

DELIM [[:blank:]\n]
LETTER [[:alpha:]_]
DIGIT [[:digit:]]
LETTER_OR_DIGIT [[:alnum:]_]
HEX_DIGIT [[:xdigit:]]
TYPE number|bool|fn|string

OP_ARITHMETIC "*"|"/"|"%"|"+"|"-"
OP_BITWISE "&"|"^"|"|"
OP_BOOL "&&"|"||"
OP_COMPARISON "<="|">="|"<"|">"|"!="|"=="

WS {DELIM}+
ID {LETTER}{LETTER_OR_DIGIT}*
BINARY_OP {OP_ARITHMETIC}|{OP_COMPARISON}|{OP_BOOL}|{OP_BITWISE}|"<<"|">>"
OP_ASSSIGN =|{OP_ARITHMETIC}=|{OP_BITWISE}=

INTEGER_NUMBER -?(0|[1-9]{DIGIT}*)
REAL_NUMBER {INTEGER_NUMBER}(\.{DIGIT}+)?
OCTAL_NUMBER 0[0-7]*
HEX_NUMBER 0[Xx]{HEX_DIGIT}+

MULTILINE_COMMENT "/*"([^*]|"*"[^/])*"*/"
SINGLELINE_COMMENT "//"[^\n]*

RESERVED_KEYWORDS "if"|"return"

%%

<*>{MULTILINE_COMMENT}|{SINGLELINE_COMMENT}

<INITIAL>[\(\){};,] {
	BEGIN(INITIAL);
    const char punct = yytext[0];
    for (int i = 0; i < curr_tab - (punct == '}'); ++i) printf("\t");
    switch (punct) {
        case '(': printf("<LPARAN>\n"); break;
        case ')': printf("<RPARAN>\n"); break;
        case '{': ++curr_tab; printf("<BEGBLOCK>\n"); break;
        case '}': --curr_tab; printf("<ENDBLOCK>\n"); break;
        case ',': printf("<COMMA>\n"); break;
        case ';': printf("<EOSTMT>\n");
    }
}

{RESERVED_KEYWORDS} {
    const int len = strlen(yytext);
    char *upper = calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; ++i) {
        upper[i] = toupper(yytext[i]);
    }
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    printf("<%s>\n", upper);
    free(upper);
}

{WS} { }

{TYPE} {
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    printf("<TYPE, %s>\n", yytext);
}

{ID} {
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    printf("<ID, `%s`>\n", yytext);
}

{REAL_NUMBER} {
    double doubleval;
    sscanf(yytext, "%lf", &doubleval);
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    printf("<DECNUM, `%lf`>\n", doubleval);
}

{HEX_NUMBER} {
    unsigned int hexval;
    sscanf(yytext, "%x", &hexval);
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    printf("<HEXNUM, `%s`=`%d`>\n", yytext, hexval);
}

{OCTAL_NUMBER} {
    unsigned int octval;
    sscanf(yytext, "%o", &octval);
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    printf("<OCTNUM, `%s`=`%d`>\n", yytext, octval);
}

{BINARY_OP} {
    char *token = yytext;
    for (int i = 0; i < curr_tab; ++i) printf("\t");
    switch (token[0]) {
        case '*':
        case '/':
        case '%':
        case '+':
        case '-': printf("<ARITHOP, `%s`>\n", token); break;
        case '<':
        case '>': {
            printf("<%s, `%s`>\n",
                strcmp(token, "<<") != 0 && strcmp(token, ">>") != 0 
                ? "INEQOP" 
                : "BITOP",
                token
            );
        } break;
        case '=':
        case '!':printf("<EQOP, `%s`>\n", token); break;
        case '^': printf("<BITOP, %s>\n", token); break;
        case '&':
        case '|':printf("<%s, %s>\n", strlen(token) > 1 ? "BOOLOP" : "BITOP", token); break;
    }
}

{OP_ASSSIGN} {
    char *token = yytext;
        for (int i = 0; i < curr_tab; ++i) printf("\t");
    switch (token[0]) {
        case '*': printf("<MULTEQ>\n"); break;
        case '/': printf("<DIVEQ>\n"); break;
        case '%': printf("<MODEQ>\n"); break;
        case '+': printf("<PLUSEQ>\n"); break;
        case '-': printf("<MINUSEQ>\n"); break;
        case '&': printf("<ANDEQ>\n"); break;
        case '^': printf("<XOREQ>\n"); break;
        case '|': printf("<OREQ>\n"); break;
        default: printf("<EQ>\n");
    }
}

%%