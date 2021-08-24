#pragma once

typedef struct {
  int col;
  int line;
} cursor_position;

void cursor_position_update(int qtd_line, int qtd_col);
