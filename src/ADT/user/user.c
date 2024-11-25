#include "user.h"

// Fungsi untuk menyalin string
void copyString(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

// Fungsi untuk membandingkan string
int compareString(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Fungsi untuk membuat pengguna baru
void createUser(User *u, char *name, char *password, int money) {
    copyString(u->name, name);
    copyString(u->password, password);
    u->money = money;
}

// Fungsi untuk membandingkan data pengguna
int compareUser(User u, char *username, char *password) {
    return (compareString(u.name, username) == 0 && compareString(u.password, password) == 0);
}