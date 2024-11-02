#include "railcipher.h"

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
	
}