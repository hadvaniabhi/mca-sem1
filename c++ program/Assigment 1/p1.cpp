/*Write a program to create class Student with student’s rollno, name and
marks of three subjects (OOCP, AI and MF) and display the details of student
with total marks of all subjects along with the percentage in proper format.
Output should be in descending order of percentage if student having same
percentage then consider higher marks in MF should be display first.*/
#include <iostream>
#include <string>
using namespace std;

class Student
{
    int rollno;
    string name;
    int OOCP, AI, MF;

public:

    void input()
    {
        cout << "Enter Roll No: ";
        cin >> rollno;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter OOCP Marks: ";
        cin >> OOCP;

        cout << "Enter AI Marks: ";
        cin >> AI;

        cout << "Enter MF Marks: ";
        cin >> MF;
    }

    int total()
    {
        return OOCP + AI + MF;
    }

    float percentage()
    {
        return total() / 3.0;
    }

    int getMF()
    {
        return MF;
    }

    void display()
    {
        cout << rollno << "\t"
             << name << "\t"
             << OOCP << "\t"
             << AI << "\t"
             << MF << "\t"
             << total() << "\t"
             << percentage() << "%\n";
    }
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;
        s[i].input();
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].percentage() < s[j].percentage())
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            else if (s[i].percentage() == s[j].percentage())
            {
                if (s[i].getMF() < s[j].getMF())
                {
                    Student temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    }

    
    cout << "Roll\tName\tOOCP\tAI\tMF\tTotal\tPercentage\n";

    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    return 0;
}
