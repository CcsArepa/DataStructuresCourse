// Queue using Linked Lists
// Juan Diego Acosta Ojeda
// ID: 185015


#include <stdio.h>
#include <stdlib.h>     
#include <stdbool.h>    

// The 'Node' is each individual element in our list.
// It stores a piece of data and a pointer to the next node.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// The 'Queue' controls the entire structure.
// We only need to know what the first and the last elements are.
typedef struct Queue {
    Node* front; // Points to the front of the queue (where data exits)
    Node* rear;  // Points to the rear of the queue (where data enters)
} Queue;


// Queue Functions (ADT Implementation)

// Function to create a new, empty queue in memory.
Queue* createQueue() {
    // 1. Request memory for the main Queue structure
    Queue* q = (Queue*)malloc(sizeof(Queue));
    // 2. Initially, there are no nodes, so front and rear point to NOTHING (NULL).
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty.
// Returns 'true' if empty, 'false' otherwise.
bool isEmpty(Queue* q) {
    // If 'front' is NULL, it means there are no elements.
    return (q->front == NULL);
}

// Function to add an element to the rear of the queue (Enqueue).
void enqueue(Queue* q, int value) {
    // 1. Create a new node to store the value.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL; // The new node always goes at the very end, so its 'next' is NULL.

    // 2. Check if the queue is empty.
    if (isEmpty(q)) {
        // If it's empty, the new node is both the front and the rear.
        q->front = newNode;
        q->rear = newNode;
    } else {
        // If there are already elements, the current rear node must point to the new node.
        q->rear->next = newNode;
        // 3. Update the 'rear' pointer to now point to the new last node.
        q->rear = newNode;
    }
    printf("-> Value %d was added to the queue.\n", value);
}

// Function to remove and return the element from the front of the queue (Dequeue).
int dequeue(Queue* q) {
    // 1. We can't remove something if the queue is empty.
    if (isEmpty(q)) {
        printf("ERROR: The queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value.
    }

    // 2. Save the front node so we don't lose it.
    Node* tempNode = q->front;
    int dequeuedValue = tempNode->data;

    // 3. Move the 'front' pointer to the next node in the list.
    q->front = q->front->next;

    // 4. Special case: if removing the node makes the queue empty,
    // we must also update the 'rear' pointer to NULL.
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(tempNode);

    return dequeuedValue;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }

    Node* temp = q->front;
    printf("QUEUE: [FRONT] -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("[REAR]\n");
}

int main() {
    Queue* myQueue = createQueue();
    int option;
    int value;

    do {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display Queue\n");
        printf("4. Check if Empty\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number you want to add: ");
                scanf("%d", &value);
                enqueue(myQueue, value);
                break;
            case 2:
                if (!isEmpty(myQueue)) {
                    value = dequeue(myQueue);
                    printf("<- Value %d was removed from the queue.\n", value);
                } else {
                    dequeue(myQueue);
                }
                break;
            case 3:
                displayQueue(myQueue);
                break;
            case 4:
                if (isEmpty(myQueue)) {
                    printf("Result: The queue IS empty.\n");
                } else {
                    printf("Result: The queue IS NOT empty.\n");
                }
                break;
            case 0:
                printf("Goodbye! Freeing memory...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 0);

    while (!isEmpty(myQueue)) {
        dequeue(myQueue);
    }
    free(myQueue);

    return 0;
}
