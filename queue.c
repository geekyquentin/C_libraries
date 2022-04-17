#include "llist.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

QUEUE createQueue() {
    return createList();
}

int isEmptyQueue(QUEUE Q) {
    return Q == NULL;
}

QUEUE enqueue(QUEUE Q, int k) {
    return insertAtEnd(Q, k);
}

QUEUE dequeue(QUEUE Q, int* k) {
    return deleteFromFront(Q, k);
}