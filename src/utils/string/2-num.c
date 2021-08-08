#include "utils/string/2-num.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "utils/cursor-position.h"

int str_hex2int(char **hex) {
  int val = 0, digits_count = 0;
  while (**hex && isxdigit(**hex)) {
    uint8_t byte = **hex;

    if (isdigit(byte)) {
      byte -= '0';
    } else {
      byte = byte - (islower(byte) ? 'a' : 'A') + 10;
    }
    val = (val << 4) | (byte & 0xF);
    ++*hex;
    ++digits_count;
    cursor_position_update(0, 1);
  }
  return digits_count > 2 ? HEX_ESCAPE_OOR : val;
}

int str_oct2int(char **oct) {
  int digits_count = 0;

  char *poct = *oct;
  while (*poct && *poct >= '0' && *poct <= '7') {
    ++digits_count;
    ++poct;
  }

  int val = 0;
  digits_count = digits_count >= 3 ? 3 : digits_count;

  while (**oct && **oct >= '0' && **oct <= '7' && digits_count) {
    uint8_t byte = **oct;

    byte -= '0';
    val += byte * pow(8, --digits_count);
    ++*oct;
    cursor_position_update(0, 1);
  }

  return val > 255 ? OCT_ESCAPE_OOR : val;
}
