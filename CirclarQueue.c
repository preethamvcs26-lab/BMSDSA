#include <stdio.h>
#define max 3

int q[max];
int front = -1;
int rear = -1;

void insert()
{
    int num;

    if ((rear + 1) % max == front)
    {
        printf("Queue overflow");
    }

    printf("Enter the element: ");
    scanf("%d", &num);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % max;
    }

    q[rear] = num;
}

void delete_element()
{
    int value;

    if (front == -1)
    {
        printf("Queue is underflow");
        return;
    }

    value = q[front];

    printf("Deleted element = %d", value);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }

    printf("Queue elements are: ");

    for (i = front; ; i = (i + 1) % max)
    {
        printf("%d ", q[i]);

        if (i == rear)
            break;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 0;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_element();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
