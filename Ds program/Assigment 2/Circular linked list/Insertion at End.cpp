
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_end(int x)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
        return;
    }

    temp = start;

    while (temp->next != start)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = start;
}

void display()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("List is empty");
        return;
    }

    temp = start;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != start);

    printf("(back to start)\n");
}

int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(30);

    display();

    return 0;
}

