#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5
#define INFINITE 10000

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

int bellman_ford(Edge * e_list, int num_edges, int s_node, int t_node);
int M[MAX_NODES][MAX_NODES];

int main() {

    // initialize example Graph
    int V = MAX_NODES;
    int E = 5;

    Edge edge_list [] = {
    {1, 3, 2},
    {4, 3, -1},
    {2, 4, 1},
    {1, 2, 1},
    {0, 1, 5}};
    
    int t = 4; //terminal node
    int s = 0; //source node.

    // Initialize memo_matrix M
    for (int i = 0; i < MAX_NODES; i++) 
        for (int j = 0; j < MAX_NODES; j++) 
            M[i][j] = -1; 

    
    for (int i = 0; i < MAX_NODES; i++) {
        M[i][0] = INFINITE; // not possible
        M[t][i] = 0; // since t = 4, the 4th row should be all 0.
    }
    M[t][0] = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            printf("\t%d ", M[i][j]);
        }
        printf("\n");
    }

    // run bellman_ford shortest path.
    bellman_ford(edge_list, E, s, t);

    /* Here you should print the final M matrix as well as the shortest 
     * path calculated from 's' to 't'. This can be done by carefully traversing
     * through the matrix M.
     * 
     * What we care about is the value of M[s][E-1];
    */
}

int bellman_ford(Edge * e_list, int num_edges, int s_node, int t_node) {
    /* implement code here. you can find an explaination and psuedocode in the 
     * textbook around page 290. The psuedocode calculates the M matrix, where
     * M[i][j] represents the shortest path from i to t, using at most j edges
     * 
     * Remember to use recurrence relation and recursion to solve this problem. 
    */
}
