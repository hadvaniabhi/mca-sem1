/*Write a program to find smallest of three numbers
using structures.*/
#include <stdio.h>

struct Number
{
    int a;
    int b;
    int c;
};

int main()
{
    struct Number n;
    int small;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &n.a, &n.b, &n.c);

    small = n.a;

    if(n.b < small)
    {
        small = n.b;
    }

    if(n.c < small)
    {
        small = n.c;
    }

    printf("Smallest number = %d", small);

    return 0;
}

