
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

void delete_before(int key)
{
    struct node *temp, *p;

    if (start == NULL || start->next == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }

    if (start->next->data == key)
    {
        p = start;
        start = start->next;
        free(p);
        return;
    }

    temp = start;

    while (temp->next->next != NULL &&
           temp->next->next->data != key)
        temp = temp->next;

    if (temp->next->next == NULL)
    {
        printf("Value not found\n");
        return;
    }

    p = temp->next;
    temp->next = p->next;
    free(p);
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
    insert_end(40);

    delete_before(30);
    display();

    return 0;
}

