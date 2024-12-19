#include <stdio.h>
#include "profile.h"

char loginAccount[100]; 
int money = 0;           

void showProfile() {
    printf("\n--- Profile ---\n");
    printf("Nama: %s\n", loginAccount);
    printf("Saldo: %d\n", money);
}
