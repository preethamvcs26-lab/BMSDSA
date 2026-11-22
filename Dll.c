#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Insert at beginning
void insertBeginning(struct Node **head, int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at specified position
void insertPosition(struct Node **head, int value, int position) {
    struct Node *temp, *newNode;
    int i;

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *head;

    if (temp->next == NULL) {
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at specified position
void deletePosition(struct Node **head, int position) {
    struct Node *temp = *head;
    int i;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        deleteBeginning(head);
        return;
    }

    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Search an element
void searchNode(struct Node *head, int value) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d\n",
                   value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("%d not found in the list\n", value);
}

// Display forward and backward
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Forward Traversal: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward Traversal: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// Free all nodes
void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node *head = NULL;
    int choice, value, position;

    do {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(&head, value, position);
                break;

            case 4:
                deleteBeginning(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &value);
                searchNode(head, value);
                break;

            case 8:
                display(head);
                break;

            case 9:
                freeList(&head);
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 9);

    return 0;
}
