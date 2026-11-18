/*WAP to define a class Time with properties int hour; int minute; int second;
overload the following operators.
6.1) + operator [a+b] (a is of time type and b is an integer)
6.2) – operator [a-b(same as above)]
6.3) = operator
6.4) <,<=,>,>=
6.5) ++,--[post and pre both]*/
#include <iostream>
using namespace std;

class Time
{
    int hour, minute, second;

public:
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    Time operator+(int n)
    {
        Time temp = *this;

        temp.second += n;

        while (temp.second >= 60)
        {
            temp.second -= 60;
            temp.minute++;
        }

        while (temp.minute >= 60)
        {
            temp.minute -= 60;
            temp.hour++;
        }

        while (temp.hour >= 24)
        {
            temp.hour -= 24;
        }

        return temp;
    }

    Time operator-(int n)
    {
        Time temp = *this;

        temp.second -= n;

        while (temp.second < 0)
        {
            temp.second += 60;
            temp.minute--;
        }

        while (temp.minute < 0)
        {
            temp.minute += 60;
            temp.hour--;
        }

        while (temp.hour < 0)
        {
            temp.hour += 24;
        }

        return temp;
    }

    Time operator=(Time t)
    {
        hour = t.hour;
        minute = t.minute;
        second = t.second;

        return *this;
    }

    bool operator<(Time t)
    {
        if (hour != t.hour)
            return hour < t.hour;

        if (minute != t.minute)
            return minute < t.minute;

        return second < t.second;
    }

    bool operator<=(Time t)
    {
        return (*this < t) ||
               (hour == t.hour && minute == t.minute && second == t.second);
    }

    bool operator>(Time t)
    {
        return !(*this <= t);
    }

    bool operator>=(Time t)
    {
        return !(*this < t);
    }

    Time operator++()
    {
        *this = *this + 1;
        return *this;
    }

    Time operator++(int)
    {
        Time temp = *this;
        *this = *this + 1;
        return temp;
    }

    Time operator--()
    {
        *this = *this - 1;
        return *this;
    }

    Time operator--(int)
    {
        Time temp = *this;
        *this = *this - 1;
        return temp;
    }

    void display()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main()
{
    Time t1(10, 20, 50);
    Time t2, t3;

    cout << "Original Time: ";
    t1.display();

    t2 = t1 + 20;
    cout << "After adding 20 seconds: ";
    t2.display();

    t3 = t1 - 30;
    cout << "After subtracting 30 seconds: ";
    t3.display();

    t2 = t1;
    cout << "After assignment: ";
    t2.display();

    if (t1 < t2)
        cout << "t1 is less than t2" << endl;

    if (t1 <= t2)
        cout << "t1 is less than or equal to t2" << endl;

    if (t1 > t2)
        cout << "t1 is greater than t2" << endl;

    if (t1 >= t2)
        cout << "t1 is greater than or equal to t2" << endl;

    ++t1;
    cout << "After pre-increment: ";
    t1.display();

    t1++;
    cout << "After post-increment: ";
    t1.display();

    --t1;
    cout << "After pre-decrement: ";
    t1.display();

    t1--;
    cout << "After post-decrement: ";
    t1.display();

    return 0;
}

