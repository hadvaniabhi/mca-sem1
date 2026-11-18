//WAP to create namespace having function for total_marks. Show its use in
//class ‘marks’ of students, display total marks of subjects using namespace.

#include <iostream>
using namespace std;

namespace student
{
    int total_marks(int a, int b, int c)
    {
        return a + b + c;
    }
}

class marks
{
    int m1, m2, m3;

public:
    void getdata()
    {
        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }

    void display()
    {
        cout << "Total Marks = "
             << student::total_marks(m1, m2, m3)
             << endl;
    }
};

int main()
{
    marks m;

    m.getdata();
    m.display();

    return 0;
}

