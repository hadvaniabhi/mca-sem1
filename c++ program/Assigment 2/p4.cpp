/*WAP to define an object m1 of matrix class, use m1<<cout.*/
#include <iostream>
using namespace std;

class MyString
{
    char str[100];

public:
    void getString()
    {
        cin >> str;
    }

    bool operator==(MyString s)
    {
        int i = 0;

        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] != s.str[i])
                return false;

            i++;
        }

        return str[i] == s.str[i];
    }

    bool operator<=(MyString s)
    {
        int i = 0;

        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] < s.str[i])
                return true;

            if (str[i] > s.str[i])
                return false;

            i++;
        }

        return str[i] == '\0';
    }

    MyString operator=(MyString s)
    {
        int i = 0;

        while (s.str[i] != '\0')
        {
            str[i] = s.str[i];
            i++;
        }

        str[i] = '\0';

        return *this;
    }

    char operator[](int index)
    {
        return str[index];
    }

    MyString reverse()
    {
        MyString temp;

        int length = 0;

        while (str[length] != '\0')
        {
            length++;
        }

        int i = 0;

        while (length > 0)
        {
            temp.str[i] = str[length - 1];
            i++;
            length--;
        }

        temp.str[i] = '\0';

        return temp;
    }

    MyString operator+(MyString s)
    {
        MyString temp;

        int i = 0;
        int j = 0;

        while (str[i] != '\0')
        {
            temp.str[i] = str[i];
            i++;
        }

        while (s.str[j] != '\0')
        {
            temp.str[i] = s.str[j];
            i++;
            j++;
        }

        temp.str[i] = '\0';

        return temp;
    }

    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    MyString s1, s2, s3;
    int choice, index;

    do
    {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Compare two strings" << endl;
        cout << "2. Check first string <= second string" << endl;
        cout << "3. Copy string" << endl;
        cout << "4. Extract character" << endl;
        cout << "5. Reverse string" << endl;
        cout << "6. Concatenate two strings" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter first string: ";
            s1.getString();

            cout << "Enter second string: ";
            s2.getString();

            if (s1 == s2)
                cout << "Strings are equal." << endl;
            else
                cout << "Strings are not equal." << endl;

            break;

        case 2:
            cout << "Enter first string: ";
            s1.getString();

            cout << "Enter second string: ";
            s2.getString();

            if (s1 <= s2)
                cout << "First string is smaller than or equal to second." << endl;
            else
                cout << "First string is greater than second." << endl;

            break;

        case 3:
            cout << "Enter string to copy: ";
            s1.getString();

            s2 = s1;

            cout << "Copied string: ";
            s2.display();

            break;

        case 4:
            cout << "Enter string: ";
            s1.getString();

            cout << "Enter index: ";
            cin >> index;

            cout << "Character: " << s1[index] << endl;

            break;

        case 5:
            cout << "Enter string: ";
            s1.getString();

            s3 = s1.reverse();

            cout << "Reversed string: ";
            s3.display();

            break;

        case 6:
            cout << "Enter first string: ";
            s1.getString();

            cout << "Enter second string: ";
            s2.getString();

            s3 = s1 + s2;

            cout << "Concatenated string: ";
            s3.display();

            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}
