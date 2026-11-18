/*Define a structure date containing three integers—
day, month, and year. Write a program using
functions to read data, to validate the date entered
by the user and then print the date on the screen.
For example, if you enter 29,2,2010 then that is an invalid date as 2010 is not a leap year. Similarly
31,6,2007 is invalid as June does not have 31 days.*/
#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void ReadDate(struct Date *D)
{
    printf("Enter Day: ");
    scanf("%d", &D->day);

    printf("Enter Month: ");
    scanf("%d", &D->month);

    printf("Enter Year: ");
    scanf("%d", &D->year);
}

int IsLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int ValidateDate(struct Date D)
{
    int maxDays;

    if (D.month < 1 || D.month > 12)
        return 0;

    if (D.month == 2)
    {
        if (IsLeapYear(D.year))
            maxDays = 29;
        else
            maxDays = 28;
    }
    else if (D.month == 4 || D.month == 6 ||
             D.month == 9 || D.month == 11)
    {
        maxDays = 30;
    }
    else
    {
        maxDays = 31;
    }

    if (D.day < 1 || D.day > maxDays)
        return 0;

    return 1;
}

void PrintDate(struct Date D)
{
    printf("Date = %d/%d/%d\n", D.day, D.month, D.year);
}

int main()
{
    struct Date D;

    ReadDate(&D);

    if (ValidateDate(D))
    {
        printf("Valid Date\n");
        PrintDate(D);
    }
    else
    {
        printf("Invalid Date\n");
    }

    return 0;
}

