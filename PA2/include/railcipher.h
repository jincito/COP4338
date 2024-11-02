#ifndef RAILCIPHER_H
#define RAILCIPHER_H

void encrypt(const char* plaintext, int* key, int key_length);
void decrypt(const char* ciphertext, int* key, int key_length);
void validate_key(int* key, int key_length);

#endif // RAILCIPHER_H