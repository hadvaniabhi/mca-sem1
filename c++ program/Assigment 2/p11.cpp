/*Write a program to generate templates function for swapping values of
variables and show its use with integer, float and character type of data as
input.*/
#include <iostream>
using namespace std;

template <class T>
void swapValues(T &a, T &b)
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    float x = 10.5, y = 20.5;
    char p = 'A', q = 'B';

    cout << "Before swapping:" << endl;
    cout << "Integer: " << a << " " << b << endl;
    cout << "Float: " << x << " " << y << endl;
    cout << "Character: " << p << " " << q << endl;

    swapValues(a, b);
    swapValues(x, y);
    swapValues(p, q);

    cout << "\nAfter swapping:" << endl;
    cout << "Integer: " << a << " " << b << endl;
    cout << "Float: " << x << " " << y << endl;
    cout << "Character: " << p << " " << q << endl;

    return 0;
}
