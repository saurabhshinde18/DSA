#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];

void DFS(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

void BFS(int start, int n) {
    int queue[MAX], front = -1, rear = -1, currentVertex;
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear) {
        currentVertex = queue[++front];
        printf("%d ", currentVertex);
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, edges, src, dest, start;
    printf("Enter the number of areas (nodes): ");
    scanf("%d", &n);
    printf("Enter the number of roads (edges): ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter source and destination for edge %d: ", i + 1);
        scanf("%d%d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    printf("Enter starting node for DFS and BFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(start, n);

    printf("\nBFS Traversal: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    BFS(start, n);

    return 0;
}
