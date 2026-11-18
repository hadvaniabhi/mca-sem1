/*Define a class Student. Inherit this class into MCAStudent and
NonMCAStudent. Also inherit it into Local and NonLocal students. Multiple
inherit LocalMCAStudent from Local and MCAStudent. Define five instances
of LocalMCAStudent with a constructor, assuming that all classes have a
constructor.*/
#include <iostream>
using namespace std;

class Student {
public:
    Student() {
        cout << "Student" << endl;
    }
};

class MCAStudent : virtual public Student {
public:
    MCAStudent() {
        cout << "MCAStudent" << endl;
    }
};

class NonMCAStudent : virtual public Student {
public:
    NonMCAStudent() {
        cout << "NonMCAStudent" << endl;
    }
};

class Local : virtual public Student {
public:
    Local() {
        cout << "Local" << endl;
    }
};

class NonLocal : virtual public Student {
public:
    NonLocal() {
        cout << "NonLocal" << endl;
    }
};

class LocalMCAStudent : public Local, public MCAStudent {
public:
    LocalMCAStudent() {
        cout << "LocalMCAStudent Created" << endl;
    }
};

int main() {
    LocalMCAStudent s1;
    cout << "---" << endl;
    LocalMCAStudent s2;
    cout << "---" << endl;
    LocalMCAStudent s3;
    cout << "---" << endl;
    LocalMCAStudent s4;
    cout << "---" << endl;
    LocalMCAStudent s5;

    return 0;
}
