#ifndef __WISHLISTCONSOLE_H__
#define __WISHLISTCONSOLE_H__

#include <stdio.h>
#include "ADT/boolean.h"
#include "ADT/listlinier.h"
#include "ADT/map.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/stack.h"
#include "ADT/linkedlist.h"
#include "ADT/string.h"

void wishlistAdd(LinkedList *L);

void wishlistSwap(LinkedList *L, int i, int j);

void wishlistRemoveNumber(LinkedList *L, int index);

void wishlistRemove(LinkedList *L);

void wishlistClear(LinkedList *L);

void wishlistShow(LinkedList L);

#endif