#include "pattern_finder.h"
bool is_arithmetic(char line[]) {
  int len = strlen(line);
  if (len < 2)
    return false;

  for (int i = 1; i < len; i++)
    if (line[i] != line[i - 1] + 1)
      return false;
  return true;
}
bool is_reverse_arithmetic(char line[]) {
  int len = strlen(line);
  if (len < 2)
    return false;

  for (int i = 1; i < len; i++) {
    if (line[i] != line[i - 1] - 1)
      return false;
  }
  return true;
}
