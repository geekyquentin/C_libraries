#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

#include "llist.h"
#include "stack.h"
#include "queue.h"
#include "union_find.h"

typedef struct _edge {
    int weight;
    int dest;
    int src;
} EDGE;

GRAPH readGraph(char *FName) {
    FILE *f = fopen(FName, "r");

    int n, m;
    fscanf(f, "%d %d", &n, &m);

    GRAPH G;
    G.nodes = n;
    G.edges = m;

    G.adjList = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G.adjList[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            G.adjList[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        fscanf(f, "%d %d %d", &u, &v, &w);
        G.adjList[u][v] = w;
        G.adjList[v][u] = w;
    }

    fclose(f);

    return G;
}

void DFS(GRAPH G) {
    STACK S = createStack();

    int *visited = (int *)malloc(G.nodes * sizeof(int));
    for (int i = 0; i < G.nodes; i++) {
        visited[i] = 0;
    }

    S = push(S, 0);

    while (!isEmptyStack(S)) {
        int u;
        S = pop(S, &u);

        if (visited[u] == 0) {
            printf("%d ", u);
            visited[u] = 1;
        }

        for (int i = 0; i < G.nodes; i++) {
            if (visited[i] == 0 && G.adjList[u][i] != 0) {
                S = push(S, i);
            }
        }
    }
}

void BFS(GRAPH G) {
    QUEUE Q = createQueue();

    int *visited = (int *)malloc(G.nodes * sizeof(int));
    for (int i = 0; i < G.nodes; i++) {
        visited[i] = 0;
    }

    Q = enqueue(Q, 0);
    visited[0] = 1;

    while (!isEmptyQueue(Q)) {
        int u;
        Q = dequeue(Q, &u);

        printf("%d ", u);

        for (int j = 0; j < G.nodes; j++) {
            if (visited[j] == 0 && G.adjList[u][j] != 0) {
                Q = enqueue(Q, j);
                visited[j] = 1;
            }
        }
    }
}

EDGE *sortEdges(EDGE *edges, int n) {
    EDGE temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    return edges;
}

void MST(GRAPH G) {
    // get the edges from the graph
    EDGE *edges = (EDGE *)malloc(G.edges * sizeof(EDGE));
    int k = 0;
    for (int i = 0; i < G.nodes; i++) {
        for (int j = 0; j < G.nodes; j++) {
            if (G.adjList[i][j] != 0) {
                edges[k].weight = G.adjList[i][j];
                edges[k].src = i;
                edges[k].dest = j;

                G.adjList[j][i] = 0;
                k++;
            }
        }
    }

    // sort the edges in ascending order
    edges = sortEdges(edges, G.edges);

    // create a union-find data structure
    UNION_FIND uf = createUF(G.nodes);

    // make sets for all the nodes
    int j;
    for (int i = 0; i < G.nodes; i++) {
        uf = makeSetUF(uf, i, &j);
    }

    EDGE *result = (EDGE *)malloc(G.edges * sizeof(EDGE));
    k = 0;
    for (int i = 0; i < G.edges; i++) {
        if (findUF(uf, edges[i].src) != findUF(uf, edges[i].dest)) {
            unionUF(uf, edges[i].src, edges[i].dest);
            result[k++] = edges[i];
        }
    }

    // print the MST
    int weight = 0;
    for (int i = 0; i < k; i++) {
        weight += result[i].weight;
        printf("%d -- %d => weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    printf("\nTotal weight: %d\n", weight);
}