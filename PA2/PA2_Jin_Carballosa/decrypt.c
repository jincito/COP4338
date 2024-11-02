#include "railcipher.h"

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
}