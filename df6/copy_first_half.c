#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* copy_second_half(const char* str) {
    int len = strlen(str);
    int half_len = len / 2;
    char* half = (char*)malloc((len - half_len) + 1); // +1 for null terminator
    if (half == NULL) {
        return NULL; // memory allocation failure
    }
    strcpy(half, str + half_len); // Copy from the midpoint to the end
    return half;
}

int main() {
    char greetings[] = "HellO World!";
    char* new_greetings = copy_second_half(greetings);
    printf(new_greetings);
    return 0;

}
