#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "railcipher.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        print_error("Usage: ./railcipher <key_length> <key...>");
        return EXIT_FAILURE;
    }

    int key_length = atoi(argv[1]); // Convert the first argument to an integer
    if (key_length <= 0 || key_length > 26) {
        print_error("Key length must be between 1 and 26");
        return EXIT_FAILURE;
    }

    int* key = malloc(key_length * sizeof(int)); // Allocate memory for the key
    if (key == NULL) {
        print_error("Memory allocation failed");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < key_length; i++) {
        key[i] = atoi(argv[i + 2]);
    }

    validate_key(key, key_length);

    char command[10];
    char input[1024];
    while (1) {
        printf("Enter command (encrpyt/decrpyt/quit): ");
        scanf("%s", command);
        getchar(); // Clears the input buffer

        if (strcmp(command, "quit") == 0) {
            break;
        }

        printf("Enter text: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character
    }
}