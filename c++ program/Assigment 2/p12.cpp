/*Write an object-oriented program to implement a generic Number Class that
can accept either int or float data type and perform basic calculation like +,-,/
and *.*/
#include <iostream>
using namespace std;

template <class T>
class Number
{
    T num1, num2;

public:
    Number(T a, T b)
    {
        num1 = a;
        num2 = b;
    }

    T add()
    {
        return num1 + num2;
    }

    T subtract()
    {
        return num1 - num2;
    }

    T multiply()
    {
        return num1 * num2;
    }

    T divide()
    {
        return num1 / num2;
    }
};

int main()
{
    Number<int> n1(20, 10);

    cout << "Integer Numbers:" << endl;
    cout << "Addition = " << n1.add() << endl;
    cout << "Subtraction = " << n1.subtract() << endl;
    cout << "Multiplication = " << n1.multiply() << endl;
    cout << "Division = " << n1.divide() << endl;

    Number<float> n2(20.5, 10.5);

    cout << "\nFloat Numbers:" << endl;
    cout << "Addition = " << n2.add() << endl;
    cout << "Subtraction = " << n2.subtract() << endl;
    cout << "Multiplication = " << n2.multiply() << endl;
    cout << "Division = " << n2.divide() << endl;

    return 0;
}
