#pragma once

#include <inttypes.h>

typedef enum {
  HEX_ESCAPE_OOR = -2,
  OCT_ESCAPE_OOR,
} Str2NumErrors;

int str_hex2int(char **hex);

int str_oct2int(char **oct);
