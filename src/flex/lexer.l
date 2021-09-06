%option nounput noinput noyywrap yylineno
%option outfile="src/flex/lexer.c" header-file="lib/flex/scanner.h"

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "bison/grammar.h"
  #include "utils/cursor-position.h"
  #include "utils/io.h"

  int errors_count = 0;
  char *filename;
  char curr_line[1024] = "";
  cursor_position dquote_open_pos, comment_open_pos;
  cursor_position cursor = {.line=1, .col=1};

  void show_str_literal_err();
  void append_curr_line(char *t) {
    strcat(curr_line, t);
  }

  #define YY_USER_ACTION                                       \
    yylloc.first_line = yylloc.last_line = yylineno;           \
    yylloc.first_column = cursor.col;                          \
    if (yytext[0] == '\n') { ++cursor.line; cursor.col =  1; } \
    else { cursor.col += yyleng; }                             \
    yylloc.last_column = cursor.col - 1;

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

RESERVED_KEYWORDS if|else|return|for|NIL
BUILTIN_FUNCTIONS read|write|writeln

%x SCANNING_STR_LITERAL
%x SCANNING_MULTILINE_COMMENT

%%

{SINGLELINE_COMMENT} { /* noop */ }

{WS} {
  switch (yytext[0]) {
      case ' ':
      case '\t':        
        append_curr_line(yytext);
        break;
      default:
        memset(curr_line, 0, 1024);
        break;
  }
}

<INITIAL>[\(\){};,] {  
  append_curr_line(yytext);
  return yytext[0];
}

{RESERVED_KEYWORDS} {  
  append_curr_line(yytext);
  switch (yytext[0]) {
    case 'i': return IF;
    case 'e': return ELSE;
    case 'f': return FOR;
    case 'r': return RETURN;
    case 'N': 
    yylval.integer = 0;
    return NIL;
  }
}

"int"|"float"|"list" {
  yylval.pchar = strdup(yytext);  
  append_curr_line(yytext);
  switch(yytext[0]) {
    case 'i': return INT;
    case 'f': return FLOAT;
    case 'l': return LIST;
  }
}

{BUILTIN_FUNCTIONS} {
  yylval.sym = symbol_found(yytext, cursor);  
  append_curr_line(yytext);
  return yytext[0] == 'r' ? READ : WRITE;
}

{ID} {
  yylval.sym = symbol_found(yytext, cursor);  
  append_curr_line(yytext);
  return NAME;
}

{INTEGER_NUMBER} {
  long int longval;
  sscanf(yytext, "%ld", &longval);
  yylval.integer = longval;  
  append_curr_line(yytext);
  return NUMBER_INT;
}

{REAL_NUMBER} {
  double doubleval;
  sscanf(yytext, "%lf", &doubleval);
  yylval.real = doubleval;  
  append_curr_line(yytext);
  return NUMBER_REAL;
}

{UNARY_OP} {  
  append_curr_line(yytext);
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
  append_curr_line(yytext);
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
  append_curr_line(yytext);
  return yytext[0];
}

["] {
  BEGIN(SCANNING_STR_LITERAL);  
  append_curr_line(yytext);
  dquote_open_pos = cursor;
  yymore();
}

<SCANNING_STR_LITERAL>{
  ([^\n"\\]|\\.)* {    
    append_curr_line(yytext);
    yymore();
  }
  ["] {    
    append_curr_line(yytext);
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
  }
  <<EOF>> {
    ++errors_count;
    CIPL_PERROR_CURSOR("unterminated comment\n", curr_line, comment_open_pos);
    BEGIN(INITIAL);
  } 
}

. {
  append_curr_line(yytext);
  CIPL_PERROR_CURSOR("unexpected character: %s\n", curr_line, cursor, yytext);  
  return YYerror;
}

%%

void show_str_literal_err() {
  ++errors_count;
  CIPL_PERROR_CURSOR("missing terminating '\"' character\n", curr_line, dquote_open_pos);
  BEGIN(INITIAL);
}
