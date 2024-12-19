#include <stdio.h>
#include "history.h"

#define MAX_HISTORY 100

Purchase history[MAX_HISTORY];
int cnt = 0; // purchase count

void initializeHistory() {
    cnt = 0;  
}

void showHistory(int n) {
    if (cnt == 0) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    int record = (n < cnt) ? n : cnt;

    printf("Riwayat pembelian barang:\n");

    // Display the most recent purchases first
    for (int i = cnt - 1; i >= cnt - record; i--) {
        printf("%d. %s %d\n", cnt - i, history[i].item, history[i].price);
    }
}

void addPurchase(const char *item, int price) {
    if (cnt < MAX_HISTORY) {
        
        int i = 0;
        while (item[i] != '\0' && i < 99) {
            history[cnt].item[i] = item[i];
            i++;
        }
        history[cnt].item[i] = '\0'; 
        history[cnt].price = price;
        cnt++;
    } else {
        printf("History is full!\n");
    }
}

int main() {
    initializeHistory();
    // contoh
    addPurchase("Laptop", 10000000);
    addPurchase("Smartphone", 5000000);
    addPurchase("Headphones", 200000);
    
    char command[20];
    int n;

    printf("Masukkan perintah (contoh: history 3): ");
    fgets(command, sizeof(command), stdin);  

    if (sscanf(command, "history %d", &n) == 1) {
        printf("\nMenampilkan %d riwayat pembelian terbaru:\n", n);
        showHistory(n);
    } else {
        printf("Perintah tidak valid! Gunakan format: history <n>\n");
    }

    return 0;
}
