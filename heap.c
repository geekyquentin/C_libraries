#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

HEAP createHeap() {
    HEAP H;
    H.size = 0;
    H.capacity = ARR_COUNT;
    return H;
}

int findMin(HEAP H) {
    if (isEmptyHeap(H)) {
        printf("Error: Heap is empty\n");
        exit(1);
    }

    return H.arr[0];
}

HEAP extractMin(HEAP H) {
    if (isEmptyHeap(H)) {
        printf("Error: Heap is empty\n");
        exit(1);
    }

    int i, j;
    H.arr[0] = H.arr[H.size - 1];
    H.size--;
    i = 0;
    while (i < H.size) {
        j = 2 * i + 1;
        if (j < H.size && H.arr[j] > H.arr[j + 1]) {
            j++;
        }
        if (H.arr[i] <= H.arr[j]) {
            break;
        }
        int tmp = H.arr[i];
        H.arr[i] = H.arr[j];
        H.arr[j] = tmp;
        i = j;
    }
    return H;
}

HEAP insertHeap(HEAP H, int k) {
    if (isFullHeap(H)) {
        printf("Error: Heap is full\n");
        exit(1);
    }

    H.size++;
    int i = H.size - 1;
    while (i > 0 && H.arr[(i - 1) / 2] > k) {
        H.arr[i] = H.arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    H.arr[i] = k;
    return H;
}

int isFullHeap(HEAP H) {
    return H.size == H.capacity;
}

int isEmptyHeap(HEAP H) {
    return H.size == 0;
}