// Juan Diego Acosta Ojeda 
// ID:185015

#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; 

// a. Crear nodo y agregarlo al final
void createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Nodo con valor %d creado.\n", value);
}

// b. Mostrar nodos
void displayNodes() {
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    struct Node* temp = head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// c. Insertar nodo al inicio
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Nodo con valor %d insertado al inicio.\n", value);
}

// d. Insertar nodo en posición específica
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Posición inválida.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("La posición excede el tamaño de la lista.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Nodo con valor %d insertado en la posición %d.\n", value, pos);
}

// e. Insertar nodo al final
void insertAtEnd(int value) {
    createNode(value); 
}

// f. Eliminar nodo al inicio
void deleteAtBeginning() {
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Nodo con valor %d eliminado del inicio.\n", temp->data);
    free(temp);
}

// g. Eliminar nodo al final
void deleteAtEnd() {
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Nodo con valor %d eliminado del final.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Nodo con valor %d eliminado del final.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// h. Eliminar nodo en posición específica
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    if (pos < 1) {
        printf("Posición inválida.\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("La posición excede el tamaño de la lista.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Nodo con valor %d eliminado en la posición %d.\n", nodeToDelete->data, pos);
    free(nodeToDelete);
}

int main() {
    int opcion, valor, pos;

    do {
        printf("\n--- MENÚ LISTA ENLAZADA ---\n");
        printf("1. Crear nodo\n");
        printf("2. Mostrar nodos\n");
        printf("3. Insertar al inicio\n");
        printf("4. Insertar en posición\n");
        printf("5. Insertar al final\n");
        printf("6. Eliminar al inicio\n");
        printf("7. Eliminar al final\n");
        printf("8. Eliminar en posición\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese valor: ");
                scanf("%d", &valor);
                createNode(valor);
                break;
            case 2:
                displayNodes();
                break;
            case 3:
                printf("Ingrese valor: ");
                scanf("%d", &valor);
                insertAtBeginning(valor);
                break;
            case 4:
                printf("Ingrese valor: ");
                scanf("%d", &valor);
                printf("Ingrese posición: ");
                scanf("%d", &pos);
                insertAtPosition(valor, pos);
                break;
            case 5:
                printf("Ingrese valor: ");
                scanf("%d", &valor);
                insertAtEnd(valor);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                printf("Ingrese posición: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 0);

    return 0;
}
