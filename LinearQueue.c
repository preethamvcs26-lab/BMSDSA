#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int num;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &num);

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = num;
        printf("Element inserted successfully\n");
    }
}

void delete()
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        val = queue[front];
        printf("Deleted element = %d\n", val);
        front++;
    }
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
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

    return 0;
}
