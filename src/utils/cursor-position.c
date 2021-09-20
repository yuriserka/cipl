#include "utils/cursor-position.h"

#include <math.h>
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

Cursor cursor_init_yylloc_begin(YYLTYPE loc) {
  return (Cursor){.line = loc.first_line, .col = loc.first_column};
}

Cursor cursor_init_yylloc_end(YYLTYPE loc) {
  return (Cursor){.line = loc.last_line, .col = loc.last_column};
}

Cursor cursor_init_yyloc_between(struct YYLTYPE lhs, struct YYLTYPE rhs) {
  return (Cursor){.col = rhs.first_column -
                         ceil((rhs.first_column - lhs.last_column) / 2.0),
                  .line = lhs.last_line};
}

LineInfo *line_init(int l, char *txt) {
  LineInfo *ll = calloc(1, sizeof(LineInfo));
  ll->line = l;
  strcpy(ll->text, txt);
  return ll;
}

void line_free(LineInfo *l) { free(l); }