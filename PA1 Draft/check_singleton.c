#include "pattern_finder.h"
bool is_singleton(char line[]) {
  int len = strlen(line);
  if (len < 1)
    return false;

  for (int i = 0; i < len - 1; i++)
    if (line[i] != line[i + 1])
      return false;
  return true;
}
