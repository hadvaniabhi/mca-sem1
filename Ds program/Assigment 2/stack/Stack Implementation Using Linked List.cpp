
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Value inserted\n");
}

void pop(void)
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted value: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void display(void)
{
    struct node *p = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
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

    while (top != NULL)
    {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

