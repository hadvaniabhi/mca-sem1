
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *start = NULL;

void insertBeg(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = start;
    start = p;
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
    insertBeg(30);
    insertBeg(20);
    insertBeg(10);

    display();
    return 0;
}

