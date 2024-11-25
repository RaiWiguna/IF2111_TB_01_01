#include <stdio.h>
#include <time.h>

// Implementasi fungsi sleep manual
void sleep(int s) {
    time_t start_time = time(NULL); // Waktu mulai
    while (time(NULL) - start_time < s) {
        // Looping hingga waktu yang ditentukan tercapai
    }
}

int main() {
    printf("Menunggu selama 5 detik...\n");
    sleep(5); // Menunggu selama 5 detik
    printf("Waktu selesai!\n");
    return 0;
}