#ifndef Kustom
#define Kustom

#include <stdio.h>
#include "../ListLinier/listlinier.h"

#define MAX_LEN 100

typedef struct {
  Word name;
  Word password;
  int money;
  ListLinier wishlist;
} User;

#endif