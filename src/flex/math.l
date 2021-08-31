%option nounput noinput noyywrap
%option outfile="src/flex/lexer.c" header-file="lib/flex/scanner.h"

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "bison/grammar.h"
  #include "utils/cursor-position.h"
  #include "utils/io.h"

  int errors_count = 0;
  char *filename;
  cursor_position dquote_open_pos, comment_open_pos;
  cursor_position cursor = {.line=1, .col=1};

  void show_str_literal_err();
%}

DELIM [[:blank:]\n\r]
LETTER [[:alpha:]_]
DIGIT [[:digit:]]
LETTER_OR_DIGIT [[:alnum:]_]

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

INTEGER_NUMBER 0|[1-9]{DIGIT}*
REAL_NUMBER ({DIGIT}*[.])?{DIGIT}+([eE][+-]?{DIGIT}+)?

SINGLELINE_COMMENT "//"[^\n]*

RESERVED_KEYWORDS if|else|return|for|NIL|let

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
  cursor_position_update(0, yyleng);
  return yytext[0];
}

{RESERVED_KEYWORDS} {
  cursor_position_update(0, yyleng);
  switch (yytext[0]) {
    case 'i': return IF;
    case 'e': return ELSE;
    case 'f': return FOR;
    case 'r': return RETURN;
    case 'l': return LET;
    case 'N': return NIL;
  }
}

"int" {
  yylval.pchar = strdup(yytext);
  return INT;
}

"float" {
  yylval.pchar = strdup(yytext);
  return FLOAT;
}

"list" {
  yylval.pchar = strdup(yytext);
  return LIST;
}

{ID} {
  yylval.sym = symbol_found(yytext, cursor);
  cursor_position_update(0, yyleng);
  return NAME;
}

{INTEGER_NUMBER} {
  long int longval;
  sscanf(yytext, "%ld", &longval);
  yylval.integer = longval;
  return NUMBER_INT;
}

{REAL_NUMBER} {
  double doubleval;
  sscanf(yytext, "%lf", &doubleval);
  yylval.real = doubleval;
  return NUMBER_REAL;
}

{UNARY_OP} {
  cursor_position_update(0, yyleng);
  yylval.pchar = strdup(yytext);
  switch(yytext[0]) {
    case '!': return EXCLAMATION;
    case '%': return PERCENT;
    case '-':
    case '+': return ADD;
    case '?': return QUESTION;
  }
}

{BINARY_OP} {
  char *token = yytext;
  cursor_position_update(0, yyleng);
  yylval.pchar = strdup(yytext);
  switch (token[0]) {
      case ':': return COLON;
      case '*':
      case '/': return MULT;
      case '+':
      case '-': return ADD;
      case '<':
      case '>': {
        const int is_dless = !strcmp(token, "<<");
        const int is_dgreat = !strcmp(token, ">>");

        const int is_cmp = !is_dless && !is_dgreat;

        if (is_cmp) return REL;
        return DL_DG;
      } break;
      case '=':
      case '!': return EQ;
      case '&': return AND;
      case '|': return OR;
  }
}

{OP_ASSSIGN} {
  cursor_position_update(0, yyleng);
  return yytext[0];
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
    yylval.pchar = strdup(yytext);
    BEGIN(INITIAL);
    return STR_LITERAL;
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
    CIPL_PERROR_CURSOR("unterminated comment\n", comment_open_pos);
    BEGIN(INITIAL);
  } 
}

. {
  CIPL_PERROR("unexpected character: %s\n", yytext);
  cursor_position_update(0, yyleng);
}

%%

void show_str_literal_err() {
  ++errors_count;
  CIPL_PWARN_CURSOR("missing terminating '\"' character\n", dquote_open_pos);
  BEGIN(INITIAL);
}
