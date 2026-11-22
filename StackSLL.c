#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Initialize top
struct Node *top = NULL;

// PUSH: Insert element
void push(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
}

// POP: Delete element
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow! Stack is empty\n");
        return;
    }

    temp = top;

    printf("Popped element: %d\n", temp->data);

    top = top->next;

    free(temp);
}

// PEEK: Display top element
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element = %d\n", top->data);
}

// DISPLAY: Display stack
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (TOP to BOTTOM):\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice, value;

    do {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
