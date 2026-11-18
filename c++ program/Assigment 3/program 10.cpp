//Write a C++ program that displays a student object read from a file
//backwards.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class student
{
    string name;
    int rollno;
    float marks;

public:
    void getdata()
    {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollno;

        cout << "Enter marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    student s;

    // Write student object to file
    ofstream fout("student.dat", ios::binary);
    s.getdata();
    fout.write((char*)&s, sizeof(s));
    fout.close();

    // Read student object from file
    student s1;
    ifstream fin("student.dat", ios::binary);

    fin.read((char*)&s1, sizeof(s1));

    cout << "\nStudent Object Read Backwards:\n";

    // Display fields in reverse order
    s1.display();

    fin.close();

    return 0;
}

