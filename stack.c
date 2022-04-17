#include "llist.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

STACK createStack() {
    return createList();
}

int isEmptyStack(STACK stack) {
    return stack == NULL;
}

STACK push(STACK S, int k) {
    return insertAtFront(S, k);
}

STACK pop(STACK S, int *k) {
    return deleteFromFront(S, k);
}