#include <stdio.h>
#define MAX 100
void my_strcpy(char dst[], char src[]) {
  int i = 0;
  while ((dst[i] = src[i]) != '\0')
    i++;
}
void my_strncpy(char dst[], char src[], int n) {
  int i = 0;
  while ((dst[i] = src[i]) != '\0' && i < n)
    i++;
  dst[i] = '\0';
}
int main(void) {
  char name1[] = "Angelina";
  char name2[] = "Bob";
  char placeholder[MAX];

  my_strcpy(placeholder, name1);
  printf("After copying %s: %s.\n", name1, placeholder);
  my_strcpy(placeholder, name2);
  printf("After copying %s: %s.\n", name2, placeholder);
  for (int i = 0; i < MAX; i++)
    printf("placeholder[%d] = %c.\n", i, placeholder[i]);

  my_strncpy(placeholder, "Hello World!!!!!", 10);
  printf("After copying %s: %s.\n", "Hello World!!!!!", placeholder);
}
