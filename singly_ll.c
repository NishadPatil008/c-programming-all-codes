#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_at_start(int value);
void insert_at_end(int value);
void insert_at_pos(int value, int pos);
void delete_at_start();
void delete_at_end();
void delete_at_pos(int pos);
void display();
void reverse();
void count();

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Display List\n");
        printf("8. Reverse List\n");
        printf("9. Count Nodes\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_at_start(value);break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_at_end(value);break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insert_at_pos(value, pos);break;
            case 4:
                delete_at_start();break;
            case 5:
                delete_at_end();break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_pos(pos);break;
            case 7:
                display();break;
            case 8:
                reverse();break;
            case 9:
                count();break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void insert_at_start(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insert_at_end(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void insert_at_pos(int value, int pos) {
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void delete_at_start() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}
void delete_at_pos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct node *delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void reverse() {
    struct node *prevNode = NULL;
    struct node *currentNode = head;
    struct node *nextNode = NULL;
    if (head == NULL) {
        printf("List is empty, cannot reverse.\n");
        return;
    }
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    printf("List reversed successfully.\n");
}
void count() {
    int nodeCount = 0;
    struct node *temp = head;
    while (temp != NULL) {
        nodeCount++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", nodeCount);
}