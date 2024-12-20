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
#include "ADT/WorkFunctions/workFunctions.h"

void Start(FILE **file,ArrayDin *Item); /*
    Memulai game dengan membaca default file /file mula mula.
*/
void Load(FILE **file, Word FileName);/*
    Melakukan Load File, menyimpan path dah membuka file.
*/

void Login(Word *LoginAccount,List L, int *Money);/*
    Melakukan Login, menyimpan username kedalam main untuk tahap melakukan load file dari akun.
*/

void Logout(Word *LoginAccount,ArrayDin *UserItem, ListLinier *WhistList);/*
    Melakukan Logut, membebaskan akun, array user item dan whistlist akun.
*/

void Register(Word *LoginAccount,List *L);/*
    Melakukan register akun, apabila akun sudah ada makan gagal melakukan register.
*/

void Work(User *LoginAccount);/*
    Melakukan kerja, untuk mendapatkan uang.
*/

void storeList(ArrayDin Item);/*
    Menampilkan isi dari Store
*/

void storeRequest(Queue *Req, ArrayDin Item);/*
    Membuat request untuk memasukkan barang kedalam store, memasukkan harga dan nama barang.    
*/

void storeSupply(Queue *Req, ArrayDin *Item);/*
    Menambahkan item request kedalam toko.
*/

void storeRemove(ArrayDin *Item);/*
    Menghapus Item dari toko.
*/

void wishlistAdd(ListLinier *L,ArrayDin Item);/*
    Menambahkan Item kedalam whislist, memastikan sudah ada item pada file baru menambahkan kedalam wishlist.
*/

void wishlistSwap(ListLinier *L, int i, int j);

void wishlistRemoveNumber(ListLinier *L, int index);

void wishlistRemove(ListLinier *L);

void wishlistClear(ListLinier *L);

void wishlistShow(ListLinier L);

// Console Tambahan
void HandleWrongInput();/*
    Console ini diperlukan, karena pada beberapa command yang diperiksa menggunakan IsSamePartial yang
    membuat adanya penundaan apakah input telah benar atau belum. Hal ini berkaitan dengan sistem kerja 
    IsSamePartial yang memeriksa hanya setengah "sesuai marker yang diberikan" terhadap input, lalu mengolahnya kembali ke format lain.
    Apabila ternyata input akhir tidak sesuai, barulah kita memanggil HandleWrongInput yang membuat seakan-akan program memang berjalan menuju bagian else.
*/
#endif