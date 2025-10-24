// Juan Acosta
#include <stdio.h>

int main() {
    int n = 4;
    char vertices[] = {'A', 'B', 'C', 'D'};
    int adj[4][4] = {0};

    // Undirected edges: {A,B}, {A,C}, {B,D}
    adj[0][1] = adj[1][0] = 1;  // A-B
    adj[0][2] = adj[2][0] = 1;  // A-C
    adj[1][3] = adj[3][1] = 1;  // B-D

    printf("Adjacency Matrix (Undirected):\n   ");
    for (int i = 0; i < n; i++)
        printf("%c ", vertices[i]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%c: ", vertices[i]);
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
