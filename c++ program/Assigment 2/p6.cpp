/*WAP to define a class Date with properties int month; int day; int year;
overload the following operators.
5.1) + operator [a+b] (a is of date type and b is an integer), use the
assumption that all years all years have 360 days and
months 30 days.
5.2) – operator [a-b(same as above)]
5.3) = operator
5.4) <,<=,>,>=
5.5) ++,--[post and pre both]*/
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
