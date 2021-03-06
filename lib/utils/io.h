#pragma once

#include <stdio.h>
#include <string.h>

#include "core/globals.h"
#include "utils/color-codes.h"
#include "utils/cursor-position.h"

#define CIPL_PRINTF_COLOR(__COLOR__, __FMT__, ...) \
  printf(__COLOR__ __FMT__ RESET, ##__VA_ARGS__);

#define CIPL_PRINTF(__FMT__, ...) printf(__FMT__, ##__VA_ARGS__);

#define CIPL_PERROR(__FMT__, ...) \
  { CIPL_PRINTF_COLOR(BRED, __FMT__, ##__VA_ARGS__); }

#define SHOULD_PRINT_ERROR_CONTEXT                                           \
  {                                                                          \
    if (p_ctx_name) {                                                        \
      if (strcmp(current_context->name, "top level")) {                      \
        CIPL_PRINTF(WHT "%s:" RESET " In function " BBLU "'%s'" RESET ":\n", \
                    filename, current_context->name);                        \
      } else {                                                               \
        CIPL_PRINTF(WHT "%s:" RESET " At top level:\n", filename);           \
      }                                                                      \
      p_ctx_name = false;                                                    \
    }                                                                        \
  }

#define CIPL_PERROR_CURSOR(__FMT__, __LINE__, __C__, ...)                  \
  {                                                                        \
    SHOULD_PRINT_ERROR_CONTEXT;                                            \
    CIPL_PRINTF_COLOR(WHT, "%s:%d:%d: ", filename, __C__.line, __C__.col); \
    CIPL_PRINTF_COLOR(BRED, "error: ");                                    \
    CIPL_PRINTF(__FMT__, ##__VA_ARGS__);                                   \
    unsigned int __STRLEN__ = strlen(__LINE__);                            \
    if (__STRLEN__) {                                                      \
      CIPL_PRINTF("%5d | %.*s" BRED "%.1s" RESET "%s\n", __C__.line,       \
                  __C__.col - 1, __LINE__, __LINE__ + __C__.col - 1,       \
                  __LINE__ + __C__.col);                                   \
      CIPL_PRINTF("%5s | %*s" BRED "%c" RESET "\n", "", __C__.col - 1, "", \
                  '^');                                                    \
    }                                                                      \
  }

#define CIPL_PERROR_CURSOR_RANGE(__FMT__, __LINE__, __B__, __E__, ...)     \
  {                                                                        \
    SHOULD_PRINT_ERROR_CONTEXT;                                            \
    CIPL_PRINTF_COLOR(WHT, "%s:%d:%d: ", filename, __B__.line, __B__.col); \
    CIPL_PRINTF_COLOR(BRED, "error: ");                                    \
    CIPL_PRINTF(__FMT__, ##__VA_ARGS__);                                   \
    unsigned int __STRLEN__ = strlen(__LINE__);                            \
    if (__STRLEN__) {                                                      \
      CIPL_PRINTF("%5d | %.*s" BRED "%.*s" RESET "%s\n", __B__.line,       \
                  __B__.col - 1, __LINE__, __E__.col - __B__.col + 1,      \
                  __LINE__ + __B__.col - 1, __LINE__ + __E__.col);         \
      CIPL_PRINTF("%5s | %*s" BRED "%c" RESET "\n", "", __B__.col - 1, "", \
                  '^');                                                    \
    }                                                                      \
  }
