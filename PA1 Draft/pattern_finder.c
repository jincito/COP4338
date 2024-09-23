#include "pattern_finder.h"
int main() {
  char line[LINE_LEN];
  while (fgets(line, LINE_LEN, stdin)) {
    int len = strlen(line);
    if (line[len - 1] == '\n') {
      line[len - 1] = '\0';
      len--;
    }
    if (is_singleton(line))
      printf("singleton\n");
    if (is_arithmetic(line))
      printf("arithmetic\n");
    if (is_reverse_arithmetic(line))
      printf("reverse arithmetic\n");
    if (is_tripartite(line))
      printf("balanced tripartite\n");
    if (is_bipartite(line))
      printf("balanced bipartite\n");
    if (is_palindrome(line))
      printf("palindrome\n");

    putchar('\n'); // add a new line just to separate the list of patterns for
                   // multiple inputs
  }
  return 0;
}
