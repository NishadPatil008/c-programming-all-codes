#include <stdio.h>
int queue[5];
int front = -1, rear = -1;

void insert(int val);
void delete();
void display();

int main() {
    int choice, val;
    while (1) {
        printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
        printf("Select your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to INSERT: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void insert(int val) {
    if (rear == 4)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        printf("Inserted %d\n", val);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        front = rear = -1;
    } else {
        printf("Deleted %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}