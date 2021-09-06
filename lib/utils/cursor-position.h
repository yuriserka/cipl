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

LineInfo *line_init(int line, char *txt);
void line_free(LineInfo *l);
