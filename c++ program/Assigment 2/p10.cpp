/*Write a template function to make sum of two numbers.*/
#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Sum = " << sum(a, b);

    return 0;
}
