typedef struct _node {
    int data;
    struct _node *next;
} NODE;

typedef NODE *LLIST;

LLIST createList();
int searchList(LLIST H, int k);
LLIST insertAtFront(LLIST H, int k);
LLIST insertAtEnd(LLIST H, int k);
LLIST deleteFromFront(LLIST H, int* k);
LLIST deleteFromEnd(LLIST H, int* k);
LLIST deleteList(LLIST H, int k);