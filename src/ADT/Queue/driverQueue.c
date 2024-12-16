#include <stdio.h>
#include "queue.h"

int main(){
    Queue Q;
    Word Temp;

    CreateQueue(&Q);
    printf("%d isEmpty\n",isEmpty(Q));
    printf("%d isFull\n",isFull(Q));
    printf("%d length\n",length(Q));

    // Test Enqueue
    printf("\nTest Enqueue\n");
    STARTWORD();
    enqueue(&Q,CurrentWord);
    displayQueue(Q);
    STARTWORD();
    enqueue(&Q,CurrentWord);
    displayQueue(Q);

    //Test Dequeue
    printf("\nTest Dequeue\n");
    dequeue(&Q,&Temp);
    displayQueue(Q);

    //Test IsInQueue
    printf("\nTest IsInQueue\n");
    STARTWORD();
    printf("%d IsInQueue\n",IsInQueue(Q,CurrentWord));
}