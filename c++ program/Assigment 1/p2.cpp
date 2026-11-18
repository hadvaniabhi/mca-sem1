/*Write a program to create class Num (int n1, int n2, int n3, int n4). Display
total and average of n1, n2, n3 and n4.*/
#include <iostream>
using namespace std;

class Num
{
    int n1, n2, n3, n4;

public:

    void input()
    {
        cout << "Enter n1: ";
        cin >> n1;

        cout << "Enter n2: ";
        cin >> n2;

        cout << "Enter n3: ";
        cin >> n3;

        cout << "Enter n4: ";
        cin >> n4;
    }

    int total()
    {
        return n1 + n2 + n3 + n4;
    }

    float average()
    {
        return total() / 4.0;
    }

    void display()
    {
        cout << "Total = " << total() << endl;
        cout << "Average = " << average() << endl;
    }
};

int main()
{
    Num obj;

    obj.input();
    obj.display();

    return 0;
}
