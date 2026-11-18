/*WAP to create student having data members (rollno, name, stream) as base
class. Derive class subject with marks of 5 subjects and apply respective
functionality. Calculate final result and display details of each student from
derived class. (multilevel inheritance).*/
#include <iostream>
using namespace std;
class Student {
protected:
    int rollno;
    char name[30];
    char stream[20];

public:
    void getStudentData() {
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Stream: ";
        cin >> stream;
    }

    void putStudentData() {
        cout << "Roll No : " << rollno << endl;
        cout << "Name    : " << name << endl;
        cout << "Stream  : " << stream << endl;
    }
};

class Subject : public Student {
protected:
    int marks[5];

public:
    void getMarks() {
        getStudentData();
        cout << "Enter marks for 5 subjects (out of 100):\n";
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void putMarks() {
        putStudentData();
        cout << "Marks   : ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class Result : public Subject {
private:
    int total;
    float percentage;

public:
    void calculate() {
        getMarks();
        total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        percentage = total / 5.0;
    }

    void displayResult() {
        cout << "\n------------------------------------" << endl;
        cout << "          STUDENT RESULT            " << endl;
        cout << "------------------------------------" << endl;
        putMarks();
        cout << "Total Marks : " << total << " / 500" << endl;
        cout << "Percentage  : " << percentage << "%" << endl;
        
        if (percentage >= 35) {
            cout << "Status      : PASSED" << endl;
        } else {
            cout << "Status      : FAILED" << endl;
        }
        cout << "------------------------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Result s[n];

    for (int i = 0; i < n; i++) {
        cout << "\n=== Enter details for Student " << i + 1 << " ===" << endl;
        s[i].calculate();
    }

    cout << "\n\n====================================";
    cout << "\n      DISPLAYING ALL RESULTS        ";
    cout << "\n====================================";
    for (int i = 0; i < n; i++) {
        s[i].displayResult();
    }

    return 0;
}
