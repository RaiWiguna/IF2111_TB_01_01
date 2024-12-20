#include <stdio.h>
#include <stdlib.h>

#include "ArrayDinamis.h"

// Konstruktor
void MakeArrayDin(ArrayDin *array) {
    (*array).elements = (Item *)malloc(InitialSize * sizeof(Item));
    (*array).Neff = 0;
    (*array).Capacity = InitialSize;
}

// Processing
int GetCapacity(ArrayDin array){
    return(array.Capacity);
}

int LengthArrDin(ArrayDin array){
    return(array.Neff);
}

void CetakNameArrayDin(ArrayDin array){
     for(int i=0; i<array.Neff;i++){
        printf("-) %s\n",array.elements[i].name);
    }
}


void CetakArrayDin(ArrayDin array){
    for(int i=0; i<array.Neff;i++){
        printf("- %s - Harga: %d\n",array.elements[i].name,array.elements[i].price);
    }
}

void UpdateCapacity(ArrayDin *array){
    if(LengthArrDin(*array) > 0.8*GetCapacity(*array)){
        (*array).Capacity *=2;
        (*array).elements = (Item *)realloc((*array).elements,(*array).Capacity * sizeof(Item));
    }
    else if((LengthArrDin (*array) < 0.25*GetCapacity(*array)) && GetCapacity(*array)>20){
        (*array).Capacity /=2;
        (*array).elements = (Item *)realloc((*array).elements,(*array).Capacity * sizeof(Item));
    }
}

void DeallocateArrDin(ArrayDin *array){
    free((*array).elements);
    (*array).elements = NULL;     
    (*array).Capacity = 0;      
    (*array).Neff = 0;    
}

void MoveRightArrDin(ArrayDin *array,Index from){
    for(int i = (*array).Neff; i>from;i--){
        (*array).elements[i] = (*array).elements[i-1];
    }
}

void MoveLeftArrDin(ArrayDin *array, Index from){
    for(int i = from; i<(*array).Neff;i++){
        (*array).elements[i] = (*array).elements[i+1];
    }
}

Item GetItem(ArrayDin array, Index i){
    return(array.elements[i]);
}

// Pengolahan Data
void InsertFirstNameArrDin(ArrayDin *array,string input){
    // Kamus Lokal
    Word tempWord;
    StrcpyToWord(&tempWord,input);

    // Algoritma
    if(IsEmpty(*array)){
        for(int j=0; j <tempWord.Length;j++){
            (*array).elements[0].name[j] = tempWord.TabWord[j];
        }
        (*array).elements[0].name[tempWord.Length] = '\0';
    }
    else{
        MoveRightArrDin(&*array,0);
        for(int j=0; j <tempWord.Length;j++){
            (*array).elements[0].name[j] = tempWord.TabWord[j];
        }
        (*array).elements[0].name[tempWord.Length] = '\0';
    }
    (*array).Neff ++;
    UpdateCapacity(&*array);
}

void InsertFirstArrDin(ArrayDin *array,string price,string name){
    // Kamus Lokal
    Word tempWord;
    StrcpyToWord(&tempWord,name);

    // Algoritma
    if(IsEmpty(*array)){
        for(int j=0; j <tempWord.Length;j++){
            (*array).elements[0].name[j] = tempWord.TabWord[j];
        }
        (*array).elements[0].name[tempWord.Length] = '\0';
        (*array).elements[0].price = atoi(price);
    }
    else{
        MoveRightArrDin(&*array,0);
        for(int j=0; j <tempWord.Length;j++){
            (*array).elements[0].name[j] = tempWord.TabWord[j];
        }
        (*array).elements[0].name[tempWord.Length] = '\0';
        (*array).elements[0].price = atoi(price);
    }
    (*array).Neff ++;
    UpdateCapacity(&*array);
}

void InsertAtNameArrDin(ArrayDin *array, string input, Index i){
    // Algoritma
    if(i==0){
        InsertFirstNameArrDin(&*array,input);
    }

    else if(i<LengthArrDin(*array)-1){
        // Kamus Lokal
        Word tempWord;
        StrcpyToWord(&tempWord,input);
        // algoritma
        MoveRightArrDin(&*array,i);
        for(int j=0; j <tempWord.Length;j++){
            (*array).elements[i].name[j] = tempWord.TabWord[j];
        }
        (*array).elements[i].name[tempWord.Length] = '\0';

        (*array).Neff++;
        UpdateCapacity(&*array);
    }
    else{
        InsertLastNameArrDin(&*array,input);
    }

}

void InsertAtArrDin(ArrayDin *array, string price, string name, Index i){
    // Algoritma
    if(i==0){
        InsertFirstArrDin(&*array,price,name);
    }

    else if(i<LengthArrDin(*array)-1){
        // Kamus Lokal
        Word tempWord;
        StrcpyToWord(&tempWord,name);
        // algoritma
        MoveRightArrDin(&*array,i);
        for(int j=0; j <tempWord.Length;j++){
            (*array).elements[i].name[j] = tempWord.TabWord[j];
        }
        (*array).elements[i].name[tempWord.Length] = '\0';
        (*array).elements[i].price = atoi(price);

        (*array).Neff++;
        UpdateCapacity(&*array);
    }
    else{
        InsertLastArrDin(&*array,price,name);
    }

}

void InsertLastNameArrDin(ArrayDin *array, string input){
    // Kamus Lokal
    int last=LengthArrDin(*array);
    Word tempWord;
    StrcpyToWord(&tempWord,input);

    // Algoritma
    for(int j=0; j <tempWord.Length;j++){
        (*array).elements[last].name[j] = tempWord.TabWord[j];
    }
    (*array).elements[last].name[tempWord.Length] = '\0';

    (*array).Neff++;
    UpdateCapacity(&*array);
}

void InsertLastArrDin(ArrayDin *array, string price,string name){
    // Kamus Lokal
    int last=LengthArrDin(*array);
    Word tempWord;
    StrcpyToWord(&tempWord,name);

    // Algoritma
    for(int j=0; j <tempWord.Length;j++){
        (*array).elements[last].name[j] = tempWord.TabWord[j];
    }
    (*array).elements[last].name[tempWord.Length] = '\0';
    (*array).elements[last].price = atoi(price);
    (*array).Neff++;
    UpdateCapacity(&*array);
}

void DeleteFirstArrDin(ArrayDin *array){
    MoveLeftArrDin(&*array,0);
    UpdateCapacity(&*array);
    (*array).Neff --;
}

void DeleteAtArrDin(ArrayDin *array, Index i){
    MoveLeftArrDin(&*array,i);
    UpdateCapacity(&*array);
    (*array).Neff --;
}

void DeleteLastArrDin(ArrayDin *array){
    (*array).Neff --;
    UpdateCapacity(&*array);
}

// Searching Metode 
Index SearchArrDin(ArrayDin array, string input){
    // Kamus lokal
    int length = LengthArrDin(array);
    int i=0;
    int out=-1;
    boolean found =false;

    // Algoritma
    while(!found && i<length){
        if(IsSame(array.elements[i].name,input)){
            found = true;
        }
        else{
            i++;
        }
    }
    return i;
}

// Boolean
boolean IsEmpty(ArrayDin array){
    return(array.Neff == 0);
}

boolean IsInArrDin(ArrayDin array, string input){
    // Kamus lokal
    int length = LengthArrDin(array);
    int i=0;
    int out=-1;
    boolean found =false;

    // Algoritma
    while(!found && i<length){
        if(IsSame(array.elements[i].name,input)){
            found = true;
        }
        else{
            i++;
        }
    }
    return found;
}