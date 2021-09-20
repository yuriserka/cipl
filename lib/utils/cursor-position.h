#pragma once

typedef struct {
  int col;
  int line;
} Cursor;

typedef struct {
  int line;
  char text[1024];
} LineInfo;

void cursor_position_update(int qtd_line, int qtd_col);

struct YYLTYPE;

Cursor cursor_init_yylloc_begin(struct YYLTYPE loc);
Cursor cursor_init_yylloc_end(struct YYLTYPE loc);
Cursor cursor_init_yyloc_between(struct YYLTYPE lhs, struct YYLTYPE rhs);

LineInfo *line_init(int line, char *txt);
void line_free(LineInfo *l);
