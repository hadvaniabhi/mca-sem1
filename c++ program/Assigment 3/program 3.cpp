//ABC publishing company markets both book and audio cassette versions of its
//work. Create a class called publication that stores the title (a string) and price(
//type float) of a publication. From this class derive two classes : book , which
//adds a page count (type int); and tape, which adds playing time in minutes
//(type float). Write a main program that reads both book and tape information in
//one array. When the user has finished entering data for all books and tapes,
//displays the resulting data for all the books and tapes entered. Also count no of
//book and cassette entries in the array using runtime identification feature of
//C++.

#include <iostream>
#include <string>
using namespace std;

class publication
{
protected:
    string title;
    float price;

public:
    virtual void getdata()
    {
        cout << "Enter title: ";
        cin >> ws;
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
    }

    virtual void display()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~publication() {}
};

class book : public publication
{
    int pages;

public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> pages;
    }

    void display()
    {
        cout << "\nBook Details\n";
        publication::display();
        cout << "Pages: " << pages << endl;
    }
};

class tape : public publication
{
    float time;

public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter playing time in minutes: ";
        cin >> time;
    }

    void display()
    {
        cout << "\nTape Details\n";
        publication::display();
        cout << "Playing Time: " << time << " minutes" << endl;
    }
};

int main()
{
    publication *p[10];
    int n, choice;
    int books = 0, tapes = 0;

    cout << "Enter number of publications (max 10): ";
    cin >> n;

    if (n < 1 || n > 10)
    {
        cout << "Invalid number of publications.";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n1. Book\n2. Tape\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            p[i] = new book;
            books++;
        }
        else if (choice == 2)
        {
            p[i] = new tape;
            tapes++;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
            i--;
            continue;
        }

        p[i]->getdata();
    }

    cout << "\n===== Publication Details =====\n";

    for (int i = 0; i < n; i++)
    {
        p[i]->display();
    }

    cout << "\nTotal Books: " << books << endl;
    cout << "Total Cassettes: " << tapes << endl;

    for (int i = 0; i < n; i++)
    {
        delete p[i];
    }

    return 0;
}

