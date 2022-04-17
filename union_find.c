#include <stdio.h>
#include <stdlib.h>

#include "union_find.h"

UNION_FIND createUF(int n) {
    UNION_FIND F;

    F.arr = (NODE_PTR*)malloc(n * sizeof(NODE_PTR));
    F.size = n;

    for (int i = 0; i < n; i++) {
        F.arr[i] = NULL;
    }

    return F;
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int* i) {
    for (int j = 0; j < F.size; j++) {
        if (F.arr[j] == NULL) {
            NODE_PTR newNode = (NODE_PTR)malloc(sizeof(NODE_PTR));
            newNode->data = x;
            newNode->nodes = 1;
            newNode->next = NULL;

            F.arr[j] = newNode;
            *i = j;

            return F;
        }
    }

    printf("Error: Size limit exceeded\n");
    exit(1);
}

NODE_PTR findUF(UNION_FIND F, int i) {
    NODE_PTR temp = F.arr[i];

    while (temp->next != NULL) {
        temp = temp->next;
    }

    return temp;
}

void unionUF(UNION_FIND F, int i, int j) {
    int iNodes = F.arr[i]->nodes;
    int jNodes = F.arr[j]->nodes;

    if (iNodes < jNodes) {
        NODE_PTR temp = F.arr[i];

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = F.arr[j];
    } else {
        NODE_PTR temp = F.arr[j];

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = F.arr[i];
    }

    F.arr[i]->nodes = iNodes + jNodes;
    F.arr[j]->nodes = iNodes + jNodes;
}
