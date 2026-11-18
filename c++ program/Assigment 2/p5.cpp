/*WAP to define a matrix class and overload the * operator to multiply a number
with matrix (Example: 5*Matrix should be possible).*/
#include <iostream>
using namespace std;

class Stack
{
    int arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == 4)
            cout << "Stack Overflow" << endl;
        else
            arr[++top] = value;
    }

    void display()
    {
        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    void* operator new(size_t size)
    {
        cout << "Overloaded new operator called" << endl;
        void* p = ::new char[size];
        return p;
    }

    void operator delete(void* p)
    {
        cout << "Overloaded delete operator called" << endl;
        ::delete[] (char*)p;
    }
};

int main()
{
    Stack *s;

    s = new Stack;

    s->push(10);
    s->push(20);
    s->push(30);

    s->display();

    delete s;

    return 0;
}
