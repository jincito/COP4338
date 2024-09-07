#include <stdio.h>

#define MAX_LENGTH 1000
/*
 * This program receives a sequence of lines from input
 * and prints out the longest one at the end!*/
void main(void)
{
  /* Specify the capacity of array*/
  char line[MAX_LENGTH];
  char longest_line[MAX_LENGTH];
  int max_len = 0;
  // Use fgets to get a line of input
  // Use fgetc to get a single character
  while (fgets(line, MAX_LENGTH, stdin) != NULL){
    int len; // length of the curr line
    for (int i = 0; i < MAX_LENGTH; i++){
      if (line[i] == '\0'){
        len = i;
        break;
      }
    }
    if (line[len - 1] == '\n'){
      line[len - 1] = '\0';
      len--;
    }
      if (len > max_len){
        max_len = len;
        //longest_line = line;
        for (int i = 0; i <= len; i++){
          longest_line[i] = line[i];
        }
        //strcpy(longest_line, line);
      }
    }
  printf("Longest line is %s. Max Length is %d\n", longest_line, max_len);
}
