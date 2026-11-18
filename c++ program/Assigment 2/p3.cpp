/*WAP to Overload the *, +,-, ==, ! = and = operators for the complex class.*/
#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    void getData()
    {
        cout << "Enter real and imaginary part: ";
        cin >> real >> imag;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }

    bool operator==(Complex c)
    {
        return (real == c.real && imag == c.imag);
    }

    bool operator!=(Complex c)
    {
        return (real != c.real || imag != c.imag);
    }

    Complex operator=(Complex c)
    {
        real = c.real;
        imag = c.imag;
        return *this;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1, c2, c3;

    cout << "Enter first complex number:" << endl;
    c1.getData();

    cout << "Enter second complex number:" << endl;
    c2.getData();

    c3 = c1 + c2;
    cout << "\nAddition: ";
    c3.display();

    c3 = c1 - c2;
    cout << "Subtraction: ";
    c3.display();

    c3 = c1 * c2;
    cout << "Multiplication: ";
    c3.display();

    if (c1 == c2)
        cout << "Both complex numbers are equal." << endl;
    else
        cout << "Both complex numbers are not equal." << endl;

    if (c1 != c2)
        cout << "Both complex numbers are different." << endl;
    else
        cout << "Both complex numbers are same." << endl;

    c3 = c1;
    cout << "Assignment: ";
    c3.display();

    return 0;
}
