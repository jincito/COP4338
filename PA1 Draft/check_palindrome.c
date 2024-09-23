#include "pattern_finder.h"
bool is_palindrome(char line[]) {
  for (int left = 0, right = strlen(line) - 1; left < right; left++, right--)
    if (line[left] != line[right])
      return false; // return zero
  return true;      // return true
}
