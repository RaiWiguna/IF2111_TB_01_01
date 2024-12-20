#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../mesinkata/mesinkata.h"
#include "../Kustom/Kustom.h"

#define MAX_LEN_WORK 100

// Kamus Lokal
typedef struct {
    char name[MAX_LEN_WORK];
    int income;
    int duration;
} Job;

extern Job jobList[];       // List pekerjaan
extern int jobCount;        // Jumlah pekerjaan
extern Job selectedJob; 

void sleep(int second);/*
    Fungsi yang mengukur waktu untuk memberikan jeda.
*/

#endif