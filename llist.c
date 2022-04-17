#include "llist.h"

#include <stdio.h>
#include <stdlib.h>

LLIST createList() {
    LLIST list = (NODE *)malloc(sizeof(NODE));
    list = NULL;

    return list;
}

LLIST insertAtFront(LLIST H, int k) {
    if (H == NULL) {
        H = (NODE *)malloc(sizeof(NODE));
        H->data = k;
        H->next = NULL;
    } else {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        newNode->data = k;
        newNode->next = H;
        H = newNode;
    }

    return H;
}

LLIST insertAtEnd(LLIST H, int k) {
    if (H == NULL) {
        H = (NODE *)malloc(sizeof(NODE));
        H->data = k;
        H->next = NULL;
    } else {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        newNode->data = k;
        newNode->next = NULL;

        NODE *temp = H;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return H;
}

LLIST deleteFromFront(LLIST H, int *k) {
    if (H == NULL) {
        *k = -1;
    } else {
        *k = H->data;
        NODE *temp = H->next;
        H = temp;
    }

    return H;
}

LLIST deleteFromEnd(LLIST H, int *k) {
    if (H == NULL) {
        *k = -1;
    } else {
        NODE *temp = H;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        *k = temp->next->data;
        free(temp->next);
        temp->next = NULL;
    }

    return H;
}

LLIST deleteList(LLIST H, int k) {
    if (H == NULL) {
        return H;
    } else {
        NODE *temp = H;
        while (temp->next != NULL) {
            if (temp->next->data == k) {
                NODE *temp2 = temp->next;
                temp->next = temp->next->next;
                free(temp2);

                return H;
            }
            temp = temp->next;
        }
    }

    return H;
}