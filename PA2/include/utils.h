#ifndef UTILS_H
#define UTILS_H

void remove_non_alpha(char* str);
void convert_to_lower(char* str);
void fill_array(char array[][27], const char* str, int rows, int columns);
void print_error(const char* message);

#endif // UTILS_H