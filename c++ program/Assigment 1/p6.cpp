/*Write a program to define a class called book. Write a program to read
information about 10 books and display books details in ascending order of
price in proper format.
*/
#include <iostream>
#include <string>
using namespace std;

class Book
{
    int id;
    string name;
    float price;

public:

    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;

        cout << "Enter Book Name: ";
        cin >> name;

        cout << "Enter Book Price: ";
        cin >> price;
    }

    float getPrice()
    {
        return price;
    }

    void display()
    {
        cout << id << "\t"
             << name << "\t"
             << price << endl;
    }
};

int main()
{
    Book b[10];

    for(int i = 0; i < 10; i++)
    {
        cout << "\nEnter details of Book "
             << i + 1 << endl;

        b[i].input();
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 10; j++)
        {
            if(b[i].getPrice() > b[j].getPrice())
            {
                Book temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    cout << "ID\tName\tPrice\n";

    for(int i = 0; i < 10; i++)
    {
        b[i].display();
    }

    return 0;
}

