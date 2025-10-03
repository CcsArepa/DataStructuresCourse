// Juan Diego Acosta Ojeda
// ID: 185015

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL; // Cabeza de la lista
int listSize = 0;

// Crear nuevo nodo
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Verificar si está vacía
int isEmpty() {
    return head == NULL;
}

// Obtener tamaño
int size() {
    return listSize;
}

// Agregar al frente
void addFront(int data) {
    Node* newNode = createNode(data);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    listSize++;
}

// Agregar al final
void addEnd(int data) {
    Node* newNode = createNode(data);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = newNode;
        newNode->next = head;
    }
    listSize++;
}

// Agregar en posición (0 = frente)
void addAtPosition(int data, int position) {
    if (position < 0 || position > listSize) {
        printf("Posición inválida.\n");
        return;
    }
    if (position == 0) {
        addFront(data);
        return;
    }
    if (position == listSize) {
        addEnd(data);
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    listSize++;
}

// Eliminar del frente
void removeFront() {
    if (isEmpty()) {
        printf("Lista vacía.\n");
        return;
    }
    Node* temp = head;
    if (head->next == head) { 
        head = NULL;
    } else {
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        head = head->next;
        tail->next = head;
    }
    free(temp);
    listSize--;
}

// Eliminar del final
void removeEnd() {
    if (isEmpty()) {
        printf("Lista vacía.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    listSize--;
}

// Eliminar en posición
void removeAtPosition(int position) {
    if (position < 0 || position >= listSize) {
        printf("Posición inválida.\n");
        return;
    }
    if (position == 0) {
        removeFront();
        return;
    }
    if (position == listSize - 1) {
        removeEnd();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    listSize--;
}

// Buscar un valor
int search(int value) {
    if (isEmpty()) return -1;
    Node* temp = head;
    int index = 0;
    do {
        if (temp->data == value) return index;
        temp = temp->next;
        index++;
    } while (temp != head);
    return -1;
}

// Recorrer lista
void traverse() {
    if (isEmpty()) {
        printf("Lista vacía.\n");
        return;
    }
    Node* temp = head;
    printf("Recorrido: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Mostrar lista
void display() {
    if (isEmpty()) {
        printf("Lista vacía.\n");
        return;
    }
    Node* temp = head;
    printf("Lista: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Obtener cabeza
void getHead() {
    if (isEmpty()) printf("Lista vacía.\n");
    else printf("Head: %d\n", head->data);
}

// Obtener cola
void getTail() {
    if (isEmpty()) printf("Lista vacía.\n");
    else {
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        printf("Tail: %d\n", tail->data);
    }
}

// Vaciar lista
void clear() {
    while (!isEmpty()) {
        removeFront();
    }
    printf("Lista eliminada completamente.\n");
}

// Menú principal
void menu() {
    int choice, data, pos;
    do {
        printf("\n--- Circular Linked List ADT ---\n");
        printf("1. Add to Front\n");
        printf("2. Add to End\n");
        printf("3. Add at Position\n");
        printf("4. Remove from Front\n");
        printf("5. Remove from End\n");
        printf("6. Remove from Position\n");
        printf("7. Search\n");
        printf("8. Traverse\n");
        printf("9. Size\n");
        printf("10. Is Empty\n");
        printf("11. Clear\n");
        printf("12. Display\n");
        printf("13. Get Head\n");
        printf("14. Get Tail\n");
        printf("0. Exit\n");
        printf("Select option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Dato: "); scanf("%d", &data);
                addFront(data); break;
            case 2:
                printf("Dato: "); scanf("%d", &data);
                addEnd(data); break;
            case 3:
                printf("Dato: "); scanf("%d", &data);
                printf("Posición: "); scanf("%d", &pos);
                addAtPosition(data, pos); break;
            case 4: removeFront(); break;
            case 5: removeEnd(); break;
            case 6:
                printf("Posición: "); scanf("%d", &pos);
                removeAtPosition(pos); break;
            case 7:
                printf("Valor a buscar: "); scanf("%d", &data);
                pos = search(data);
                if (pos == -1) printf("No encontrado.\n");
                else printf("Encontrado en posición %d\n", pos);
                break;
            case 8: traverse(); break;
            case 9: printf("Tamaño: %d\n", size()); break;
            case 10: printf(isEmpty() ? "Lista vacía.\n" : "Lista con elementos.\n"); break;
            case 11: clear(); break;
            case 12: display(); break;
            case 13: getHead(); break;
            case 14: getTail(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
