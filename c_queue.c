#include <stdio.h>

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
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
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}

void enqueue(int value) {
    if ((front == 0 && rear == 9) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == 9 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == 9) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Empty\n");
        return;
    }

    printf("Queue: ");
    if (rear >= front) {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (i = front; i < 10; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}