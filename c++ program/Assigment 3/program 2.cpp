//Consider a class student from which the classes test and sports are derived.
//The class student has the name and rollno of the student. The class test has
//the marks of the internal test and the sports class has the marks of the sports
//test. The class student contains a virtual function display() which are
//implemented in the classes test and sports. Write a program which will take
//relative information and display it using pointer of the base class.

#include <iostream>
using namespace std;

class student
{
protected:
    char name[30];
    int rollno;

public:
    void getdata()
    {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollno;
    }

    virtual void display()
    {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
    }
};

class test : public student
{
    int marks;

public:
    void getdata()
    {
        student::getdata();

        cout << "Enter internal test marks: ";
        cin >> marks;
    }

    void display()
    {
        student::display();
        cout << "Internal Test Marks: " << marks << endl;
    }
};

class sports : public student
{
    int marks;

public:
    void getdata()
    {
        student::getdata();

        cout << "Enter sports test marks: ";
        cin >> marks;
    }

    void display()
    {
        student::display();
        cout << "Sports Test Marks: " << marks << endl;
    }
};

int main()
{
    test t;
    sports s;

    student *ptr;

    cout << "\nEnter Test Student Details:\n";
    t.getdata();

    cout << "\nEnter Sports Student Details:\n";
    s.getdata();

    cout << "\nInternal Test Student Details:\n";
    ptr = &t;
    ptr->display();

    cout << "\nSports Student Details:\n";
    ptr = &s;
    ptr->display();

    return 0;
}

