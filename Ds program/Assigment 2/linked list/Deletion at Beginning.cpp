
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

void delete_beg()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = start;
    start = start->next;
    free(temp);
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
    insert_end(30);

    delete_beg();
    display();

    return 0;
}

