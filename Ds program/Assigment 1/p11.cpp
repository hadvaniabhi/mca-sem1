/*Write a program using pointer to structure to
initialize the members of an employee structure.
Use functions to print the employee’s information.*/
#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

void display(struct Employee *emp)
{
    printf("\nEmployee Information:\n");
    printf("ID     : %d\n", emp->id);
    printf("Name   : %s\n", emp->name);
    printf("Salary : %.2f\n", emp->salary);
}

int main()
{
    struct Employee e;
    struct Employee *ptr;

    ptr = &e;

    printf("Enter Employee ID: ");
    scanf("%d", &ptr->id);

    printf("Enter Employee Name: ");
    scanf("%s", ptr->name);

    printf("Enter Employee Salary: ");
    scanf("%f", &ptr->salary);

    display(ptr);

    return 0;
}

