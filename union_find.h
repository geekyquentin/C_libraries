typedef struct _djnode {
    int data;
    int nodes;
    struct _djnode* next;
} DJNODE;

typedef DJNODE* NODE_PTR;

typedef struct _uf {
    NODE_PTR* arr;
    int size;
} UNION_FIND;

UNION_FIND createUF(int n);
UNION_FIND makeSetUF(UNION_FIND F, int x, int* i);
NODE_PTR findUF(UNION_FIND F, int i);
void unionUF(UNION_FIND F, int i, int j);