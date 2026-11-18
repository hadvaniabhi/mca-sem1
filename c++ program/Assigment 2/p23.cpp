/*Define a class Faculty. It contains the following attributes:

(a) Name of the faculty
(b) Qualification of the faculty
(c) Subjects the faculty can teach
Inherit the Faculty class into a regular faculty, who
(a) is available full time (no consulting time is specified)
(b) teaches at least three subjects
(c) is part of the institute alone
Inherit the Faculty class into visiting faculty, who
(a) is available only on two to three days (consulting time is also to be
specified)
(b) teaches a single subject
(c) is part of some other institute
Provide virtual functions for reading and writing class objects of the classes
given above.*/
#include <iostream>
#include <string>
using namespace std;

class Faculty {
protected:
    string name;
    string qualification;

public:
    virtual void readData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Qualification: ";
        cin >> qualification;
    }

    virtual void writeData() {
        cout << "Name: " << name << endl;
        cout << "Qualification: " << qualification << endl;
    }

    virtual ~Faculty() {}
};

class RegularFaculty : public Faculty {
private:
    string subjects[3];
    string institute;

public:
    void readData() override {
        Faculty::readData();
        cout << "Enter 3 Subjects:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> subjects[i];
        }
        cout << "Enter Institute Name: ";
        cin >> institute;
    }

    void writeData() override {
        cout << "\n--- Regular Faculty Details ---" << endl;
        Faculty::writeData();
        cout << "Type: Full Time" << endl;
        cout << "Institute: " << institute << endl;
        cout << "Subjects: ";
        for (int i = 0; i < 3; i++) {
            cout << subjects[i] << " ";
        }
        cout << endl;
    }
};

class VisitingFaculty : public Faculty {
private:
    string subject;
    string other_institute;
    int working_days;
    string consulting_time;

public:
    void readData() override {
        Faculty::readData();
        cout << "Enter Single Subject: ";
        cin >> subject;
        cout << "Enter Other Institute Name: ";
        cin >> other_institute;
        cout << "Enter Working Days (2 or 3): ";
        cin >> working_days;
        cout << "Enter Consulting Time: ";
        cin >> consulting_time;
    }

    void writeData() override {
        cout << "\n--- Visiting Faculty Details ---" << endl;
        Faculty::writeData();
        cout << "Subject: " << subject << endl;
        cout << "Other Institute: " << other_institute << endl;
        cout << "Working Days: " << working_days << " days/week" << endl;
        cout << "Consulting Time: " << consulting_time << endl;
    }
};

int main() {
    Faculty* f1 = new RegularFaculty();
    Faculty* f2 = new VisitingFaculty();

    cout << "=== Enter Regular Faculty Details ===" << endl;
    f1->readData();

    cout << "\n=== Enter Visiting Faculty Details ===" << endl;
    f2->readData();

    cout << "\n====================================";
    f1->writeData();
    f2->writeData();

    delete f1;
    delete f2;

    return 0;
}
