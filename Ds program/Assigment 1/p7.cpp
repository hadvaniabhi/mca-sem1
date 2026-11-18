/*Write a program to read and display the information
about all the employees in a department. Edit the
details of the ith employee and redisplay the
information.*/
#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    struct Employee e[10];
    int n, i, pos;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Read employee information
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &e[i].id);

        printf("Name: ");
        scanf("%s", e[i].name);

        printf("Salary: ");
        scanf("%f", &e[i].salary);
    }

    // Display employee information
    printf("\n--- Employee Information ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID     : %d\n", e[i].id);
        printf("Name   : %s\n", e[i].name);
        printf("Salary : %.2f\n", e[i].salary);
    }

    // Select employee to edit
    printf("\nEnter employee number to edit: ");
    scanf("%d", &pos);

    pos = pos - 1;

    // Edit employee details
    printf("\nEnter new details:\n");

    printf("Employee ID: ");
    scanf("%d", &e[pos].id);

    printf("Name: ");
    scanf("%s", e[pos].name);

    printf("Salary: ");
    scanf("%f", &e[pos].salary);

    // Redisplay information
    printf("\n--- Updated Employee Information ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID     : %d\n", e[i].id);
        printf("Name   : %s\n", e[i].name);
        printf("Salary : %.2f\n", e[i].salary);
    }

    return 0;
}

