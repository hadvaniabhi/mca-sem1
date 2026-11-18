/*Write a program to create class employee with employee’s id, name and basic
salary. Calculate gross salary for each employee(HRA 20%, DA 30%, OA 10%).
Also count total number of employee records that are entered.*/
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int id;
    string name;
    float basicSalary;

    static int count;

public:

    Employee()
    {
        count++;
    }

    void input()
    {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    float grossSalary()
    {
        float hra, da, oa;

        hra = basicSalary * 20 / 100;
        da = basicSalary * 30 / 100;
        oa = basicSalary * 10 / 100;

        return basicSalary + hra + da + oa;
    }

    void display()
    {
        cout << "\nEmployee ID     : " << id;
        cout << "\nEmployee Name   : " << name;
        cout << "\nBasic Salary    : " << basicSalary;
        cout << "\nGross Salary    : " << grossSalary() << endl;
    }

    static int getCount()
    {
        return count;
    }
};

// Initialize static variable
int Employee::count = 0;


int main()
{
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    Employee e[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Employee "
             << i + 1 << endl;

        e[i].input();
    }

    cout << "\nEmployee Details\n";

    for (int i = 0; i < n; i++)
    {
        e[i].display();
    }

    cout << "\nTotal Employee Records = "
         << Employee::getCount() << endl;

    return 0;
}

