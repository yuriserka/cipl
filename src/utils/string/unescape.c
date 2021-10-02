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
    size_t len = strlen(str);
    if (*s == '\\') {
      switch (*++s) {
        case 'a':
          str[len++] = '\a';
          ++s;
          break;
        case 'b':
          str[len++] = '\b';
          ++s;
          break;
        case 'f':
          str[len++] = '\f';
          ++s;
          break;
        case 'n':
          str[len++] = '\n';
          ++s;
          break;
        case 'r':
          str[len++] = '\r';
          ++s;
          break;
        case 't':
          str[len++] = '\t';
          ++s;
          break;
        case 'v':
          str[len++] = '\v';
          ++s;
          break;
        case '\\':
          str[len++] = '\\';
          ++s;
          break;
        case '\'':
          str[len++] = '\'';
          ++s;
          break;
        case '\"':
          str[len++] = '\"';
          ++s;
          break;
        case 'x':
        case 'X': {
          ++s;
          int hexval = str_hex2int(&s);
          if (hexval == HEX_ESCAPE_OOR) {
            CIPL_PERROR("hex escape sequence out of range\n");
            goto end_str;
          } else {
            str[len++] = hexval;
            if (!hexval) goto end_str;
          }
        } break;
        default: {
          if (isdigit(*s)) {
            int octval = str_oct2int(&s);
            if (octval == OCT_ESCAPE_OOR) {
              CIPL_PERROR("octal escape sequence out of range\n");
              goto end_str;
            } else {
              str[len++] = octval;
              if (!octval) goto end_str;
            }
          } else {
            CIPL_PERROR("invalid escape sequence\n");
            goto end_str;
          }
        }
      }
    } else {
      str[len++] = *s++;
    }
  }

end_str:
  return str;
}
