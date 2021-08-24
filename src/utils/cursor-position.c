#include "utils/cursor-position.h"

#include "core/globals.h"

void cursor_position_update(int qtd_line, int qtd_col) {
  if (qtd_line) {
    cursor.line += qtd_line;
    cursor.col = 1;
  }
  cursor.col += qtd_col;
}
