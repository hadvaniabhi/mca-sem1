/*Using the structure definition of the above
program, write a function to increment the date.
Make sure that the incremented date is a valid
date. */

#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int IsLeapYear(int year)
{
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

void IncrementDate(struct Date *D)
{
    int maxDays;

    if (D->month == 2)
    {
        if (IsLeapYear(D->year))
            maxDays = 29;
        else
            maxDays = 28;
    }
    else if (D->month == 4 || D->month == 6 ||
             D->month == 9 || D->month == 11)
    {
        maxDays = 30;
    }
    else
    {
        maxDays = 31;
    }

    D->day++;

    if (D->day > maxDays)
    {
        D->day = 1;
        D->month++;

        if (D->month > 12)
        {
            D->month = 1;
            D->year++;
        }
    }
}

int main()
{
    struct Date D;

    printf("Enter day: ");
    scanf("%d", &D.day);

    printf("Enter month: ");
    scanf("%d", &D.month);

    printf("Enter year: ");
    scanf("%d", &D.year);

    IncrementDate(&D);

    printf("Incremented Date = %d/%d/%d\n",
           D.day, D.month, D.year);

    return 0;
}

