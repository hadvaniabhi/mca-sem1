/*Write a program to create class Date (int day, int month, int year). Read a
value as day from user to display new date after adding the value to day in
Date.*/
#include <iostream>
using namespace std;

class Date
{
    int day, month, year;

public:

    void input()
    {
        cout << "Enter day: ";
        cin >> day;

        cout << "Enter month: ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;
    }

    void addDays(int x)
    {
        int daysInMonth[] =
        {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        day = day + x;

        while (day > daysInMonth[month - 1])
        {
            day = day - daysInMonth[month - 1];
            month++;

            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }

    void display()
    {
        cout << "New Date = "
             << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date d;
    int x;

    d.input();

    cout << "Enter days to add: ";
    cin >> x;

    d.addDays(x);

    d.display();

    return 0;
}

