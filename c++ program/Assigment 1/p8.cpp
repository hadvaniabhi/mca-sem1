/*Define a class to represent a bank account. Include the following members :
DATA MEMBERS MEMBER FUNCTIONS
------------------------ ------------------------------
Name of depositor (1) To assign initial values
Account Number (2) To Deposit the amount
Type of Account (3) To withdraw an amount after checking the
Balance amount in account (4) To display name and balance
Write C++ program to handle 10 customers.*/
#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNumber;
    string accountType;
    float balance;

public:

    void initialize(string n, int accNo, string type, float bal)
    {
        name = n;
        accountNumber = accNo;
        accountType = type;
        balance = bal;
    }

    void deposit(float amount)
    {
        balance = balance + amount;
        cout << "Amount Deposited Successfully.\n";
    }

    void withdraw(float amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount Withdrawn Successfully.\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    void display()
    {
        cout << "\nName    : " << name;
        cout << "\nBalance : " << balance << endl;
    }
};

int main()
{
    BankAccount customer[10];

    string name, type;
    int accountNumber;
    float balance, amount;

    for (int i = 0; i < 10; i++)
    {
        cout << "\nCustomer " << i + 1;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Type: ";
        cin >> type;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        customer[i].initialize(name, accountNumber, type, balance);

        cout << "Enter Deposit Amount: ";
        cin >> amount;
        customer[i].deposit(amount);

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;
        customer[i].withdraw(amount);
    }

    cout << "\n\n Customer Details";

    for (int i = 0; i < 10; i++)
    {
        cout << "\nCustomer " << i + 1 << ":";
        customer[i].display();
    }

    return 0;
}

