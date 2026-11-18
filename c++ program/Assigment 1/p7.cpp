/*Create class STUDENT having rollno, name and age as data members, also
take subject with three subjects and initialize their value with minimum
passing marks. Using member function, modify marks of student with specific
rollno which is given by user.*/
#include <iostream>
#include <string>
using namespace std;

class STUDENT
{
    int rollno;
    string name;
    int age;

    int sub1, sub2, sub3;

public:

    STUDENT()
    {
        sub1 = 35;
        sub2 = 35;
        sub3 = 35;
    }

    void input()
    {
        cout << "Enter Roll No: ";
        cin >> rollno;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;
    }

    int getRollNo()
    {
        return rollno;
    }

    void modifyMarks()
    {
        cout << "Enter Subject 1 Marks: ";
        cin >> sub1;

        cout << "Enter Subject 2 Marks: ";
        cin >> sub2;

        cout << "Enter Subject 3 Marks: ";
        cin >> sub3;
    }

    void display()
    {
        cout << "\nRoll No : " << rollno;
        cout << "\nName    : " << name;
        cout << "\nAge     : " << age;
        cout << "\nSubject 1 Marks : " << sub1;
        cout << "\nSubject 2 Marks : " << sub2;
        cout << "\nSubject 3 Marks : " << sub3 << endl;
    }
};

int main()
{
    int n;
    int rno;
    bool found = false;

    cout << "Enter number of students: ";
    cin >> n;

    STUDENT s[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student "
             << i + 1 << endl;

        s[i].input();
    }

    cout << "\nEnter Roll No to modify marks: ";
    cin >> rno;

    for(int i = 0; i < n; i++)
    {
        if(s[i].getRollNo() == rno)
        {
            s[i].modifyMarks();
            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nStudent with Roll No "
             << rno << " not found." << endl;
    }

    cout << "\nStudent Details\n";

    for(int i = 0; i < n; i++)
    {
        s[i].display();
    }

    return 0;
}

