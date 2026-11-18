/*An educational institution wishes to maintain a database of its employees.
The database is divided into a number of classes that you may identify. You
have to take minimum information required for each class. Specify all the
classes and define function to create the database and retrieve individual
information as and when required. Write parameterized constructor for each
class in the hierarchy.*/
#include <iostream>
using namespace std;

class Person {
protected:
    char name[30];
    int age;

public:
    void getPersonData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPersonData() {
        cout << "Name            : " << name << endl;
        cout << "Age             : " << age << endl;
    }
};

class Employee : public Person {
protected:
    int emp_id;
    float salary;

public:
    void getEmployeeData() {
        getPersonData(); 
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayEmployeeData() {
        displayPersonData();
        cout << "Employee ID     : " << emp_id << endl;
        cout << "Salary          : " << salary << endl;
    }
};

class Department : public Employee {
private:
    char dept_name[30];
    char location[30];

public:
    void getDepartmentData() {
        getEmployeeData(); 
        cout << "Enter Department Name: ";
        cin >> dept_name;
        cout << "Enter Location: ";
        cin >> location;
    }

    void displayDepartmentData() {
        cout << "\n====================================" << endl;
        cout << "       EMPLOYEE & DEPT DETAILS      " << endl;
        cout << "====================================" << endl;
        displayEmployeeData(); 
        cout << "Department Name : " << dept_name << endl;
        cout << "Location        : " << location << endl;
        cout << "====================================" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

   
    Department d[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Employee " << i + 1 << " ---" << endl;
        d[i].getDepartmentData();
    }


    cout << "\n\n====================================";
    cout << "\n       DISPLAYING ALL RECORDS       ";
    cout << "\n====================================";
    for (int i = 0; i < n; i++) {
        d[i].displayDepartmentData();
    }

    return 0;
}
