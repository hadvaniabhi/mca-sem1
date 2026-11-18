/*WAP to use binary operator + add two object of class Numbers having num1
and num2 as its data members and display result.*/
#include <iostream>
using namespace std;

class Numbers
{
    int num1, num2;

public:
    void getData()
    {
        cout << "Enter num1 and num2: ";
        cin >> num1 >> num2;
    }

    Numbers operator+(Numbers n)
    {
        Numbers temp;
        temp.num1 = num1 + n.num1;
        temp.num2 = num2 + n.num2;
        return temp;
    }

    void display()
    {
        cout << "Result num1 = " << num1 << endl;
        cout << "Result num2 = " << num2 << endl;
    }
};

int main()
{
    Numbers n1, n2, n3;

    n1.getData();
    n2.getData();

    n3 = n1 + n2;

    n3.display();

    return 0;
}
