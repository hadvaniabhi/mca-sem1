/*Write a program to add and subtract 10hrs 20mins
50sec and 5hrs 30min 40sec.*/
#include <stdio.h>

struct Time
{
    int hr;
    int min;
    int sec;
};

int main()
{
    struct Time t1 = {10, 20, 50};
    struct Time t2 = {5, 30, 40};
    struct Time add, sub;

    /* Addition */
    add.sec = t1.sec + t2.sec;
    add.min = t1.min + t2.min;
    add.hr = t1.hr + t2.hr;

    if(add.sec >= 60)
    {
        add.min++;
        add.sec -= 60;
    }

    if(add.min >= 60)
    {
        add.hr++;
        add.min -= 60;
    }

    /* Subtraction */
    sub.sec = t1.sec - t2.sec;
    sub.min = t1.min - t2.min;
    sub.hr = t1.hr - t2.hr;

    if(sub.sec < 0)
    {
        sub.min--;
        sub.sec += 60;
    }

    if(sub.min < 0)
    {
        sub.hr--;
        sub.min += 60;
    }

    printf("Addition = %d hrs %d mins %d sec\n",
           add.hr, add.min, add.sec);

    printf("Subtraction = %d hrs %d mins %d sec\n",
           sub.hr, sub.min, sub.sec);

    return 0;
}

