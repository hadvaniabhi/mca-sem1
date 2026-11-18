//Use an Employee Class to write records of employee to a file. Include a menu
//that will allow the user to select any of the following features
//a. Add a new record.
//b. Modify an existing record.
//c. Retrieve and display an entire record for a given name.
//d. Generate a complete list of all names, addresses and telephone numbers.
//e. End of the computation.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class Employee
{
    int id;
    string name, address, phone;

public:
    void getdata()
    {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Telephone Number: ";
        cin >> phone;
    }

    void display()
    {
        cout << "\nEmployee ID: " << id;
        cout << "\nName: " << name;
        cout << "\nAddress: " << address;
        cout << "\nTelephone: " << phone << endl;
    }

    void addRecord()
    {
        Employee e;
        ofstream fout("employee.txt", ios::app);

        e.getdata();

        fout << e.id << '\n'
             << e.name << '\n'
             << e.address << '\n'
             << e.phone << '\n';

        fout.close();
        cout << "Record added successfully.\n";
    }

    void modifyRecord()
    {
        int searchID;
        bool found = false;
        Employee e;

        cout << "Enter Employee ID to modify: ";
        cin >> searchID;

        ifstream fin("employee.txt");
        ofstream temp("temp.txt");

        while (fin >> e.id)
        {
            fin.ignore(10000, '\n');
            getline(fin, e.name);
            getline(fin, e.address);
            getline(fin, e.phone);

            if (e.id == searchID)
            {
                cout << "Enter updated details:\n";
                e.getdata();
                found = true;
            }

            temp << e.id << '\n'
                 << e.name << '\n'
                 << e.address << '\n'
                 << e.phone << '\n';
        }

        fin.close();
        temp.close();

        if (found)
        {
            remove("employee.txt");
            rename("temp.txt", "employee.txt");
            cout << "Record modified successfully.\n";
        }
        else
        {
            remove("temp.txt");
            cout << "Employee not found.\n";
        }
    }

    void searchRecord()
    {
        string searchName;
        bool found = false;
        Employee e;

        cout << "Enter employee name: ";
        cin >> ws;
        getline(cin, searchName);

        ifstream fin("employee.txt");

        while (fin >> e.id)
        {
            fin.ignore(10000, '\n');
            getline(fin, e.name);
            getline(fin, e.address);
            getline(fin, e.phone);

            if (e.name == searchName)
            {
                e.display();
                found = true;
            }
        }

        fin.close();

        if (!found)
            cout << "Employee not found.\n";
    }

    void displayAll()
    {
        Employee e;
        ifstream fin("employee.txt");

        if (!fin)
        {
            cout << "No records found.\n";
            return;
        }

        cout << "\n===== EMPLOYEE LIST =====\n";

        while (fin >> e.id)
        {
            fin.ignore(10000, '\n');
            getline(fin, e.name);
            getline(fin, e.address);
            getline(fin, e.phone);

            e.display();
            cout << "----------------------\n";
        }

        fin.close();
    }
};

int main()
{
    Employee e;
    int choice;

    do
    {
        cout << "\n===== EMPLOYEE MENU =====\n";
        cout << "1. Add New Record\n";
        cout << "2. Modify Existing Record\n";
        cout << "3. Retrieve Record by Name\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            e.addRecord();
            break;
        case 2:
            e.modifyRecord();
            break;
        case 3:
            e.searchRecord();
            break;
        case 4:
            e.displayAll();
            break;
        case 5:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
