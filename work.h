#ifndef WORK_H
#define WORK_H

#include "user.h"

#define MAX_LEN_WORK 50

typedef struct {
    char name[MAX_LEN_WORK];
    int income;
    int duration;
} Job;

int jobCount;
Job jobList[5];
Job selectedJob;

void Work(User *u);

void sleep(int second);

#endif