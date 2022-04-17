#include <stdio.h>

#include "llist.h"
#include "stack.h"
#include "queue.h"
#include "union_find.h"
#include "graph.h"

int main() {
    printf("Enter the file name: ");
    char fileName[100];
    scanf("%s", fileName);

    GRAPH G = readGraph(fileName);
    printf("DFS: ");
    DFS(G);
    printf("\n");
    printf("BFS: ");
    BFS(G);
    printf("\n");
    printf("MST: \n");
    MST(G);
    return 0;
}