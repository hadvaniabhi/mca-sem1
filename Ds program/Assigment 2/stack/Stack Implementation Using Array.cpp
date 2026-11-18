
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
        printf("Value inserted\n");
    }
}

void pop(void)
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("Deleted value: %d\n", stack[top]);
        top--;
    }
}

void display(void)
{
    int i;

    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack: ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main(void)
{
    int choice, value;

    do
    {
        printf("\n1.Push  2.Pop  3.Display  0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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

