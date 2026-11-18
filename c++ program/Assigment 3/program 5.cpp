//Define a class marksheet. The class should contain a function PrintMarkSheet
//such that it prints the marksheet of a given student with three subject names
//and five marks for each subject. Define manipulators for displaying headings
//and footnotes. The function should display marksheet with respective
//headings and class. The marks should be aligned under the headings (Use
//either ios functions or manipulators).

#include <iostream>
#include <iomanip>
using namespace std;

class marksheet
{
    string name;
    int rollno;
    string subject[3];
    int marks[3][5];

public:
    void getdata()
    {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> rollno;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Subject " << i + 1 << " Name: ";
            cin >> subject[i];

            for (int j = 0; j < 5; j++)
            {
                cout << "Enter Mark " << j + 1
                     << " for " << subject[i] << ": ";
                cin >> marks[i][j];
            }
        }
    }

    void PrintMarkSheet()
    {
        cout << "\n";
        cout << setfill('*') << setw(50) << "*" << endl;
        cout << setfill(' ');

        cout << setw(35) << right
             << "STUDENT MARKSHEET" << endl;

        cout << setfill('*') << setw(50) << "*" << endl;
        cout << setfill(' ');

        cout << "Student Name: " << name << endl;
        cout << "Roll Number : " << rollno << endl;

        cout << "\n";
        cout << left << setw(15) << "Subject"
             << right << setw(8) << "Mark 1"
             << setw(8) << "Mark 2"
             << setw(8) << "Mark 3"
             << setw(8) << "Mark 4"
             << setw(8) << "Mark 5" << endl;

        cout << setfill('-') << setw(55) << "-" << endl;
        cout << setfill(' ');

        for (int i = 0; i < 3; i++)
        {
            cout << left << setw(15) << subject[i];

            for (int j = 0; j < 5; j++)
            {
                cout << right << setw(8) << marks[i][j];
            }

            cout << endl;
        }

        cout << setfill('-') << setw(55) << "-" << endl;
        cout << setfill(' ');

        cout << "\nFootnote: Marks are out of 100." << endl;
        cout << "Class: Diploma" << endl;
    }
};

int main()
{
    marksheet m;

    m.getdata();
    m.PrintMarkSheet();

    return 0;
}

