#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
  return (IDX_HEAD(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
  return ((IDX_TAIL(q)+1)%CAPACITY == IDX_HEAD(q));
}

int length(Queue q){
  if(isEmpty(q)){
    return 0;
  } else{
    if(IDX_TAIL(q) - IDX_HEAD(q) >= 0){
      return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    } else{
      return (CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1);
    }
  }
}

void enqueue(Queue *q, ElType val){
  if(isEmpty(*q)){
    IDX_TAIL(*q) = 0;
    IDX_HEAD(*q) = 0;
  } else{
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
  }
  TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){

  *val = HEAD(*q);

  if(IDX_HEAD(*q) == IDX_TAIL(*q)){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
  } else{
    IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
  }
}

void displayQueue (Queue q){
    if(IDX_HEAD(q) == IDX_UNDEF){
        printf("[]\n");
    }
    else {
        printf("[");
        int i = IDX_HEAD(q);
        int IndexTail = IDX_TAIL(q);
        while (i != (IndexTail+1)%CAPACITY){
            if(i == IndexTail){
                printf("%s",q.buffer[i]);
            }
            else{
                printf("%s,",q.buffer[i]);
            }
            i = (i+1) %CAPACITY;
        }
        printf("]\n");
    }
}

// Boolean
boolean IsInQueue(Queue *q, string input) {
    string temp;
    Queue tempQueue;
    CreateQueue(&tempQueue);
    boolean found = false;

    if (isEmpty(*q)) {
        return false;
    }

    // Proses pengecekan dan simpan salinan elemen dalam tempQueue
    while (!isEmpty(*q)) {
        dequeue(q, &temp);
        enqueue(&tempQueue, temp);  // Salin elemen ke tempQueue
    }

    // Proses pengecekan dan kembalikan elemen ke antrian asli
    while (!isEmpty(tempQueue)) {
        dequeue(&tempQueue, &temp);
        if (IsSame(temp, input)) {
            found = true;
        }
        enqueue(q, temp);  // Mengembalikan elemen ke antrian asli dengan aman
    }

    return found;
}
