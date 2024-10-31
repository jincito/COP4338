#include <stdio.h>
#include <string.h>
int break_in_half(char arr[], int size) {
  arr[size / 2] = '\0'; // halves the string
  size = size / 2;
  return size;
}
int main() {
  char input[] = "Hello world";
  int size = strlen(input);
  break_in_half(input, size);
  printf("%dX%s", size, input);
  return 0;
}
