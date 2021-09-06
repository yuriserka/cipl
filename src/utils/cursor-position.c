#include "utils/cursor-position.h"

#include <stdlib.h>
#include <string.h>

#include "core/globals.h"

void cursor_position_update(int qtd_line, int qtd_col) {
  if (qtd_line) {
    cursor.line += qtd_line;
    cursor.col = 1;
  }
  cursor.col += qtd_col;
}

LineInfo *line_init(int l, char *txt) {
  LineInfo *ll = calloc(1, sizeof(LineInfo));
  ll->line = l;
  strcpy(ll->text, txt);
  return ll;
}

void line_free(LineInfo *l) {
  free(l);
}