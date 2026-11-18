/*Write a program to define a structure vector. Then
write functions to read data, print data, add two
vectors and scale the members of a vector by a
factor of 10.*/
#include <stdio.h>

struct Vector
{
    int x;
    int y;
    int z;
};

void ReadVector(struct Vector *v)
{
    printf("Enter x, y and z: ");
    scanf("%d %d %d", &v->x, &v->y, &v->z);
}

void PrintVector(struct Vector v)
{
    printf("Vector = (%d, %d, %d)\n", v.x, v.y, v.z);
}

struct Vector AddVector(struct Vector v1, struct Vector v2)
{
    struct Vector v3;

    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;

    return v3;
}

void ScaleVector(struct Vector *v)
{
    v->x = v->x * 10;
    v->y = v->y * 10;
    v->z = v->z * 10;
}

int main()
{
    struct Vector v1, v2, v3;

    printf("Enter first vector:\n");
    ReadVector(&v1);

    printf("Enter second vector:\n");
    ReadVector(&v2);

    printf("\nFirst Vector:\n");
    PrintVector(v1);

    printf("Second Vector:\n");
    PrintVector(v2);

    v3 = AddVector(v1, v2);

    printf("\nAddition of two vectors:\n");
    PrintVector(v3);

    ScaleVector(&v1);

    printf("\nFirst vector after scaling by 10:\n");
    PrintVector(v1);

    return 0;
}

