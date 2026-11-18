
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_sorted(int x)
{
    struct node *p, *temp;

    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;

    if (start == NULL || x <= start->data)
    {
        p->next = start;
        start = p;
        return;
    }

    temp = start;

    while (temp->next != NULL &&
           temp->next->data < x)
        temp = temp->next;

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
    insert_sorted(10);
    insert_sorted(30);
    insert_sorted(20);
    insert_sorted(40);
    insert_sorted(5);

    display();
    return 0;
}

