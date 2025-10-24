// Juan Acosta
#include <stdio.h>

int main() {
    char vertices[] = {'A', 'B', 'C', 'D'};

    // Adjacency list using arrays of arrays
    int n = 4;
    int adjList[4][4] = {
        {1, 2, -1, -1}, // A -> B, C
        {3, -1, -1, -1}, // B -> D
        {-1, -1, -1, -1}, // C -> none
        {-1, -1, -1, -1}  // D -> none
    };

    printf("Adjacency List (Directed):\n");
    for (int i = 0; i < n; i++) {
        printf("%c -> ", vertices[i]);
        for (int j = 0; j < 4 && adjList[i][j] != -1; j++) {
            printf("%c ", vertices[adjList[i][j]]);
        }
        printf("\n");
    }

    return 0;
}
