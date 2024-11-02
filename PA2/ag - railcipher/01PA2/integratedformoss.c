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
void decrypt(char* ciphertext);/*implement the decryption algorithm and print plaintext here*/#include "railcipher.h"

void decrypt(char* ciphertext){
	// printf("Decrypting %s.\n", ciphertext);
	int l = strlen(ciphertext);          // Length of ciphertext
    int n = (int)ceil(l / (double)m);    // Number of rows in the grid based on key length
    char rectangle[n][m];                // Grid for holding characters
    int counter = 0;

    // Step 1: Initialize the key inverse array
    int key_inverse[m + 1];
    for (int i = 0; i < m; i++) {
        key_inverse[key[i] - 1] = i; // Maps key values to column indices
    }

    // Step 2: Fill the rectangle column-wise using the transposition key
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            if (counter < l) {
                rectangle[row][key_inverse[col]] = ciphertext[counter++];
            } else {
                rectangle[row][key_inverse[col]] = 'z'; // Filler in case of extra columns
            }
        }
    }

    // Step 3: Read out plaintext in row-major order
    // Output the decrypted plaintext
    printf("Decrypted text is: ");
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (rectangle[row][col] != 'z') { // Ignore padding characters
                putchar(rectangle[row][col]);
            }
        }
    }
    putchar('\n');
}#include "railcipher.h"

void encrypt(char* plaintext){
	//printf("Encrypting %s.\n", plaintext);
	
	int read = 0, write = 0;
	while(plaintext[read] != '\0'){
		if(isalpha(plaintext[read]))
			plaintext[write++] = tolower(plaintext[read]);
		read++;
	}
	plaintext[write] = '\0';	
	int l = write;
	int n = (int)ceil(l/(double)m);//# of rows!
	char rectangle[n][m];//m is the key length (externally defined!)
	int counter = 0;
	for(int row = 0; row < n;row++)
		for(int col = 0; col < m;col++)
			if(counter < l)
				rectangle[row][col] = plaintext[counter++];
			else
				rectangle[row][col] = 'z' + col - m + 1;
	/*printf("The rectangular array is:\n");
	for(int row = 0; row < n;row++){
		for(int col = 0; col < m;col++)
			putchar(rectangle[row][col]);
		putchar('\n');
	}*/
	
	int key_inverse[m+1];
	//i ----> key[i]
	//key[i] ---inverse_key---> i
	for(int i = 0; i < m;i++)
		key_inverse[key[i]-1] = i;
	
	//printf("Ciphertext is equal to: ");
	for(int col = 0; col < m;col++)
		for(int row = 0; row < n;row++)
			putchar(rectangle[row][key_inverse[col]]);
	putchar('\n');
	
}#include "railcipher.h"
int key[MAX_LEN];
int m;//key length
static int is_legal_key(){
	char* seen = (char*) calloc(m+1, 1);
	for(int i = 0; i < m;i++){
		if(key[i] < 1 || key[i] > m)
			return FALSE;
		if(!seen[key[i]])
			seen[key[i]] = TRUE;
		else//duplicate
			return FALSE;
	}
	return TRUE;	
}
static int handle_args(int argc, char* argv[]){
	m = argc - 2;//length of key
	if( m < 2 || m > MAX_LEN){//invalid key length
		printf("Fatal error: too few or too many arguments!\n");
		return INVALID_KEY_LENGTH;//error code for invalid key
	}
	if(atoi(argv[1]) != m){//user did not enter the right CLA combination!
		printf("Fatal error: invalid key length!\n");
		return INVALID_KEY_LENGTH;//error code for invalid key
	}
	for(int i = 0; i < m;i++)
		key[i] = atoi(argv[2 + i]);
	if(!is_legal_key()){//user did not enter the right CLA combination!
		printf("Fatal error: invalid key sequence!\n");
		return INVALID_KEY_SEQ;//error code for invalid key sequence
	}
	return NO_ERROR;
}
int main(int argc, char* argv[]){
	//argv[1]: key length (m) 2-26
	//argv[2:m+1]: key vector: permutaion from 1 to m
	//argv[m+2]: NULL
	//argc: 2 + m where m is the length of key
	int error_code;
	if(error_code = handle_args(argc, argv))
		return error_code;
	//printf("Key is ");
	//for(int i = 0; i < m;i++)
	//	printf("%d ", key[i]);
	//printf("\n");
	//fflush(stdout);
	char command[MAX_COMMAND_LEN];
	while(fgets(command, MAX_COMMAND_LEN, stdin)){
		int len = strlen(command);
		if(command[len-1] == '\n'){
			command[len-1] = '\0';
			len--;
		}
		if(!strcasecmp(command, "quit"))
			break;
		if(!strncmp(command, "encrypt ", 8))
			encrypt(command + 8);
		else if(!strncmp(command, "decrypt ", 8))
			decrypt(command + 8);
		else
			printf("invalid command! try again!\n");
	}
	return NO_ERROR;
}
