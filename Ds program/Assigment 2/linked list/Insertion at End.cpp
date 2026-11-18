
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *start = NULL;

void insertEnd(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;

    if (start == NULL)
    {
        start = p;
        return;
    }

    Node *temp = start;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}

void display()
{
    Node *temp = start;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();
    return 0;
}

