#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
// 2. Function to create a new Node
Node* createNode(int value) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Initialize the node with the given value
    newNode->data = value;
    newNode->left = NULL; // As per the 'Linked Representation' concept in your notes
    newNode->right = NULL;
    return newNode;
}

// 3. Function to insert a new value into the BST
// This follows the BST rule: (L < Root < R)
Node* insert(Node* root, int value) {
    // If the tree is empty, return a new node as the root
    if (root == NULL) {
        return createNode(value);
    }

    // Traverse the tree to find the correct insertion spot
    if (value < root->data) {
        // Go to the left subtree if the value is smaller
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // Go to the right subtree if the value is larger
        root->right = insert(root->right, value);
    }
    // If the value is equal, we typically do nothing (no duplicates allowed in a simple BST)

    // Return the (unchanged) root pointer
    return root;
}

// 4. Function to perform Inorder Traversal
// This traversal visits nodes in the order: Left -> Root -> Right
// It is used to print the BST elements in SORTED order.
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);    // 1. Recurse on the left subtree
        printf("%d ", root->data);      // 2. Visit the current node (print data)
        inorderTraversal(root->right);   // 3. Recurse on the right subtree
    }
}


// Main function to test the BST
int main() {
    Node* root = NULL;
    
    // Sample data to insert (similar to the data in your example: 85, 10, 78, 12, 54, 11, 9, 30)
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);

    printf("Inserting elements into the BST: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", elements[i]);
        root = insert(root, elements[i]);
    }
    printf("\n");

    printf("---BST Constructed---\n");
    // The structure will look like:
    //         50
    //       /    \
    //     30      70
    //    /  \    /  \
    //  20   40 60    80

    // Perform Inorder Traversal
    printf("Inorder Traversal (Sorted Order): ");
    inorderTraversal(root);
    printf("\n");
    
    // Note: In a production environment, you would also need a function to free the allocated memory.

    return 0;
}