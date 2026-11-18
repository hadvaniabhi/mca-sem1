/*Write a program to define a structure for a hotel
that has members— name, address, grade, number
of rooms, and room charges. Write a function to
print the names of hotels in a particular grade. Also
write a function to print names of hotels that have
room charges less than the specified value.*/

#include <stdio.h>

struct Hotel
{
    char name[50];
    char address[100];
    char grade;
    int rooms;
    float charges;
};

void PrintByGrade(struct Hotel h[], int n, char grade)
{
    int i;

    printf("\nHotels of Grade %c:\n", grade);

    for (i = 0; i < n; i++)
    {
        if (h[i].grade == grade)
        {
            printf("%s\n", h[i].name);
        }
    }
}

void PrintByCharges(struct Hotel h[], int n, float charges)
{
    int i;

    printf("\nHotels with room charges less than %.2f:\n", charges);

    for (i = 0; i < n; i++)
    {
        if (h[i].charges < charges)
        {
            printf("%s\n", h[i].name);
        }
    }
}

int main()
{
    struct Hotel h[10];
    int n, i;
    char grade;
    float charges;

    printf("Enter number of hotels: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Hotel %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", h[i].name);

        printf("Address: ");
        scanf(" %[^\n]", h[i].address);

        printf("Grade (A/B/C): ");
        scanf(" %c", &h[i].grade);

        printf("Number of Rooms: ");
        scanf("%d", &h[i].rooms);

        printf("Room Charges: ");
        scanf("%f", &h[i].charges);
    }

    printf("\nEnter grade to search: ");
    scanf(" %c", &grade);

    PrintByGrade(h, n, grade);

    printf("\nEnter maximum room charge: ");
    scanf("%f", &charges);

    PrintByCharges(h, n, charges);

    return 0;
}

