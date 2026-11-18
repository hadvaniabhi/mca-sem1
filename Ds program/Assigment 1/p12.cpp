/*Write a program to create a structure with the
information given below. Then, read and print the
data.
Employee[10]
(a) Emp_Id
(b) Name
(i) First Name
(ii) Middle Name
(iii) Last Name
(c) Address
(i) Area
(ii) City
(iii) State
(d) Age
(e) Salary
(f) Designation*/

#include <stdio.h>

struct Employee
{
    int Emp_Id;

    struct
    {
        char First_Name[20];
        char Middle_Name[20];
        char Last_Name[20];
    } Name;

    struct
    {
        char Area[30];
        char City[20];
        char State[20];
    } Address;

    int Age;
    float Salary;
    char Designation[30];
};

int main()
{
    struct Employee Employee[10];
    int i, n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Employee %d:\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &Employee[i].Emp_Id);

        printf("First Name: ");
        scanf("%s", Employee[i].Name.First_Name);

        printf("Middle Name: ");
        scanf("%s", Employee[i].Name.Middle_Name);

        printf("Last Name: ");
        scanf("%s", Employee[i].Name.Last_Name);

        printf("Area: ");
        scanf("%s", Employee[i].Address.Area);

        printf("City: ");
        scanf("%s", Employee[i].Address.City);

        printf("State: ");
        scanf("%s", Employee[i].Address.State);

        printf("Age: ");
        scanf("%d", &Employee[i].Age);

        printf("Salary: ");
        scanf("%f", &Employee[i].Salary);

        printf("Designation: ");
        scanf("%s", Employee[i].Designation);
    }

    printf("\n--- Employee Information ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID : %d\n", Employee[i].Emp_Id);
        printf("Name        : %s %s %s\n",
               Employee[i].Name.First_Name,
               Employee[i].Name.Middle_Name,
               Employee[i].Name.Last_Name);
        printf("Address     : %s, %s, %s\n",
               Employee[i].Address.Area,
               Employee[i].Address.City,
               Employee[i].Address.State);
        printf("Age         : %d\n", Employee[i].Age);
        printf("Salary      : %.2f\n", Employee[i].Salary);
        printf("Designation : %s\n", Employee[i].Designation);
    }

    return 0;
}

