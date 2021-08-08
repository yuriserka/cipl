#include "utils/string/find-occurrences.h"

#include <string.h>

int str_count_occ_char(char *s, char c) {
  char *ptr = strchr(s, c);
  int count = 0;
  while (ptr) {
    ++count;
    ptr = strchr(++ptr, c);
  }
  return count;
}

int str_count_occ_str(char *s, char *ss) {
  char *ptr = strstr(s, ss);
  int count = 0;
  while (ptr) {
    ++count;
    ptr = strstr(++ptr, ss);
  }
  return count;
}
