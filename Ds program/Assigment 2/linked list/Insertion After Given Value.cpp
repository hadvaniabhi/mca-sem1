
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
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;

    if (start == NULL)
    {
        start = p;
        return;
    }

    temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}

void insert_after(int key, int x)
{
    struct node *temp = start, *p;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = temp->next;
    temp->next = p;
}

void display()
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(40);

    insert_after(20, 30);
    display();

    return 0;
}

