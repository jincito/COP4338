#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX_LEN 26
#define MAX_COMMAND_LEN 5000
#define TRUE 1
#define FALSE 0
#define INVALID_KEY_LENGTH 1
#define INVALID_KEY_SEQ 2
#define NO_ERROR 0
extern int key[MAX_LEN];
extern int m;//key length
void encrypt(char* plaintext);/*implement the encryption algorithm and print ciphertext here*/
void decrypt(char* ciphertext);/*implement the decryption algorithm and print plaintext here*/