#include <stdio.h>
#include <string.h>
int main() {
  char haystack[] = "This is a sentence.\n";
  char needle[] = "is";
  printf("%s", strstr(haystack, needle));
  return 0;
}
