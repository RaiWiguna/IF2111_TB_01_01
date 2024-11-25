#ifndef Kustom
#define Kustom

#include <stdio.h>

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;

typedef struct {
  char name[MAX_LEN];
  int price;
} Item;


#endif