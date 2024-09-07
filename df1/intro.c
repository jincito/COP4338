#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Integer types
    printf("Type: char\nMinimum: %d\nMaximum: %d\nSize: %lu bytes\n\n", CHAR_MIN, CHAR_MAX, sizeof(char));
    printf("Type: unsigned char\nMinimum: 0\nMaximum: %u\nSize: %lu bytes\n\n", UCHAR_MAX, sizeof(unsigned char));
    printf("Type: short\nMinimum: %d\nMaximum: %d\nSize: %lu bytes\n\n", SHRT_MIN, SHRT_MAX, sizeof(short));
    printf("Type: unsigned short\nMinimum: 0\nMaximum: %u\nSize: %lu bytes\n\n", USHRT_MAX, sizeof(unsigned short));
    printf("Type: int\nMinimum: %d\nMaximum: %d\nSize: %lu bytes\n\n", INT_MIN, INT_MAX, sizeof(int));
    printf("Type: unsigned int\nMinimum: 0\nMaximum: %u\nSize: %lu bytes\n\n", UINT_MAX, sizeof(unsigned int));
    printf("Type: long\nMinimum: %ld\nMaximum: %ld\nSize: %lu bytes\n\n", LONG_MIN, LONG_MAX, sizeof(long));
    printf("Type: unsigned long\nMinimum: 0\nMaximum: %lu\nSize: %lu bytes\n\n", ULONG_MAX, sizeof(unsigned long));
    printf("Type: long long\nMinimum: %lld\nMaximum: %lld\nSize: %lu bytes\n\n", LLONG_MIN, LLONG_MAX, sizeof(long long));
    printf("Type: unsigned long long\nMinimum: 0\nMaximum: %llu\nSize: %lu bytes\n\n", ULLONG_MAX, sizeof(unsigned long long));

    // Floating point types
    printf("Type: float\nMinimum: %e\nMaximum: %e\nSize: %lu bytes\n\n", FLT_MIN, FLT_MAX, sizeof(float));
    printf("Type: double\nMinimum: %e\nMaximum: %e\nSize: %lu bytes\n\n", DBL_MIN, DBL_MAX, sizeof(double));
    printf("Type: long double\nMinimum: %Le\nMaximum: %Le\nSize: %lu bytes\n\n", LDBL_MIN, LDBL_MAX, sizeof(long double));

    return 0;
}
