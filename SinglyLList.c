
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create the linked list
void createList(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int i, value;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nSingly Linked List:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at the beginning
void insertBeginning(struct Node **head, int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at a specified position
void insertMiddle(struct Node **head, int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
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
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node from the beginning
void deleteBeginning(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty. Deletion not possible!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete a node from a specified position
void deletePosition(struct Node **head, int position) {
    struct Node *temp, *prev;
    int i;

    if (*head == NULL) {
        printf("List is empty. Deletion not possible!\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        deleteBeginning(head);
        return;
    }

    temp = *head;
    prev = NULL;

    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete a node from the end
void deleteEnd(struct Node **head) {
    struct Node *temp, *prev;

    if (*head == NULL) {
        printf("List is empty. Deletion not possible!\n");
        return;
    }

    if ((*head)->next == NULL) {
        temp = *head;
        *head = NULL;

        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    temp = *head;
    prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Main function
int main() {
    struct Node *head = NULL;
    int n, choice, value, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    createList(&head, n);

    printf("\nOriginal linked list:\n");
    display(head);

    do {
        printf("\n\n===== SINGLY LINKED LIST =====");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at Specified Position");
        printf("\n3. Insert at End");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from Specified Position");
        printf("\n6. Delete from End");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertMiddle(&head, value, position);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 4:
                deleteBeginning(&head);
                break;

            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;

            case 6:
                deleteEnd(&head);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    // Release remaining nodes
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
