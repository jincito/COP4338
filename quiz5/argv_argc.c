#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  printf("%d", argc);
  while (*++argv)
    if (isupper(*argv[0]))
      printf("!%c", toupper(argv[0][1]));
    else
      printf("!%zu", strlen(*argv));
  return 0;
}
