/* Instructions
Implement a program that:
- Creates a queue of 5 ints
- Asks the user to decide if he/she wants to enqueue or dequeue
- If enqueue, read the element from the keyboard and insert in the queue (if the queue is not full)
- Show the current content of the queue
- If dequeue, dequeue from the queue (only if the queue is not empty) and show the retrieved element.
- Show the current content of the queue */

// Juan Diego Acosta Ojeda ID: 185015

#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 5

int queue[QUEUESIZE];
int front = 0;
int rear = 0;
int numCurrentElements = 0;

int isEmpty() {
    return (numCurrentElements == 0);
}

int isFull() {
    return (numCurrentElements == QUEUESIZE);
}

// Enqueue
void enqueue(int val) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", val);
        return;
    }
    queue[rear] = val;
    rear = (rear + 1) % QUEUESIZE;  // mover rear circular
    numCurrentElements++;
    printf("Enqueued: %d\n", val);
}

// Dequeue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int val = queue[front];
    front = (front + 1) % QUEUESIZE;  // mover front circular
    numCurrentElements--;
    return val;
}

// Mostrar la cola
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue content: ");
    for (int i = 0; i < numCurrentElements; i++) {
        printf("%d ", queue[(front + i) % QUEUESIZE]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                displayQueue();
                break;

            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                displayQueue();
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
