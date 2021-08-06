%option nounput noinput noyywrap
%option outfile="src/main.c" header-file="include/flex/scanner.h"

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "utils/io.h"
    #include "utils/str2num.h"
    #include "utils/str-unescape.h"
    #include "utils/cursor-position.h"

    int errors_count = 0;
    char *filename;

    cursor_position cursor = {.col=1, .line=1};

    void str_rm_n_char_from_beg(char *s, const int qtd);
    void str_rm_char_at(char *s, unsigned int index);
    void str_2_upper(char *s, char *d);
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
RESERVED_KEYWORDS if|else|return|break|for|NIL

%%

<*>{MULTILINE_COMMENT}|{SINGLELINE_COMMENT}
<*>{WS} {
    switch (yytext[0]) {
        case '\n':
            ++cursor.line;
            cursor.col = 1;
            break;
        default:
            cursor.col += yyleng;
    }
}

<INITIAL>[\(\){};,] {
	BEGIN(INITIAL);

    switch (yytext[0]) {
        case '(': printf("<LPARAN>\n"); break;
        case ')': printf("<RPARAN>\n"); break;
        case '{': printf("<LBRACE>\n"); break;
        case '}': printf("<RBRACE>\n"); break;
        case ',': printf("<COMMA>\n"); break;
        case ';': printf("<SEMI>\n"); break;
    }
    cursor.col += yyleng;
}

{RESERVED_KEYWORDS} {
    char *upper = calloc(yyleng, sizeof(char));
    str_2_upper(yytext, upper);
    printf("<%s>\n", upper);
    free(upper);
}

{TYPES} {
    printf("<TYPE, `%s`>\n", yytext);
    cursor.col += yyleng;
}

{ID} {
    printf("<ID, `%s`>\n", yytext);
    cursor.col += yyleng;
}

{INTEGER_NUMBER} {
    long int longval;
    sscanf(yytext, "%ld", &longval);
    printf("<INTNUM, `%ld`>\n", longval);
    cursor.col += yyleng;
}

{REAL_NUMBER} {
    double doubleval;
    sscanf(yytext, "%lf", &doubleval);
    printf("<REALNUM, `%lf`>\n", doubleval);
    cursor.col += yyleng;
}

{HEX_NUMBER} {
    unsigned int hexval;
    sscanf(yytext, "%x", &hexval);
    printf("<HEXNUM, `%s`=`%d`>\n", yytext, hexval);
    cursor.col += yyleng;
}

{OCTAL_NUMBER} {
    unsigned int octval;
    sscanf(yytext, "%o", &octval);
    printf("<OCTNUM, `%s`=`%d`>\n", yytext, octval);
    cursor.col += yyleng;
}

{UNARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case '-': {
            printf("<%s, `%s`>\n", yyleng > 1 ? "DECREMENT_OP" : "SIGNCHANGEOP", token);
        } break;
        case '+': printf("<INCREMENT_OP, `%s`>\n", token); break;
        // só será possivel decidir a ação na analise semantica
        // se !int = NOTOP senao !list = LISTTAILOP
        case '!': printf("<EXCLAMATIONOP, `%s`>\n", token); break;
        case '?': printf("<QUESTIONMARKOP, `%s`>\n", token); break;
        case '%': printf("<PERCENTOP, `%s`>\n", token); break;
        case '~': printf("<BITOP, `%s`>\n", token); break;
    }
    cursor.col += yyleng;
}

{BINARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case ':': printf("<COLONOP>\n"); break;
        case '*':
        case '/':
        case '%':
        case '+':
        case '-': printf("<ARITHOP, `%s`>\n", token); break;
        case '<':
        case '>': {
            const int is_dless = !strcmp(token, "<<");
            const int is_dgreat = !strcmp(token, ">>");

            const int is_cmp = !is_dless && !is_dgreat;

            if (is_cmp) printf("<INEQOP, `%s`>\n", token);
            else printf("<%s>\n", is_dless ? "DLESSOP" : "DGREATOP");
        } break;
        case '=': 
        case '!': printf("<EQOP, `%s`>\n", token); break;
        case '^': printf("<BITOP, `%s`>\n", token); break;
        case '&': printf("<%s, `%s`>\n", yyleng > 1 ? "BOOLOP" : "BITOP", token); break;
        case '|': printf("<%s, `%s`>\n", yyleng > 1 ? "BOOLOP" : "BITOP", token); break;
    }
    cursor.col += yyleng;
}

{OP_ASSSIGN} {
    char *token = yytext;
    switch (token[0]) {
        case '*': printf("<MULTEQ>\n"); break;
        case '/': printf("<DIVEQ>\n"); break;
        case '%': printf("<MODEQ>\n"); break;
        case '+': printf("<PLUSEQ>\n"); break;
        case '-': printf("<MINUSEQ>\n"); break;
        case '&': printf("<ANDEQ>\n"); break;
        case '^': printf("<XOREQ>\n"); break;
        case '|': printf("<OREQ>\n"); break;
        case '>': printf("<RSHIFTEQ>\n"); break;
        case '<': printf("<LSHIFTEQ>\n"); break;
        default: printf("<EQ>\n");
    }
    cursor.col += yyleng;
}

{STRING_LITERAL} {
    char *str_dup = strdup(yytext);
    string_literal_rm_dquote(str_dup);
    char *unescaped = str_literal_unescape(str_dup);
    printf("<STRINGLITERAL, `%s`>\n", unescaped);
    free(str_dup);
    free(unescaped);
}

. {
    cipl_perror("Unexpected Character: %s\n", yytext);
    ++errors_count;
    cursor.col += yyleng;
}

%%

int main(int argc, char **argv){
    if (argc < 2) {
        cipl_printf_color(RED, "usage: %s filename", argv[0]);
        return 1;
    }

    FILE *pfile = fopen(argv[1], "r");

    if (!pfile) {
        cipl_printf_color(RED, "could not open file at: %s\n", argv[1]);
        return 1;
    }

    yyin = pfile;
    (filename = strrchr(argv[1], '/')) ? ++filename : (filename = argv[1]);

    yylex();

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

void str_rm_char_at(char *str, unsigned int index) {
    memmove(&str[index], &str[index + 1], strlen(str) - index);
}

void str_rm_n_char_from_beg(char *str, int n) {
    for (int i = 0; i < n; ++i) str_rm_char_at(str, 0);
}

void string_literal_rm_dquote(char *s) {
    unsigned int len = strlen(s);
    str_rm_char_at(s, 0); --len;
    str_rm_char_at(s, len - 1); --len;
    s = realloc(s, sizeof(char) * (len + 1));
}

void str_2_upper(char *s, char *d) {
    char *psrc = s;
    while (*psrc != '\0') *d++ = toupper(*psrc++);
}
