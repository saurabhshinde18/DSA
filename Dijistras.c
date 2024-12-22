#include <stdio.h>
#define INF 9999
#define MAX 10

int graph[MAX][MAX], dist[MAX], visited[MAX], pred[MAX];
int n;

int minDistance() {
    int min = INF, minIndex;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        pred[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }
}

int main() {
    int edges, src, dest, weight, start;
    printf("Enter the number of areas (nodes): ");
    scanf("%d", &n);
    printf("Enter the number of roads (edges): ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter source, destination, and weight for edge %d: ", i + 1);
        scanf("%d%d%d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (i != start) {
            printf("To %d: %d\n", i, dist[i]);
        }
    }

    return 0;
}
