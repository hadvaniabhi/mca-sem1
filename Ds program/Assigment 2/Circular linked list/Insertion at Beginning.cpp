
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_beg(int x)
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

    newnode->next = start;
    temp->next = newnode;
    start = newnode;
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
    insert_beg(30);
    insert_beg(20);
    insert_beg(10);

    display();

    return 0;
}

