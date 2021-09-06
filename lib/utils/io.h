#pragma once

#include <stdio.h>

#include "core/globals.h"
#include "utils/color-codes.h"
#include "utils/cursor-position.h"

#define CIPL_PRINTF_COLOR(__CIPL_OUT_COLOR_CODE__, __CIPL_OUT_FMT__, ...) \
  printf(__CIPL_OUT_COLOR_CODE__ __CIPL_OUT_FMT__ RESET, ##__VA_ARGS__);

#define CIPL_PRINTF(__CIPL_OUT_FMT__, ...) \
  printf(__CIPL_OUT_FMT__, ##__VA_ARGS__);

#define CIPL_PERROR(__CIPL_ERR_OUT_FMT__, ...) \
  { CIPL_PRINTF_COLOR(BRED, __CIPL_ERR_OUT_FMT__, ##__VA_ARGS__); }

#define CIPL_PERROR_CURSOR(__CIPL_ERR_OUT_FMT__, __LINE__, __CURSOR__, ...) \
  {                                                                         \
    Cursor __B4__ = cursor;                                                 \
    cursor = __CURSOR__;                                                    \
    CIPL_PRINTF("%s:%d:%d: ", filename, cursor.line, cursor.col);           \
    CIPL_PRINTF_COLOR(BRED, "error: ");                                     \
    CIPL_PRINTF(__CIPL_ERR_OUT_FMT__, ##__VA_ARGS__);                       \
    unsigned int __STRLEN__ = strlen(__LINE__);                             \
    if (__STRLEN__) {                                                       \
      printf("%5d |\t", cursor.line);                                       \
      for (int i = 0; i < __STRLEN__; ++i) {                                \
        if (i == (cursor.col - 1)) {                                        \
          CIPL_PRINTF_COLOR(BRED, "%c", __LINE__[i]);                       \
        } else {                                                            \
          printf("%c", __LINE__[i]);                                        \
        }                                                                   \
      }                                                                     \
      printf("\n%5s |\t", "");                                              \
      for (int i = 0; i < __STRLEN__; ++i) {                                \
        if (i == (cursor.col - 1)) {                                        \
          CIPL_PRINTF_COLOR(BRED, "^");                                     \
        } else {                                                            \
          printf(" ");                                                      \
        }                                                                   \
      }                                                                     \
      printf("\n");                                                         \
    }                                                                       \
    cursor = __B4__;                                                        \
  }

#define CIPL_PWARN(__CIPL_WRN_OUT_FMT__, ...) \
  { CIPL_PWARN_CURSOR(__CIPL_ERR_OUT_FMT__, cursor, ##__VA_ARGS__); }

#define CIPL_PWARN_CURSOR(__CIPL_WRN_OUT_FMT__, __CURSOR__, ...)  \
  {                                                               \
    Cursor __B4__ = cursor;                                       \
    cursor = __CURSOR__;                                          \
    CIPL_PRINTF("%s:%d:%d: ", filename, cursor.line, cursor.col); \
    CIPL_PRINTF_COLOR(BMAG, "warning: ");                         \
    CIPL_PRINTF(__CIPL_WRN_OUT_FMT__, ##__VA_ARGS__);             \
    cursor = __B4__;                                              \
  }
