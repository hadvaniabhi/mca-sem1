
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    queue[++rear] = value;
    printf("Value inserted\n");
}

void dequeue(void)
{
    if (front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted value: %d\n", queue[front++]);

    if (front > rear)
    {
        front = 0;
        rear = -1;
    }
}

void display(void)
{
    int i;

    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

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

    return 0;
}

