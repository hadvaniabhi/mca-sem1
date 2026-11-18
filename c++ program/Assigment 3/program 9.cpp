//Define a class Result which contains the result of an MCA written test. It
//should take merit list from a file and display on the screen such that at a time
//only ten candidates information is printed on the screen. The headings should
//be displayed using a manipulator. All the information should be aligned with
//the headings.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Result
{
public:
    void display()
    {
        ifstream fin("merit.txt");

        if (!fin)
        {
            cout << "File not found!" << endl;
            return;
        }

        string name;
        int rollno, marks;
        int count = 0;

        cout << "\n";
        cout << setw(45) << right
             << "MCA WRITTEN TEST MERIT LIST" << endl;

        cout << setfill('-') << setw(65) << "-" << endl;
        cout << setfill(' ');

        cout << left
             << setw(10) << "Roll No"
             << setw(25) << "Name"
             << setw(10) << "Marks" << endl;

        cout << setfill('-') << setw(45) << "-" << endl;
        cout << setfill(' ');

        while (fin >> rollno >> name >> marks)
        {
            cout << left
                 << setw(10) << rollno
                 << setw(25) << name
                 << setw(10) << marks << endl;

            count++;

            if (count == 10)
            {
                cout << "\nPress Enter to display next 10 candidates...";
                cin.ignore(10000, '\n');
                cin.get();

                count = 0;

                cout << "\n";
                cout << left
                     << setw(10) << "Roll No"
                     << setw(25) << "Name"
                     << setw(10) << "Marks" << endl;

                cout << setfill('-') << setw(45) << "-" << endl;
                cout << setfill(' ');
            }
        }

        fin.close();
    }
};

int main()
{
    Result r;
    r.display();

    return 0;
}

