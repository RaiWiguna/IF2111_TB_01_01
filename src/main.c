#include <stdio.h>
#include "user.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

#define MAX_USERS 100

User users[MAX_USERS];  
int userCount = 0;      
int currentUserIndex = -1; 


void Register() {
    char username[MAX_LEN], password[MAX_LEN];
    printf("Username: ");
    STARTKATA();  
    copyString(username, CKata.TabKata);

    // Cek apakah username sudah ada
    for (int i = 0; i < userCount; i++) {
        if (compareString(users[i].name, username) == 0) {
            printf("Username sudah digunakan. Silakan lakukan REGISTER ulang.\n");
            return;
        }
    }

    printf("Password: ");
    STARTKATA(); 
    copyString(password, CKata.TabKata);

    // Tambahkan pengguna baru
    createUser(&users[userCount], username, password, 0); 
    userCount++;
    printf("Akun berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n");
}

void Login() {
    if (currentUserIndex != -1) {
        printf("Anda masih tercatat sebagai %s, silakan LOGOUT terlebih dahulu!\n", users[currentUserIndex].name);
        return;
    }

    char username[MAX_LEN], password[MAX_LEN];
    printf("Username: ");
    STARTKATA();  
    copyString(username, CKata.TabKata);

    printf("Password: ");
    STARTKATA();  
    copyString(password, CKata.TabKata);

    for (int i = 0; i < userCount; i++) {
        if (compareUser(users[i], username, password)) {
            currentUserIndex = i;
            printf("Anda telah login ke PURRMART sebagai %s.\n", users[i].name);
            return;
        }
    }
    printf("Username atau password salah.\n");
}

void Logout() {
    if (currentUserIndex == -1) {
        printf("Tidak ada pengguna yang sedang login.\n");
        return;
    }

    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan. \n", users[currentUserIndex].name);
    currentUserIndex = -1;
}



int main() {
    char command[MAX_LEN];
    printf("Selamat datang di PURRMART!\n");

    while (1) {
        printf("Masukkan Command: ");
        STARTKATA();
        copyString(command, CKata.TabKata);

        if (compareString(command, "REGISTER") == 0) {
            Register();
        } else if (compareString(command, "LOGIN") == 0) {
            Login();
        } else if (compareString(command, "LOGOUT") == 0) {
            Logout();
        } else {
            printf("Command tidak dikenal. Ketik HELP untuk bantuan.\n");
        }
    }

    return 0;
}
