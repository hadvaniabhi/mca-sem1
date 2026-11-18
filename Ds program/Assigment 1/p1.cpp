/*Declare a structure that represents the following 
hierarchical information.
(a) Student
(b) Roll Number
(c) Name
(i) First name
(ii) Middle Name
(iii) Last Name
(d) Sex
(e) Date of Birth
(i) Day
(ii) Month
(iii) Year
(f) Marks
(i) English
(ii) Mathematics
(iii) Computer Science*/
#include <stdio.h>

struct Student
{
    int roll_no;

    struct
    {
        char first_name[20];
        char middle_name[20];
        char last_name[20];
    } name;

    char sex;

    struct
    {
        int day;
        int month;
        int year;
    } dob;

    struct
    {
        float english;
        float mathematics;
        float computer_science;
    } marks;
};

int main()
{
    struct Student s;

    return 0;
}



