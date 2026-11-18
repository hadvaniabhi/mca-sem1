/*Modify the above program to add a specific
number of days to the given date.*/
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

int DaysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (IsLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 ||
             month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

void AddDays(struct Date *D, int days)
{
    while (days > 0)
    {
        D->day++;
        days--;

        if (D->day > DaysInMonth(D->month, D->year))
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
}

int main()
{
    struct Date D;
    int days;

    printf("Enter day: ");
    scanf("%d", &D.day);

    printf("Enter month: ");
    scanf("%d", &D.month);

    printf("Enter year: ");
    scanf("%d", &D.year);

    printf("Enter number of days to add: ");
    scanf("%d", &days);

    AddDays(&D, days);

    printf("New Date = %d/%d/%d\n",
           D.day, D.month, D.year);

    return 0;
}

