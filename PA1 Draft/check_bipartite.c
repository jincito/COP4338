#include "pattern_finder.h"
bool is_bipartite(char line[]) {
  int len = strlen(line);
  if (len % 2 != 0)
    return false;

  int part_len = len / 2;
  for (int i = 0; i < part_len; i++)
    if (line[i] != line[part_len + i])
      return false;
  return true;
}
