#ifndef HISTORY_H
#define HISTORY_H

typedef struct {
    char item[100];
    int price;
} Purchase;

void showHistory(int n);
void initializeHistory();
void addPurchase(const char *item, int price);

#endif
