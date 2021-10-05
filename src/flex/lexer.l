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
  ListNode *lines;
  char curr_line_buffer[1024] = "";
  LineInfo *curr_line_info;
  Cursor dquote_open_pos, comment_open_pos;
  Cursor cursor = {.line=1, .col=1};

  void show_str_literal_err();
  void string_literal_rm_dquote(char *s);

  #define cat_yytext {                    \
    strcat(curr_line_info->text, yytext); \
    strcat(curr_line_buffer, yytext);     \
    cursor.col += yyleng;                 \
  }

  #define skip_comments {                                   \
    case '/':                                               \
      if (yytext[1] != '/' && yytext[1] != '*') cat_yytext; \
      break;                                                \
    case '*':                                               \
      if (yytext[1] != '/') cat_yytext;                     \
      break;                                                \
  }

  #define YY_USER_ACTION                                           \
    yylloc.first_line = yylloc.last_line = yylineno;               \
    yylloc.first_column = cursor.col;                              \
    if (yytext[0] == '\n') {                                       \
      list_push(&lines, line_init(cursor.line, curr_line_buffer)); \
      cursor.col = 1;                                              \
      ++cursor.line;                                               \
      ++curr_line_info->line;                                      \
      memset(curr_line_buffer, 0, 1024);                           \
      memset(curr_line_info->text, 0, 1024);                       \
    }                                                              \
    else {                                                         \
      switch (yytext[0]) {                                         \
        case '"':                                                  \
          if (yyleng > 1 && yytext[yyleng - 1] == '"') cat_yytext; \
          break;                                                   \
        default:                                                   \
          cat_yytext;                                              \
      }                                                            \
    }                                                              \
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

{WS} {}

<INITIAL><<EOF>> {
  list_push(&lines, line_init(cursor.line, curr_line_buffer));
  return YYEOF;
}

<INITIAL>[\(\){};,] {  
  return yytext[0];
}

{RESERVED_KEYWORDS} {  
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
  switch(yytext[0]) {
    case 'i': return INT;
    case 'f': return FLOAT;
    case 'l': return LIST;
  }
}

{BUILTIN_FUNCTIONS} {
  yylval.pchar = strdup(yytext);
  return yytext[0] == 'r' ? READ : WRITE;
}

{ID} {
  yylval.sym = symbol_found(yytext, cursor);  
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
  return yytext[0];
}

["] {
  BEGIN(SCANNING_STR_LITERAL);  
  dquote_open_pos = cursor;
  yymore();
}

<SCANNING_STR_LITERAL>{
  ([^\n"\\]|\\.)* {    
    yymore();
  }
  ["] {    
    yylval.pchar = strdup(yytext);
    string_literal_rm_dquote(yylval.pchar);
    BEGIN(INITIAL);
    return STR_LITERAL;
  }
  \n {
    show_str_literal_err();
  }
  <<EOF>> {
    show_str_literal_err();
  }
}

"/*" {
  BEGIN(SCANNING_MULTILINE_COMMENT);  
  comment_open_pos = cursor;
}

<SCANNING_MULTILINE_COMMENT>{
  ([^*\n]|"*"[^/\n])* { /* noop */ }
  "\n" { /* noop */ }
  "*/" {
    BEGIN(INITIAL);
  }
  <<EOF>> {
    ++errors_count;
    CIPL_PERROR_CURSOR("unterminated comment\n", curr_line_buffer, comment_open_pos);
    BEGIN(INITIAL);
  } 
}

. {
  Cursor c = (Cursor){.line=cursor.line, .col=cursor.col - 1};
  CIPL_PERROR_CURSOR("unexpected character: " WHT "'%s'" RESET "\n",
                     curr_line_buffer, c, yytext);  
  ++errors_count;
  return YYerror;
}

%%

void show_str_literal_err() {
  ++errors_count;
  CIPL_PERROR_CURSOR("missing terminating " WHT "'\"'" RESET " character\n",
                     curr_line_buffer, dquote_open_pos);
  BEGIN(INITIAL);
}

void str_rm_char_at(char *str, unsigned int index) {
  memmove(&str[index], &str[index + 1], strlen(str) - index);
}

void string_literal_rm_dquote(char *s) {
  unsigned int len = strlen(s);
  str_rm_char_at(s, 0); --len;
  str_rm_char_at(s, len - 1); --len;
}