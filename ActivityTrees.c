// Juan Acosta 
#include <stdio.h>
#define MAXSIZE 20

typedef struct {
    char nodes[MAXSIZE];
    int numElements;
} Tree;

int main() {
    Tree tree;
    
    // Lugares vacíos = X
    char values[] = {'G', 'D', 'I', 'B', 'F', 'H', 'J', 'A', 'C', 'X', 'E', 'X', 'X', 'X', 'X'};
    tree.numElements = 15;

    for (int i = 0; i < tree.numElements; i++) {
        tree.nodes[i] = values[i];
    }

    printf("=== Full Binary Tree (Array-based) ===\n");
    for (int i = 0; i < tree.numElements; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        printf("\nNode %c at index [%d]", tree.nodes[i], i);

        if (left < tree.numElements)
            printf("\n\tLeft child: %c", tree.nodes[left]);
        else
            printf("\n\tLeft child: NULL");

        if (right < tree.numElements)
            printf("\n\tRight child: %c", tree.nodes[right]);
        else
            printf("\n\tRight child: NULL");
    }

    return 0;
}
