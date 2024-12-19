#include "string.h"

int strlen_custom(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int strcmp_custom(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (unsigned char)(*str1) - (unsigned char)(*str2);
}

char *strcpy_custom(char *dest, const char *src) {
    char *dest_start = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
}

char *strdup_custom(const char *src) {
    int length = strlen_custom(src) + 1;
    char *copy = (char *)malloc(length * sizeof(char));
    if (copy != NULL) {
        strcpy_custom(copy, src);
    }
    return copy;
}