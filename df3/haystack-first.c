#include <stdio.h>

int find_first_occurrence(char needle, const char *haystack) {
  int i;

  for (i = 0; haystack[i] != '\0'; i++)
    if (haystack[i] == needle)
      return i;
  return -1;
}

int main() {
  const char *haystack = "This is a sample haystack.";
  char needle = 's';
  int index = find_first_occurrence(needle, haystack);

  if (index != -1)
    printf("The first occurrence of '%c' is at index '%d'.\n", needle, index);
  else
    printf("The character '%c' was not found.\n", needle);

  return 0;
}
