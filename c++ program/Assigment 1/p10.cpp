/*Write a C++ program to create a class Wallet to manage the details and
transactions of digital wallets. The class should contain the following data
members: Wallet ID, Owner Name, Balance, and Transaction Count.
Also display following details:
Details of the wallet having the highest balance.
Details of the wallet having the highest number of transactions.
The total number of transactions performed by all wallets.
Validate followings:
Additional Conditions:
Initial balance must be at least ?500.
Deposit amount must be ?100 or more.
Withdrawal is allowed only when the resulting balance remains at least
?500.
Every successful deposit or withdrawal should increase the wallet's
transaction count and the static total transaction count.
Invalid deposits and withdrawals should not be counted as
transactions.*/
#include <iostream>
using namespace std;

class Wallet
{
private:
    int walletID;
    string ownerName;
    float balance;
    int transactionCount;

    static int totalTransactions;

public:

    void input()
    {
        cout << "\nEnter Wallet ID: ";
        cin >> walletID;

        cout << "Enter Owner Name: ";
        cin >> ownerName;

        do
        {
            cout << "Enter Initial Balance (Minimum 500): ";
            cin >> balance;

            if (balance < 500)
                cout << "Invalid! Initial balance must be at least 500.\n";

        } while (balance < 500);

        transactionCount = 0;
    }

    void deposit(float amount)
    {
        if (amount >= 100)
        {
            balance = balance + amount;
            transactionCount++;
            totalTransactions++;

            cout << "Deposit Successful.\n";
        }
        else
        {
            cout << "Invalid Deposit! Deposit must be 100 or more.\n";
        }
    }

    void withdraw(float amount)
    {
        if (balance - amount >= 500)
        {
            balance = balance - amount;
            transactionCount++;
            totalTransactions++;

            cout << "Withdrawal Successful.\n";
        }
        else
        {
            cout << "Invalid Withdrawal! Balance must remain at least 500.\n";
        }
    }

    void display()
    {
        cout << "\nWallet ID        : " << walletID;
        cout << "\nOwner Name       : " << ownerName;
        cout << "\nBalance          : " << balance;
        cout << "\nTransaction Count: " << transactionCount << endl;
    }

    float getBalance()
    {
        return balance;
    }

    int getTransactionCount()
    {
        return transactionCount;
    }

    static void displayTotalTransactions()
    {
        cout << "\nTotal Transactions of All Wallets: "
             << totalTransactions << endl;
    }
};

int Wallet::totalTransactions = 0;


int main()
{
    Wallet w[10];

    float amount;

    for (int i = 0; i < 10; i++)
    {
        cout << "\n========== Wallet " << i + 1 << " ==========";

        w[i].input();

        cout << "Enter Deposit Amount: ";
        cin >> amount;
        w[i].deposit(amount);

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;
        w[i].withdraw(amount);
    }

    int highestBalanceIndex = 0;

    for (int i = 1; i < 10; i++)
    {
        if (w[i].getBalance() > w[highestBalanceIndex].getBalance())
        {
            highestBalanceIndex = i;
        }
    }

    int highestTransactionIndex = 0;

    for (int i = 1; i < 10; i++)
    {
        if (w[i].getTransactionCount() >
            w[highestTransactionIndex].getTransactionCount())
        {
            highestTransactionIndex = i;
        }
    }

    cout << "\n\n========================================";
    cout << "\nWallet Having Highest Balance";
    cout << "\n========================================";

    w[highestBalanceIndex].display();


    cout << "\n\n========================================";
    cout << "\nWallet Having Highest Transactions";
    cout << "\n========================================";

    w[highestTransactionIndex].display();


    Wallet::displayTotalTransactions();

    return 0;
}

