#include <stdio.h>
int stack[5];
int top=-1;
void push();
void pop();
void display();
int main() {
    int choice, val;
    while (1) {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Select your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter value to PUSH: ");
            scanf("%d", &val);
            push(val);
            break;

            case 2:
            pop();
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
void push(int val) {
    if (top==4)
        printf("Stack Overflow\n");
    else {
        stack[++top]=val;
        printf("PUSHED %d\n", val);
    }
}
void pop() {
    if (top==-1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}
void display() {
    if (top==-1)
        printf("Stack is empty\n");
    else {
        printf("Current Stack: ");
        for (int i=top;i>=0;i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}