#include <stdio.h>
#include <stdlib.h>

#include "ArrayDinamis.h"

// Konstruktor
void MakeArrayDin(ArrayDin *array) {
    (*array).input = (string *)malloc(InitialSize * sizeof(string));
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

void CetakArrayDin(ArrayDin array){
    for (int i = 0; i < array.Neff; i++) {
        printf("%s\n", array.input[i]);
    }
}

void UpdateCapacity(ArrayDin *array){
    if(LengthArrDin(*array) > 0.8*GetCapacity(*array)){
        (*array).Capacity *=2;
        (*array).input = (string *)realloc((*array).input,(*array).Capacity * sizeof(string));
    }
    else if((LengthArrDin (*array) < 0.25*GetCapacity(*array)) && GetCapacity(*array)>20){
        (*array).Capacity /=2;
        (*array).input = (string *)realloc((*array).input,(*array).Capacity * sizeof(string));
    }
}

void DeallocateArrDin(ArrayDin *array){
    for (int i = 0; i < (*array).Neff; i++) {
        free((*array).input[i]);
    }
    free((*array).input);
    (*array).input = NULL;     
    (*array).Capacity = 0;      
    (*array).Neff = 0;    
}

void MoveRightArrDin(ArrayDin *array,Index from){
    for(int i = (*array).Neff; i>from;i--){
        (*array).input[i] = (*array).input[i-1];
    }
}

void MoveLeftArrDin(ArrayDin *array, Index from){
    for(int i = from; i<(*array).Neff;i++){
        (*array).input[i] = (*array).input[i+1];
    }
}

string GetInput(ArrayDin array, Index i){
    return(array.input[i]);
}

// Pengolahan Data
void InsertFirstArrDin(ArrayDin *array,string input){
    // Kamus Lokal
    Word tempWord;
    StrcpyToWord(&tempWord,input);

    // Algoritma
    if(IsEmpty(*array)){
        (*array).input[0] = (string)malloc((tempWord.Length+1) * sizeof(char));
        for(int j=0; j <tempWord.Length;j++){
            (*array).input[0][j] = tempWord.TabWord[j];
        }
        (*array).input[0][tempWord.Length] = '\0';
    }
    else{
        MoveRightArrDin(&*array,0);
        (*array).input[0] = (string)malloc((tempWord.Length+1) * sizeof(char));
        for(int j=0; j <tempWord.Length;j++){
            (*array).input[0][j] = tempWord.TabWord[j];
        }
        (*array).input[0][tempWord.Length] = '\0';
    }
    (*array).Neff ++;
    UpdateCapacity(&*array);
}

void InsertAtArrDin(ArrayDin *array, string input, Index i){
    // Algoritma
    if(i==0){
        InsertFirstArrDin(&*array,input);
    }

    else if(i<LengthArrDin(*array)-1){
        // Kamus Lokal
        Word tempWord;
        StrcpyToWord(&tempWord,input);
        // algoritma
        MoveRightArrDin(&*array,i);
        (*array).input[i] = (string)malloc((tempWord.Length+1) * sizeof(char));
        for(int j=0; j <tempWord.Length;j++){
            (*array).input[i][j] = tempWord.TabWord[j];
        }
        (*array).input[i][tempWord.Length] = '\0';

        (*array).Neff++;
        UpdateCapacity(&*array);
    }
    else{
        InsertLastArrDin(&*array,input);
    }

}

void InsertLastArrDin(ArrayDin *array, string input){
    // Kamus Lokal
    int last=LengthArrDin(*array);
    Word tempWord;
    StrcpyToWord(&tempWord,input);

    // Algoritma
    (*array).input[last] = (string)malloc((tempWord.Length+1) * sizeof(char));
    for(int j=0; j <tempWord.Length;j++){
        (*array).input[last][j] = tempWord.TabWord[j];
    }
    (*array).input[last][tempWord.Length] = '\0';

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
        if(IsSame(array.input[i],input)){
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