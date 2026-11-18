//Create a base class called shape. Use this class to store two double type values
//that could be used to compute the area of figures. Derive three specific classes
//called triangle, rectangle and circle from the base shape. Add to the base class,
//a member function get_data( ) to initialize base class data members and
//another member function display_area( ) to compute and display the area of
//figures. Make display_area( ) as a virtual function and redefine this function in
//derived classes to suit their requirements. Using these three classes design a
//program that will accept dimensions of a triangle or rectangle interactively and
//store it in one array . After having read all the input display the area of all the
//figures whose area has been read in the program. Remember the two values
//given as input will be treated as lengths of two sides in the case of rectangle
//and as base and height in case of triangle. In case of circle only one value
//should be accepted which will be taken as the radius and the default value of
//the next parameter should be 0.

#include <iostream>
using namespace std;

class shape
{
protected:
    double a, b;

public:
    void get_data(double x, double y = 0)
    {
        a = x;
        b = y;
    }

    virtual void display_area()
    {
        cout << "Area = 0" << endl;
    }
};

class triangle : public shape
{
public:
    void display_area()
    {
        cout << "Area of Triangle = " << 0.5 * a * b << endl;
    }
};

class rectangle : public shape
{
public:
    void display_area()
    {
        cout << "Area of Rectangle = " << a * b << endl;
    }
};

class circle : public shape
{
public:
    void display_area()
    {
        cout << "Area of Circle = " << 3.14159 * a * a << endl;
    }
};

int main()
{
    shape *s[10];
    int n = 0, ch;
    double x, y;

    cout << "1. Triangle\n";
    cout << "2. Rectangle\n";
    cout << "3. Circle\n";
    cout << "Enter number of shapes: ";
    cin >> n;

    int count = n;
    n = 0;

    while (n < count && n < 10)
    {
        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter base and height: ";
            cin >> x >> y;
            triangle *t = new triangle;
            t->get_data(x, y);
            s[n++] = t;
        }
        else if (ch == 2)
        {
            cout << "Enter length and breadth: ";
            cin >> x >> y;
            rectangle *r = new rectangle;
            r->get_data(x, y);
            s[n++] = r;
        }
        else if (ch == 3)
        {
            cout << "Enter radius: ";
            cin >> x;
            circle *c = new circle;
            c->get_data(x);
            s[n++] = c;
        }
        else
        {
            cout << "Invalid choice!" << endl;
            count--;
        }
    }

    cout << "\nAreas of all shapes:\n";

    for (int i = 0; i < n; i++)
    {
        s[i]->display_area();
        delete s[i];
    }

    return 0;
}
