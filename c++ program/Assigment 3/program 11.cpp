//A file contains name and phone numbers. Name contains only one word and
//names and telephone numbers are separated by white spaces. Write a
//program which will include a menu driven functionality for the above file
//(a) Display 2 column output with names left justified and phone numbers
//right justified.
//Name Phone
//Ram 56789125
//Shyam 34565432
//Rahim 23456789
//Joseph 67213148
//
//(b) Determine the telephone number of a person.
//(c) Determine the name if the telephone number is known.
//(d) Update the telephone number.
//(e) Prefix all the telephone numbers by 2.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class PhoneBook
{
    string name, phone;

public:
    void display()
    {
        ifstream fin("phone.txt");

        if (!fin)
        {
            cout << "File not found!" << endl;
            return;
        }

        cout << left << setw(20) << "Name"
             << right << setw(15) << "Phone" << endl;

        cout << "-----------------------------------\n";

        while (fin >> name >> phone)
        {
            cout << left << setw(20) << name
                 << right << setw(15) << phone << endl;
        }

        fin.close();
    }

    void findPhone()
    {
        string searchName;
        bool found = false;

        cout << "Enter name: ";
        cin >> searchName;

        ifstream fin("phone.txt");

        while (fin >> name >> phone)
        {
            if (name == searchName)
            {
                cout << "Phone Number: " << phone << endl;
                found = true;
                break;
            }
        }

        fin.close();

        if (!found)
            cout << "Name not found!" << endl;
    }

    void findName()
    {
        string searchPhone;
        bool found = false;

        cout << "Enter phone number: ";
        cin >> searchPhone;

        ifstream fin("phone.txt");

        while (fin >> name >> phone)
        {
            if (phone == searchPhone)
            {
                cout << "Name: " << name << endl;
                found = true;
                break;
            }
        }

        fin.close();

        if (!found)
            cout << "Phone number not found!" << endl;
    }

    void updatePhone()
    {
        string searchName, newPhone;
        bool found = false;

        cout << "Enter name to update: ";
        cin >> searchName;

        ifstream fin("phone.txt");
        ofstream temp("temp.txt");

        while (fin >> name >> phone)
        {
            if (name == searchName)
            {
                cout << "Enter new phone number: ";
                cin >> newPhone;
                phone = newPhone;
                found = true;
            }

            temp << name << " " << phone << endl;
        }

        fin.close();
        temp.close();

        if (found)
        {
            remove("phone.txt");
            rename("temp.txt", "phone.txt");
            cout << "Phone number updated successfully.\n";
        }
        else
        {
            remove("temp.txt");
            cout << "Name not found!\n";
        }
    }

    void prefixNumbers()
    {
        ifstream fin("phone.txt");
        ofstream temp("temp.txt");

        while (fin >> name >> phone)
        {
            phone = "2" + phone;
            temp << name << " " << phone << endl;
        }

        fin.close();
        temp.close();

        remove("phone.txt");
        rename("temp.txt", "phone.txt");

        cout << "Prefix 2 added to all phone numbers.\n";
    }
};

int main()
{
    PhoneBook p;
    int choice;

    do
    {
        cout << "\n----- PHONE BOOK MENU -----\n";
        cout << "1. Display all records\n";
        cout << "2. Find phone number by name\n";
        cout << "3. Find name by phone number\n";
        cout << "4. Update phone number\n";
        cout << "5. Prefix all numbers by 2\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p.display();
            break;

        case 2:
            p.findPhone();
            break;

        case 3:
            p.findName();
            break;

        case 4:
            p.updatePhone();
            break;

        case 5:
            p.prefixNumbers();
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

