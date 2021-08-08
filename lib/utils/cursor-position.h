#pragma once

typedef struct {
  int col;
  int line;
} cursor_position;

extern cursor_position cursor;

void cursor_position_update(int qtd_line, int qtd_col);
