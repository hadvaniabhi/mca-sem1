/*Write a program using structure to check if the
current year is leap year or not.*/
#include <stdio.h>
#include <time.h>

struct Year
{
    int year;
};

int main()
{
    struct Year y;
    time_t t = time(NULL);
    struct tm *current = localtime(&t);

    y.year = current->tm_year + 1900;

    if ((y.year % 400 == 0) || 
        (y.year % 100 != 0 && y.year % 4 == 0))
    {
        printf("%d is a Leap Year.", y.year);
    }
    else
    {
        printf("%d is not a Leap Year.", y.year);
    }

    return 0;
}


