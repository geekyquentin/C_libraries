#define ARR_COUNT 100

typedef struct {
    int arr[ARR_COUNT];
    int size;
    int capacity;
} HEAP;

HEAP createHeap();
int findMin(HEAP H);
HEAP extractMin(HEAP H);
HEAP insertHeap(HEAP H, int k);
int isFullHeap(HEAP H);
int isEmptyHeap(HEAP H);