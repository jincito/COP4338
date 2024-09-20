#include <stdio.h>
#include <string.h>
#define MAX 100

double calculate_avg(int arr[]) {
  double rv = 0;
  int len = sizeof(arr) / sizeof(int);
  for (int i = 0; i < len; i++)
    rv += arr[i];
  return rv / len;
}
int main(void) {
  char c;
  unsigned short number = 10;
  printf("size of char c is %d.\n", sizeof(c));
  printf("size of number is %d.\n", sizeof(number));

  char greetings[] = "Hello world!";
  printf("size of greetings is %d.\n", sizeof(greetings));
  printf("string length of greetings is %d.\n", strlen(greetings));

  int arr[] = {5, 7, 9, 11, 13};
  printf("size of arr is %d.\n", sizeof(arr));
}

/*
#include<stdio.h>
#include<string.h>
int main(){
   char arr[] = {'W', 'o', 'r', 'd', '\t', '\n', '\0', 'A', '0'};
   printf("%dX%d", strlen(arr), sizeof(arr)/sizeof(char));
   return 0;
}
*/
