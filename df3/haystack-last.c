#include <stdio.h>

int find_last_occurrence(char needle, const char *haystack) {
  int index = -1; // Initialize index to -1 (not found)
  int i;

  // Iterate through the haystack array to find the length
  for (i = 0; haystack[i] != '\0'; i++)
    ;

  // Traverse haystack from the end to the beginning
  for (i--; i >= 0; i--) {
    if (haystack[i] == needle) {
      index = i; // Update index if needle is found
      break;     // Exit the loop after finding the last occurrence
    }
  }

  return index; // Return the last occurrence index or -1
}

int main() {
  const char *haystack = "This is a sample haystack.";
  char needle = 's';
  int index = find_last_occurrence(needle, haystack);

  if (index != -1) {
    printf("The last occurrence of '%c' is at index %d.\n", needle, index);
  } else {
    printf("The character '%c' was not found.\n", needle);
  }

  return 0;
}
