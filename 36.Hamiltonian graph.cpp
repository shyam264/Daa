#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int V;

bool isSafe(int v, int pos, int path[], int n) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCircuitUtil(int path[], int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos, path, n)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(path, pos + 1, n))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCircuit() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (!hamiltonianCircuitUtil(path, 1, V)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Hamiltonian Circuit exists with the following vertices:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);

    return true;
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (!hamiltonianCircuit())
        printf("No solution exists.\n");

    return 0;
}
