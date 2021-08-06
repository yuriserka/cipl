#pragma once

#include "utils/color-codes.h"

extern char *filename;

#define cipl_printf_color(__cipl_out_color_code, __cipl_out_fmt, ...) \
  printf(__cipl_out_color_code __cipl_out_fmt RESET, ##__VA_ARGS__);

#define cipl_printf(__cipl_out_fmt, ...) printf(__cipl_out_fmt, ##__VA_ARGS__);

#define cipl_perror(__merrfmt, ...)                               \
  {                                                               \
    cipl_printf("%s:%d:%d: ", filename, cursor.line, cursor.col); \
    cipl_printf_color(RED, "error: ");                            \
    cipl_printf(__merrfmt, ##__VA_ARGS__);                        \
  }
