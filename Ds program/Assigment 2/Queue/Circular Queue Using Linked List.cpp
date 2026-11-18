
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;

    if (front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        newnode->next = front;
        rear->next = newnode;
        rear = newnode;
    }

    printf("Value inserted\n");
}

void dequeue(void)
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Circular Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted value: %d\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void display(void)
{
    struct node *p;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    p = front;

    printf("Circular Queue: ");

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != front);

    printf("\n");
}

int main(void)
{
    int choice, value;

    do
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    while (front != NULL)
        dequeue();

    return 0;
}

