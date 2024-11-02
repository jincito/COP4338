#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void to_lowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void convert_numbers_to_scientific(char* str) {
    char buffer[1024];
    int buf_idx = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            buf_idx += sprintf(buffer + buf_idx, "%.1e", atof(&str[i]));
            while (isdigit(str[i])) i++;
            i--;
        } else {
            buffer[buf_idx++] = str[i];
        }
    }
    buffer[buf_idx] = '\0';
    strcpy(str, buffer);
}

int main(int argc, char* argv[]) {
    int lower_flag = 0, scientific_flag = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            lower_flag = 1;
        } else if (strcmp(argv[i], "-e") == 0) {
            scientific_flag = 1;
        }
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (lower_flag) {
            to_lowercase(buffer);
        }
        if (scientific_flag) {
            convert_numbers_to_scientific(buffer);
        }
        printf("%s", buffer);
    }

    return 0;
}

