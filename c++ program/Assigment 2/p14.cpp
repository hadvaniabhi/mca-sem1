/*Write a generic function that will sort a character string, integer and float
value. Create a menu with appropriate options and accept the values from the
user.*/
#include <iostream>
using namespace std;

template <class T>
void sortArray(T arr[], int n)
{
    T temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <class T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, n;

    do
    {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Sort Integer Values" << endl;
        cout << "2. Sort Float Values" << endl;
        cout << "3. Sort Character String" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int arr[100];

            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter integer values: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            sortArray(arr, n);

            cout << "Sorted values: ";
            display(arr, n);

            break;
        }

        case 2:
        {
            float arr[100];

            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter float values: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            sortArray(arr, n);

            cout << "Sorted values: ";
            display(arr, n);

            break;
        }

        case 3:
        {
            char str[100];

            cout << "Enter character string: ";
            cin >> str;

            n = 0;

            while (str[n] != '\0')
            {
                n++;
            }

            sortArray(str, n);

            cout << "Sorted string: ";
            display(str, n);

            break;
        }

        case 4:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}

