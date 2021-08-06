#pragma once

#include "utils/color-codes.h"

#define cipl_printf_color(__cipl_out_color_code, __cipl_out_fmt, ...) \
  printf(__cipl_out_color_code __cipl_out_fmt RESET, ##__VA_ARGS__);

#define cipl_printf(__cipl_out_fmt, ...) \
  cipl_printf_color(WHT, __cipl_out_fmt, ##__VA_ARGS__);
