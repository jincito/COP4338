#include <stdio.h>
#include <string.h>
#define MAX 100
void my_strcat(char dst[], char src[]) {
  int i = 0;
  int len = strlen(dst);
  while ((dst[i + len] = src[i]) != '\0')
    i++;
}
void my_strncat(char dst[], char src[], int n) {
  int i = 0;
  int len = strlen(dst);
  while ((dst[i + len] = src[i]) != '\0' && i < n)
    i++;
  dst[i + len] = '\0';
}

// int arr[] = {5, 7, 9};
int main(void) {
  char name1[] = "Angelina";
  char name2[] = "Bob";
  char placeholder[MAX];
  strcpy(placeholder, name2);    // Bob
  my_strcat(placeholder, name1); // BobAngelina
  printf("%s + %s: %s.\n", name2, name1, placeholder);
  my_strncat(placeholder, "Hello world!!!!!!!", 10); // BobAngelinaHello Worl
  printf("%s\n", placeholder);
}
