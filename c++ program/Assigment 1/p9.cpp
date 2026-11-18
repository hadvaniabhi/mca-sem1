/*Write a program to create class ‘Search’ having data members (int a[ ], x) and
define member functions as void input(), void output(), void search(int position),
void add(int value) to display result.*/
#include <iostream>
using namespace std;

class Search
{
private:
    int a[10];
    int x;

public:

    void input()
    {
        cout << "Enter 10 elements:\n";

        for (int i = 0; i < 10; i++)
        {
            cin >> a[i];
        }

        cout << "Enter value to search: ";
        cin >> x;
    }

    void output()
    {
        cout << "\nArray elements are:\n";

        for (int i = 0; i < 10; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    void search(int position)
    {
        if (position >= 0 && position < 10)
        {
            cout << "Value at position " << position
                 << " = " << a[position] << endl;
        }
        else
        {
            cout << "Invalid position!" << endl;
        }
    }

    void add(int value)
    {
        x = x + value;

        cout << "After adding " << value
             << ", x = " << x << endl;
    }
};

int main()
{
    Search s;
    int position, value;

    s.input();

    s.output();

    cout << "\nEnter position to search (0 to 9): ";
    cin >> position;

    s.search(position);

    cout << "\nEnter value to add in x: ";
    cin >> value;

    s.add(value);

    return 0;
}

