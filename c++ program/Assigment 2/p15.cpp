/*Write a template function called find(). This function searches an array for an
object. It returns either the index of the matching object (if one is found) or
-1 if no match is found.*/
#include <iostream>
using namespace std;

template <class T>
int find(T arr[], int n, T value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int value;

    cout << "Enter value to search: ";
    cin >> value;

    int result = find(arr, 5, value);

    if (result != -1)
        cout << "Object found at index: " << result << endl;
    else
        cout << "Object not found. Index = -1" << endl;

    return 0;
}
