#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    printf("\n--- Circular Queue Implementation in C ---\n");

    while (1) {
        printf("\n\n====== MENU ======\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("==================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program. Goodbye! 👋\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void enqueue(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow! 🈵 Cannot insert element.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    }
    else {
        rear++;
    }

    queue[rear] = value;
    printf("✅ Inserted %d into the queue.", value);
}

void dequeue() {
    int val;

    if (front == -1) {
        printf("Queue Underflow! 텅 Cannot delete element.\n");
        return;
    }

    val = queue[front];
    printf("🗑️ Deleted element is: %d", val);

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == MAX_SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty. 텅\n");
        return;
    }

    printf("Queue elements are: [ ");
    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("]\n");
    printf("(Front is at index %d, Rear is at index %d)\n", front, rear);
}