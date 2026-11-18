/*Make an array of students as illustrated in Question 1
and write a program to display the details of the
student with the given Date of Birth.*/	
#include <stdio.h>

struct Name
{
    char first_name[20];
    char middle_name[20];
    char last_name[20];
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Marks
{
    float english;
    float mathematics;
    float computer_science;
};

struct Student
{
    int roll_number;
    struct Name name;
    char sex;
    struct Date dob;
    struct Marks marks;
};

int main()
{
    struct Student s[5];
    int n, i;
    int d, m, y;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll_number);

        printf("First Name: ");
        scanf("%s", s[i].name.first_name);

        printf("Middle Name: ");
        scanf("%s", s[i].name.middle_name);

        printf("Last Name: ");
        scanf("%s", s[i].name.last_name);

        printf("Sex: ");
        scanf(" %c", &s[i].sex);

        printf("Date of Birth (DD MM YYYY): ");
        scanf("%d %d %d",
              &s[i].dob.day,
              &s[i].dob.month,
              &s[i].dob.year);

        printf("English Marks: ");
        scanf("%f", &s[i].marks.english);

        printf("Mathematics Marks: ");
        scanf("%f", &s[i].marks.mathematics);

        printf("Computer Science Marks: ");
        scanf("%f", &s[i].marks.computer_science);
    }

    // Enter Date of Birth to search
    printf("\nEnter Date of Birth to search (DD MM YYYY): ");
    scanf("%d %d %d", &d, &m, &y);

    // Search student by Date of Birth
    for(i = 0; i < n; i++)
    {
        if(s[i].dob.day == d &&
           s[i].dob.month == m &&
           s[i].dob.year == y)
        {
            printf("\n--- Student Details ---\n");

            printf("Roll Number : %d\n", s[i].roll_number);

            printf("Name        : %s %s %s\n",
                   s[i].name.first_name,
                   s[i].name.middle_name,
                   s[i].name.last_name);

            printf("Sex         : %c\n", s[i].sex);

            printf("Date of Birth: %02d-%02d-%04d\n",
                   s[i].dob.day,
                   s[i].dob.month,
                   s[i].dob.year);

            printf("English     : %.2f\n", s[i].marks.english);
            printf("Mathematics : %.2f\n", s[i].marks.mathematics);
            printf("Computer Science: %.2f\n",
                   s[i].marks.computer_science);
        }
    }

    return 0;
}


