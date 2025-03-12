#include <stdio.h>
#define MAX 5

// Function for Topological Sort using DFS
void topologicalSortUtil(int adj[][MAX], int visited[], int stack[], int* top, int start) {
    visited[start] = 1;
    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] && !visited[i]) {
            topologicalSortUtil(adj, visited, stack, top, i);
        }
    }
    stack[++(*top)] = start;
}

// Function to perform Topological Sort
void topologicalSort(int adj[][MAX]) {
    int visited[MAX] = {0};
    int stack[MAX], top = -1;

    for (int i = 0; i < MAX; i++) {
        if (!visited[i]) {
            topologicalSortUtil(adj, visited, stack, &top, i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%c ", stack[top--] + 65);
    }
    printf("\n");
}

int main() {
    int adj[MAX][MAX];
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(adj);

    return 0;
}
