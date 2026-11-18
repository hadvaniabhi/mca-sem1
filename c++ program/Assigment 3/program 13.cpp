//Write a program that stores and displays the records of the customer from a
//file the following information for account of the customer is to be stored.
//Account no, account type, name, old balance, new balance, last payment,
//date of last payment. Also display the current account status by comparing
//current payment and previous balance. Also calculate the current balance by
//subtracting the current payment from the previous balance.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Customer
{
    int accno;
    string acctype, name, date;
    float oldbalance, newbalance, payment;

public:
    void getdata()
    {
        cout << "Enter Account Number: ";
        cin >> accno;

        cout << "Enter Account Type: ";
        cin >> acctype;

        cout << "Enter Customer Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter Old Balance: ";
        cin >> oldbalance;

        cout << "Enter Last Payment: ";
        cin >> payment;

        cout << "Enter Date of Last Payment (DD-MM-YYYY): ";
        cin >> date;

        newbalance = oldbalance - payment;
    }

    void display()
    {
        cout << "\n===== CUSTOMER ACCOUNT DETAILS =====\n";
        cout << "Account Number       : " << accno << endl;
        cout << "Account Type         : " << acctype << endl;
        cout << "Customer Name        : " << name << endl;
        cout << "Old Balance          : " << oldbalance << endl;
        cout << "Last Payment         : " << payment << endl;
        cout << "Date of Last Payment : " << date << endl;
        cout << "Current Balance      : " << newbalance << endl;

        if (payment >= oldbalance)
            cout << "Account Status       : Balance Cleared\n";
        else
            cout << "Account Status       : Payment Due\n";
    }

    void saveToFile()
    {
        ofstream fout("customer.txt", ios::app);

        fout << accno << '\n'
             << acctype << '\n'
             << name << '\n'
             << oldbalance << '\n'
             << payment << '\n'
             << date << '\n'
             << newbalance << '\n';

        fout.close();
    }

    void readFromFile()
    {
        ifstream fin("customer.txt");

        if (!fin)
        {
            cout << "File not found!\n";
            return;
        }

        while (fin >> accno)
        {
            fin >> acctype;
            fin.ignore(10000, '\n');
            getline(fin, name);
            fin >> oldbalance >> payment >> date >> newbalance;

            display();
        }

        fin.close();
    }
};

int main()
{
    Customer c;
    int choice;

    cout << "1. Enter and Save Customer Record\n";
    cout << "2. Display Customer Records from File\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        c.getdata();
        c.saveToFile();
        cout << "\nRecord saved successfully.\n";
        c.display();
    }
    else if (choice == 2)
    {
        c.readFromFile();
    }
    else
    {
        cout << "Invalid choice!\n";
    }

    return 0;
}

