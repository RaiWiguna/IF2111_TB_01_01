#ifndef console_h
#define console_h

#include <stdio.h>

#include "boolean.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/ListStatis/liststatis.h"
#include "ADT/ArrayDinamis/ArrayDinamis.h"
#include "ADT/Queue/queue.h"
#include "ADT/ListLinier/listlinier.h"
#include "ADT/ScanFile/scanfile.h"

void Start(FILE **file,ArrayDin *Item); /*
    Memulai game dengan membaca default file /file mula mula.
*/
void Load(FILE **file);/*
    Melakukan Load File, menyimpan path dah membuka file.
*/

void Login(Word *LoginAccount,List L);/*
    Melakukan Login, menyimpan username kedalam main untuk tahap melakukan load file dari akun.
*/

void Logout(Word *LoginAccount,ArrayDin *UserItem, ListLinier *WhistList);/*
    Melakukan Logut, membebaskan akun, array user item dan whistlist akun.
*/

void Register(Word *LoginAccount,List *L);/*
    Melakukan register akun, apabila akun sudah ada makan gagal melakukan register.
*/
#endif