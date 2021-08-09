#include "utils/string/unescape.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"
#include "utils/string/2-num.h"

extern int errors_count;

char *str_unescape(char *s) {
  char *str = calloc(strlen(s) + 20, sizeof(char));
  while (*s != '\0') {
    char *sstr = str;
    if (*s == '\\') {
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
          int hexval = str_hex2int(&s);
          if (hexval == HEX_ESCAPE_OOR) {
            ++errors_count;
            cipl_perror("hex escape sequence out of range\n");
            goto end_str;
          } else {
            sprintf(str, "%s%c", sstr, hexval);
            if (!hexval) goto end_str;
          }
        } break;
        default: {
          if (isdigit(*s)) {
            int octval = str_oct2int(&s);
            if (octval == OCT_ESCAPE_OOR) {
              ++errors_count;
              cipl_perror("octal escape sequence out of range\n");
              goto end_str;
            } else {
              sprintf(str, "%s%c", sstr, octval);
              if (!octval) goto end_str;
            }
          } else {
            cipl_perror("invalid escape sequence\n");
            goto end_str;
          }
        }
      }
    } else {
      sprintf(str, "%s%c", sstr, *s++);
    }
  }

end_str:
  str = realloc(str, sizeof(char) * (strlen(str) + 1));
  return str;
}
