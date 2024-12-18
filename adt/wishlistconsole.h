#ifndef __WISHLISTCONSOLE_H__
#define __WISHLISTCONSOLE_H__

#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"
#include "map.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "stack.h"
#include "linkedlist.h"
#include "string.h"

void wishlistAdd(LinkedList *L);

void wishlistSwap(LinkedList *L, int i, int j);

void wishlistRemoveNumber(LinkedList *L, int index);

void wishlistRemove(LinkedList *L);

void wishlistClear(LinkedList *L);

void wishlistShow(LinkedList L);

#endif