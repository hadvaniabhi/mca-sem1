/*Create a class student from which the classes test and sports are derived.
The class student has the name and rollno of the student. The class test has
the marks of the internal test and the sports class has the marks of the sports
test. The class student contains a virtual function display() which are
implemented in the classes test and sports. Write a program which will take
relative information and display it using pointer of the base class.*/
#include <iostream>
using namespace std;
class Student {
protected:
    int rollno;
    char name[30];

public:
    Student(int r, const char* n) {
        rollno = r;
        int i = 0;
        while(n[i] != '\0') {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }

    virtual void display() {
        cout << "Roll No: " << rollno << ", Name: " << name << endl;
    }
};

class Test : public Student {
private:
    float test_marks;

public:
    Test(int r, const char* n, float m) : Student(r, n) {
        test_marks = m;
    }

    void display() {
        cout << "\n--- Test Details ---" << endl;
        cout << "Roll No    : " << rollno << endl;
        cout << "Name       : " << name << endl;
        cout << "Test Marks : " << test_marks << endl;
    }
};

class Sports : public Student {
private:
    float sports_score;

public:
    Sports(int r, const char* n, float s) : Student(r, n) {
        sports_score = s;
    }

    void display() {
        cout << "\n--- Sports Details ---" << endl;
        cout << "Roll No      : " << rollno << endl;
        cout << "Name         : " << name << endl;
        cout << "Sports Score : " << sports_score << endl;
    }
};

int main() {
    Test t1(101, "Rahul", 85.5);
    Sports s1(102, "Priya", 92.0);

    Student* ptr;

    ptr = &t1;
    ptr->display();

    ptr = &s1;
    ptr->display();

    return 0;
}
