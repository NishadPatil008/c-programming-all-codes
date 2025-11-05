#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
struct node* create(int data);
void insert();
void in_order(struct node *t);
void pre_order(struct node *t);
void post_order(struct node *t);
void search_element();
int main() {
    int choice;
    while (1) {
        printf("\n1.Insert  2.Inorder  3.Preorder  4.Postorder  5.Search  6.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                insert(); break;
            case 2: 
                in_order(root); 
                printf("\n"); break;
            case 3: 
                pre_order(root); 
                printf("\n"); break;
            case 4: 
                post_order(root); 
                printf("\n"); break;
            case 5: 
                search_element(); break;
            case 6: 
                return 0;
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}
struct node* create(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
void insert() {
    int data;
    scanf("%d", &data);
    struct node *newnode = create(data);
    if (root == NULL) {
        root = newnode;
        return;
    }
    struct node *temp = root;
    while (1) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = newnode;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = newnode;
                break;
            }
            temp = temp->right;
        }
    }
}
void in_order(struct node *t) {
    if (t) {
        in_order(t->left);
        printf("%d ", t->data);
        in_order(t->right);
    }
}
void pre_order(struct node *t) {
    if (t) {
        printf("%d ", t->data);
        pre_order(t->left);
        pre_order(t->right);
    }
}
void post_order(struct node *t) {
    if (t) {
        post_order(t->left);
        post_order(t->right);
        printf("%d ", t->data);
    }
}
void search_element() {
    int key;
    scanf("%d", &key);
    struct node *temp = root;
    while (temp) {
        if (key == temp->data) {
            printf("Found\n");
            return;
        } else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Not found\n");
}