#include <stdio.h>
#include <string.h>
// int strcmp(const char* s1, const char* s2)
int my_strcmp(char s1[], char s2[]) {
  int i = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] != s2[i])
      return s1[i] - s2[i];
    i++;
  }
  return s1[i] - s2[i];
}
int main(void) {
  char name1[] = "Alice";
  char name2[] = "AliceZ";
  /*
  if(name1 == name2)//name1.compareTo(name2) == 0
          printf("Alice is equal to Bob.\n");
  else if(name1 > name2)//name1.compareTo(name2) > 0
          printf("Alice is greater than Bob.\n");
  else if(name1 < name2)//name1.compareTo(name2) < 0
          printf("Alice is less than Bob.\n");
  */
  int result = strcmp(name1, name2); // my_strcmp(name1, name2);
  result = strncmp(name1, name2, 4);
  if (result == 0) // name1.compareTo(name2) == 0
    printf("%s is equal to %s.\n", name1, name2);
  else if (result > 0) // name1.compareTo(name2) > 0
    printf("%s is greater than %s.\n", name1, name2);
  else if (result < 0) // name1.compareTo(name2) < 0
    printf("%s is less than %s.\n", name1, name2);
}
