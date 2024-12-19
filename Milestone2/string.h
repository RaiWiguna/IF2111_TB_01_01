#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

// Menghitung panjang string
int strlen_custom(const char *str);

// Membandingkan dua string
int strcmp_custom(const char *str1, const char *str2);

// Menyalin string
char *strcpy_custom(char *dest, const char *src);

// Mengalokasikan memori dan menduplikasi string
char *strdup_custom(const char *src);

#endif