#include "pattern_finder.h"
bool is_tripartite(char line[]) {
  int len = strlen(line);
  if (len % 3 != 0)
    return false;

  int part_len = len / 3;
  for (int i = 0; i < part_len; i++)
    if (line[i] != line[part_len + i] || line[i] != line[2 * part_len + i])
      return false;
  return true;
}
