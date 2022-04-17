typedef struct {
    int** adjList;
    int nodes;
    int edges;
} GRAPH;

GRAPH readGraph(char* FName);
void DFS(GRAPH G);
void BFS(GRAPH G);
void MST(GRAPH G);