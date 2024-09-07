#include <stdio.h>
int main() {
  char input[100];
  fgets(input, 100, stdin);
  for (int i = 0; i < 100 && input[i] != '\n'; i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      putchar(input[i]);
    }
  }
  // putchar method accepts
  // a mandatory parameter ch which is the character to be written to stdout.
}
