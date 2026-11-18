//Write a program to create a file student to store name and marks of 5
//students and then display them.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int marks;

    // Create file and store student details
    ofstream fout("student.txt");

    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter name of student " << i << ": ";
        cin >> name;

        cout << "Enter marks of student " << i << ": ";
        cin >> marks;

        fout << name << " " << marks << endl;
    }

    fout.close();

    // Read and display student details
    ifstream fin("student.txt");

    cout << "\nStudent Details\n";
    cout << "Name\tMarks\n";

    while (fin >> name >> marks)
    {
        cout << name << "\t" << marks << endl;
    }

    fin.close();

    return 0;
}

