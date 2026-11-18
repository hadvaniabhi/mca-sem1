/*WAP to overload operator * which multiply a number to each element of an
array within a class arrayContainer and display the result.
*/
#include <iostream>
using namespace std;

class arrayContainer
{
    int arr[5];

public:
    void getData()
    {
        cout << "Enter 5 elements: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> arr[i];
        }
    }

    arrayContainer operator*(int n)
    {
        arrayContainer temp;

        for (int i = 0; i < 5; i++)
        {
            temp.arr[i] = arr[i] * n;
        }

        return temp;
    }

    void display()
    {
        cout << "Result: ";
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    arrayContainer a1, a2;
    int n;

    a1.getData();

    cout << "Enter number to multiply: ";
    cin >> n;

    a2 = a1 * n;

    a2.display();

    return 0;
}
