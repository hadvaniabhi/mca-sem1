/*Modify Question 2 to print each student’s average
marks and the class average (that includes average
of all the student’s marks).*/
#include <stdio.h>

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
    float average, class_total = 0, class_average;

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

    // Display each student's average
    printf("\n--- Student Average ---\n");

    for(i = 0; i < n; i++)
    {
        total = 0;

        for(j = 0; j < 3; j++)
        {
            total = total + s[i].marks[j];
        }

        average = total / 3.0;
        class_total = class_total + total;

        printf("%s = %.2f\n", s[i].name, average);
    }

    // Calculate class average
    class_average = class_total / (n * 3);

    printf("\nClass Average = %.2f\n", class_average);

    return 0;
}

