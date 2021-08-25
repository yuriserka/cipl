#pragma once

#include <stdio.h>

#include "core/globals.h"
#include "utils/color-codes.h"
#include "utils/cursor-position.h"

#define CIPL_PRINTF_COLOR(__cipl_out_color_code, __cipl_out_fmt, ...) \
  printf(__cipl_out_color_code __cipl_out_fmt RESET, ##__VA_ARGS__);

#define CIPL_PRINTF(__cipl_out_fmt, ...) printf(__cipl_out_fmt, ##__VA_ARGS__);

#define CIPL_PERROR(__cipl_err_out_fmt, ...) \
  { CIPL_PERROR_CURSOR(__cipl_err_out_fmt, cursor, ##__VA_ARGS__); }

#define CIPL_PERROR_CURSOR(__cipl_err_out_fmt, __cursor, ...)     \
  {                                                               \
    cursor_position b4 = cursor;                                  \
    cursor = __cursor;                                            \
    CIPL_PRINTF("%s:%d:%d: ", filename, cursor.line, cursor.col); \
    CIPL_PRINTF_COLOR(BRED, "error: ");                           \
    CIPL_PRINTF(__cipl_err_out_fmt, ##__VA_ARGS__);               \
    cursor = b4;                                                  \
    ++errors_count;                                               \
  }

#define CIPL_PWARN(__cipl_wrn_out_fmt, ...) \
  { CIPL_PWARN_CURSOR(__cipl_err_out_fmt, cursor, ##__VA_ARGS__); }

#define CIPL_PWARN_CURSOR(__cipl_wrn_out_fmt, __cursor, ...)      \
  {                                                               \
    cursor_position b4 = cursor;                                  \
    cursor = __cursor;                                            \
    CIPL_PRINTF("%s:%d:%d: ", filename, cursor.line, cursor.col); \
    CIPL_PRINTF_COLOR(BMAG, "warning: ");                         \
    CIPL_PRINTF(__cipl_wrn_out_fmt, ##__VA_ARGS__);               \
    cursor = b4;                                                  \
  }
