%option nounput noinput noyywrap
%option outfile="src/flex/lexer.c" header-file="lib/flex/scanner.h"

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "utils/io.h"
    #include "utils/string/2-num.h"
    #include "utils/string/unescape.h"
    #include "utils/string/find-occurrences.h"
    #include "utils/cursor-position.h"
    #include "bison/grammar.h"

    int errors_count = 0;
    char *filename;
    cursor_position dquote_open_pos, comment_open_pos;

    cursor_position cursor = {.line=1, .col=1};

    void str_rm_n_char_from_beg(char *s, const int qtd);
    void str_rm_char_at(char *s, unsigned int index);
    void str_2_upper(char *s, char *d);
    void string_literal_rm_dquote(char *s);
    void show_str_literal_err();
%}

DELIM [[:blank:]\n\r]
LETTER [[:alpha:]_]
DIGIT [[:digit:]]
LETTER_OR_DIGIT [[:alnum:]_]
TYPES "int list"|"float list"|"int"|"float"

OP_BIN_ARITHMETIC "*"|"/"|"+"|"-"
OP_BIN_BOOL "&&"|"||"
OP_BIN_COMPARISON "<="|">="|"<"|">"|"!="|"=="
OP_BIN_LIST "<<"|">>"|":"

OP_UNI_BOOL "!"
OP_UNI_LIST "?"|"%"|"!"

WS {DELIM}
ID {LETTER}{LETTER_OR_DIGIT}*
BINARY_OP {OP_BIN_ARITHMETIC}|{OP_BIN_COMPARISON}|{OP_BIN_BOOL}|{OP_BIN_LIST}
UNARY_OP {OP_UNI_BOOL}|{OP_UNI_LIST}
OP_ASSSIGN "="

INTEGER_NUMBER [+-]?(0|[1-9]{DIGIT}*)
REAL_NUMBER ({DIGIT}*[.])?{DIGIT}+([eE][+-]?{DIGIT}+)?

SINGLELINE_COMMENT "//"[^\n]*

RESERVED_KEYWORDS if|else|return|for|NIL
BUILTIN_FNS read|write|writeln

%x SCANNING_STR_LITERAL
%x SCANNING_MULTILINE_COMMENT

%%

{SINGLELINE_COMMENT} { /* noop */ }

{WS} {
    switch (yytext[0]) {
        case ' ':
        case '\t': cursor_position_update(0, yyleng); break;
        default: cursor_position_update(yyleng, 0); break;
    }
}

<INITIAL>[\(\){};,] {
    switch (yytext[0]) {
        case '(': printf("<LPARAN>\n"); break;
        case ')': printf("<RPARAN>\n"); break;
        case '{': printf("<LBRACE>\n"); break;
        case '}': printf("<RBRACE>\n"); break;
        case ',': printf("<COMMA>\n"); break;
        case ';': printf("<SEMI>\n"); break;
    }
    cursor_position_update(0, yyleng);
}

{BUILTIN_FNS} {
    switch (yytext[0]) {
        case 'r': printf("<IN, `%s`>\n", yytext); break;
        default: printf("<OUT, `%s`>\n", yytext); break;
    }
    cursor_position_update(0, yyleng);
}

{RESERVED_KEYWORDS} {
    char *upper = calloc(yyleng + 1, sizeof(char));
    str_2_upper(yytext, upper);
    printf("<%s>\n", upper);
    free(upper);
    cursor_position_update(0, yyleng);
}

{TYPES} {
    printf("<TYPE, `%s`>\n", yytext);
    cursor_position_update(0, yyleng);
}

{ID} {
    printf("<ID, `%s`>\n", yytext);
    cursor_position_update(0, yyleng);
}

{INTEGER_NUMBER} {
    long int longval;
    sscanf(yytext, "%ld", &longval);
    printf("<INTNUM, `%ld`>\n", longval);
    cursor_position_update(0, yyleng);
}

{REAL_NUMBER} {
    double doubleval;
    sscanf(yytext, "%lf", &doubleval);
    printf("<REALNUM, `%lf`>\n", doubleval);
    cursor_position_update(0, yyleng);
}

{UNARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        // só será possivel decidir a ação na analise semantica
        // se !int = NOTOP senao !list = LISTTAILOP
        case '!': printf("<EXCLAMATIONOP, `%s`>\n", token); break;
        case '?': printf("<LISTHEADEROP, `%s`>\n", token); break;
        case '%': printf("<LISTTAILPOPOP, `%s`>\n", token); break;
    }
    cursor_position_update(0, yyleng);
}

{BINARY_OP} {
    char *token = yytext;
    switch (token[0]) {
        case ':': printf("<LISTCTROP>\n"); break;
        case '*':
        case '/':
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
        case '&':
        case '|': printf("<BOOLOP, `%s`>\n", token); break;
    }
    cursor_position_update(0, yyleng);
}

{OP_ASSSIGN} {
    printf("<EQ>\n");
    cursor_position_update(0, yyleng);
}

["] {
    BEGIN(SCANNING_STR_LITERAL);
    cursor_position_update(0, yyleng);
    dquote_open_pos = cursor;
    yymore();
}

<SCANNING_STR_LITERAL>{
    ([^\n"\\]|\\.)* {
        cursor_position_update(0, yyleng);
        yymore();
    }
    ["] {
        cursor_position_update(0, yyleng);
        char *str_dup = strdup(yytext);
        string_literal_rm_dquote(str_dup);
        // char *unescaped = str_unescape(str_dup);
        printf("<STRINGLITERAL, `%s`>\n", str_dup);
        free(str_dup);
        // free(unescaped);
        BEGIN(INITIAL);
    }
    \n {
        show_str_literal_err();
        cursor_position_update(1, 0);
    }
    <<EOF>> {
        show_str_literal_err();
    }
}

"/*" {
    BEGIN(SCANNING_MULTILINE_COMMENT);
    cursor_position_update(0, yyleng);
    comment_open_pos = cursor;
    yymore();
}

<SCANNING_MULTILINE_COMMENT>{
    ([^*\n]|"*"[^/\n])* { /* noop */ }
    "\n" {
        cursor_position_update(1, 0);
    }
    "*/" {
        BEGIN(INITIAL);
        cursor_position_update(0, yyleng);
    }
   <<EOF>> {
        ++errors_count;
        CIPL_PWARN_CURSOR("unterminated comment\n", comment_open_pos);
        BEGIN(INITIAL);
    } 
}

. {
    CIPL_PERROR("unexpected character: %s\n", yytext);
    cursor_position_update(0, yyleng);
}

%%

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
}

void str_2_upper(char *s, char *d) {
    char *psrc = s;
    while (*psrc != '\0') *d++ = toupper(*psrc++);
}

void show_str_literal_err() {
    ++errors_count;
    CIPL_PWARN_CURSOR("missing terminating '\"' character\n", dquote_open_pos);
    BEGIN(INITIAL);
}
