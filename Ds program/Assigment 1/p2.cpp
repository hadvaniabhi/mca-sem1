/*Define a structure to store the name, an array
marks[] which stores the marks of three different
subjects, and a character grade. Write a program
to display the details of the student whose name
is entered by the user. Use the structure definition
of the first question to make an array of students. 
Display the name of the students who have secured
less than 40% of the aggregate.*/
#include <stdio.h>
#include <string.h>

struct Student
{
    char name[30];
    int marks[3];
    char grade;
};

int main()
{
    struct Student s[5];
    int n, i, j, total;
    float aggregate;
    char search_name[30];

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for(i = 0; i < n; i++)
    {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);

        printf("Enter marks of 3 subjects: ");
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &s[i].marks[j]);
        }

        printf("Enter grade: ");
        scanf(" %c", &s[i].grade);
    }

    // Search student by name
    printf("\nEnter name to search: ");
    scanf("%s", search_name);

    for(i = 0; i < n; i++)
    {
        if(strcmp(s[i].name, search_name) == 0)
        {
            printf("\nStudent Details");
            printf("\nName  : %s", s[i].name);
            printf("\nMarks : %d %d %d",
                   s[i].marks[0],
                   s[i].marks[1],
                   s[i].marks[2]);
            printf("\nGrade : %c\n", s[i].grade);
        }
    }

    // Display students having aggregate less than 40%
    printf("\nStudents having aggregate less than 40%%:\n");

    for(i = 0; i < n; i++)
    {
        total = 0;

        for(j = 0; j < 3; j++)
        {
            total = total + s[i].marks[j];
        }

        aggregate = total / 3.0;

        if(aggregate < 40)
        {
            printf("%s\n", s[i].name);
        }
    }

    return 0;
}


