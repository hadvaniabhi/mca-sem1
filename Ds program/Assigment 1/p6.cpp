/*Write a program to calculate the distance between
the given points (6,3) and (2,2).*/
#include <stdio.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p1 = {6, 3};
    struct Point p2 = {2, 2};

    float distance;

    distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                    (p1.y - p2.y) * (p1.y - p2.y));

    printf("Distance = %.2f", distance);

    return 0;
}

