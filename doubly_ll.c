#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void insert_at_start();
void insert_at_end();
void insert_at_pos();
void delete_at_start();
void delete_at_end();
void delete_at_pos();
void display();
void reverse();
void count();
int main() {
    int choice;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Display List\n");
        printf("8. Reverse Display\n");
        printf("9. Count Nodes\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_at_start(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_pos(); break;
            case 4: delete_at_start(); break;
            case 5: delete_at_end(); break;
            case 6: delete_at_pos(); break;
            case 7: display(); break;
            case 8: reverse(); break;
            case 9: count(); break;
            case 10: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }}
    return 0;
}
void insert_at_start() {
    int value;
    printf("Enter value to insert at start: ");
    scanf("%d", &value);
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}
void insert_at_end() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}
void insert_at_pos() {
    int value, pos;
    printf("Enter value and position to insert: ");
    scanf("%d %d", &value, &pos);
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (pos == 1) {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }
    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}
void delete_at_start() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("Deleted node from start.\n");
}
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
    printf("Deleted node from end.\n");
}
void delete_at_pos() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Deleted node at position 1.\n");
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted node at position %d.\n", pos);
}
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void reverse() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Reversed List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
void count() {
    int count_val = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count_val++;
        temp = temp->next;
    }
    printf("Total number of nodes in the list: %d\n", count_val);
}