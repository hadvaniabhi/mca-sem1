
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

int main(void)
{
    struct node *newnode, *p, *q;
    int n, i, key, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (start == NULL)
            start = newnode;
        else
        {
            p = start;
            while (p->next != NULL)
                p = p->next;

            p->next = newnode;
            newnode->prev = p;
        }
    }

    printf("Enter node value before which to insert: ");
    scanf("%d", &key);
    printf("Enter new value: ");
    scanf("%d", &value);

    p = start;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL)
    {
        printf("Node not found\n");
    }
    else
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = p;
        newnode->prev = p->prev;

        if (p->prev != NULL)
            p->prev->next = newnode;
        else
            start = newnode;

        p->prev = newnode;
    }

    printf("List: NULL <-> ");
    q = start;

    while (q != NULL)
    {
        printf("%d <-> ", q->data);
        q = q->next;
    }

    printf("NULL\n");
    return 0;
}

