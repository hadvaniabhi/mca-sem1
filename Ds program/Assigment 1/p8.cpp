/*Write a program to add and subtract height 6'2"
and 5'4".*/
#include <stdio.h>

struct Height
{
    int feet;
    int inch;
};

int main()
{
    struct Height h1 = {6, 2};
    struct Height h2 = {5, 4};
    struct Height add, sub;

    add.feet = h1.feet + h2.feet;
    add.inch = h1.inch + h2.inch;

    if(add.inch >= 12)
    {
        add.feet++;
        add.inch -= 12;
    }

    sub.feet = h1.feet - h2.feet;
    sub.inch = h1.inch - h2.inch;

    if(sub.inch < 0)
    {
        sub.feet--;
        sub.inch += 12;
    }

    printf("Addition = %d' %d\"\n", add.feet, add.inch);
    printf("Subtraction = %d' %d\"\n", sub.feet, sub.inch);

    return 0;
}
