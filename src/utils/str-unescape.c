#include "utils/str-unescape.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/cursor-position.h"
#include "utils/io.h"
#include "utils/str2num.h"

extern cursor_position cursor;
extern int errors_count;

char *str_literal_unescape(char *s) {
  char *str = calloc(512, sizeof(char));
  while (*s != '\0') {
    char *sstr = str;
    if (*s == '\\') {
      ++cursor.col;
      switch (*++s) {
        case 'a':
          sprintf(str, "%s%c", sstr, '\a');
          ++s;
          break;
        case 'b':
          sprintf(str, "%s%c", sstr, '\b');
          ++s;
          break;
        case 'f':
          sprintf(str, "%s%c", sstr, '\f');
          ++s;
          break;
        case 'n':
          sprintf(str, "%s%c", sstr, '\n');
          ++s;
          break;
        case 'r':
          sprintf(str, "%s%c", sstr, '\r');
          ++s;
          break;
        case 't':
          sprintf(str, "%s%c", sstr, '\t');
          ++s;
          break;
        case 'v':
          sprintf(str, "%s%c", sstr, '\v');
          ++s;
          break;
        case '\\':
          sprintf(str, "%s%c", sstr, '\\');
          ++s;
          break;
        case '\'':
          sprintf(str, "%s%c", sstr, '\'');
          ++s;
          break;
        case '\"':
          sprintf(str, "%s%c", sstr, '\"');
          ++s;
          break;
        case 'x':
        case 'X': {
          ++s;
          ++cursor.col;
          int hexval = str_hex2int(&s);
          if (hexval == HEX_ESCAPE_OOR) {
            ++errors_count;
            cipl_perror("hex escape sequence out of range\n");
            goto end_str;
          } else {
            sprintf(str, "%s%c", sstr, hexval);
            ++cursor.col;
            if (!hexval) goto end_str;
          }
        } break;
        default: {
          if (*s >= '0' && *s <= '9') {
            ++cursor.col;
            int octval = str_oct2int(&s);
            if (octval == OCT_ESCAPE_OOR) {
              ++errors_count;
              cipl_perror("octal escape sequence out of range\n");
              goto end_str;
            } else {
              sprintf(str, "%s%c", sstr, octval);
              ++cursor.col;
              if (!octval) goto end_str;
            }
          } else {
            cipl_printf_color(RED, "error:");
            printf("invalid escape sequence\n");
            goto end_str;
          }
        }
      }
    } else {
      sprintf(str, "%s%c", sstr, *s++);
    }
    if (*s == '\n') ++cursor.line;
    ++cursor.col;
  }

end_str:
  str = realloc(str, sizeof(char) * (strlen(str) + 1));
  return str;
}
