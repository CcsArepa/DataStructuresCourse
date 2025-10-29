// Juan Acosta
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Intercambia dos elementos del heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sube el elemento en la posición i hasta restaurar la propiedad del Max-Heap
void reHeapUp(int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] > heap[parent]) {
        swap(&heap[i], &heap[parent]);
        reHeapUp(parent);
    }
}

// Inserta un elemento en el heap
void insert(int item) {
    if (size >= MAX) {
        printf("Heap full, cannot insert.\n");
        return;
    }
    
    heap[size] = item;
    reHeapUp(size);
    size++;
}

// Baja el elemento en la posición i hasta restaurar la propiedad del Max-Heap
void reHeapDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        reHeapDown(largest);
    }
}

// Elimina el elemento máximo (la raíz)
int removeMax() {
    if (size == 0) {
        printf("Heap empty.\n");
        return -1;
    }

    int maxItem = heap[0];
    heap[0] = heap[size - 1];
    size--;
    reHeapDown(0);

    return maxItem;
}

// Muestra el heap completo (como arreglo)
void showHeap() {
    printf("Actual heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Muestra cada nodo con sus hijos izquierdo y derecho (usando índices)
void printHeapStructure() {
    printf("\nHeap Structure:\n");
    for (int i = 0; i < size; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        printf("Node [%d] = %d  | ", i, heap[i]);
        if (left < size)
            printf("Left[%d]=%d ", left, heap[left]);
        else
            printf("Left[ ]=NULL ");

        if (right < size)
            printf("Right[%d]=%d\n", right, heap[right]);
        else
            printf("Right[ ]=NULL\n");
    }
    printf("\n");
}

// Programa principal
int main() {
    int n, item, k;

    printf("=== Max-Heap Construction ===\n");
    printf("How many elements do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Insert element #%d: ", i + 1);
        scanf("%d", &item);
        insert(item);
        showHeap();
    }

    printHeapStructure();

    printf("\nHow many elements do you want to remove (removeMax)? ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int removed = removeMax();
        if (removed != -1)
            printf("Removed: %d\n", removed);
        showHeap();
    }

    printHeapStructure();

    return 0;
}
