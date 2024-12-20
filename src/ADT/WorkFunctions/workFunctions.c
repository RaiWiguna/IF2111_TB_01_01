#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "workFunctions.h"

// Kebutuhan Work
Job jobList[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};

int jobCount = 5;
Job selectedJob;

// Fungsi
void sleep(int second) {
    time_t start_time = time(NULL); // Waktu mulai
    time_t end_time = start_time + second; // Waktu akhir

    while (time(NULL) < end_time) {
        // Loop sampai waktu sekarang melebihi waktu akhir
    }
}