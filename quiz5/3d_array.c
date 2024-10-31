#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[2][3][4] = {
    {{'H', 'o', 'w', ' '}, {'a', 'r', 'e', ' '}, {'y', 'o', 'u', ' '}},
    {{'n', 'o', 'w', ' '}, {'a', 'n', 'd', ' '}, {'e', 't', 'c', '\0'}}};

int main() {
  printf("%s!%s!%s!%c", arr, arr[1], arr[1][1], arr[1][1][1]);
  return 0;
}
