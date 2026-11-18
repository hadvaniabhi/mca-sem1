
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
    struct node *newnode, *p, *temp;
    int n, i;

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

    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = start;
        start = start->next;

        if (start != NULL)
            start->prev = NULL;

        free(temp);
    }

    printf("List: NULL <-> ");
    p = start;

    while (p != NULL)
    {
        printf("%d <-> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
    return 0;
}

