/*Write a program to create class Time (int h, int m). Read a value as minutes
from user to display new time after adding the value to minutes in Time.*/
#include <iostream>
using namespace std;

class Time
{
    int h, m;

public:

    void input()
    {
        cout << "Enter hours: ";
        cin >> h;

        cout << "Enter minutes: ";
        cin >> m;
    }

    void addMinutes(int x)
    {
        m = m + x;

        h = h + m / 60;
        m = m % 60;
    }

    void display()
    {
        cout << "New Time = " << h << " hours "
             << m << " minutes" << endl;
    }
};

int main()
{
    Time t;
    int x;

    t.input();

    cout << "Enter minutes to add: ";
    cin >> x;

    t.addMinutes(x);

    t.display();

    return 0;
}

