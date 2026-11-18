
#include <stdio.h>
#include <ctype.h>

#define MAX 200

int main(void)
{
    char exp[MAX], brackets[MAX];
    int top = -1, i;
    int expectOperand = 1;
    int valid = 1;
    char ch;

    printf("Enter expression: ");
    fgets(exp, MAX, stdin);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (isspace((unsigned char)ch))
            continue;

        if (isalnum((unsigned char)ch))
        {
            if (!expectOperand)
            {
                valid = 0;
                break;
            }

            expectOperand = 0;
        }
        else if (ch == '(')
        {
            if (!expectOperand || top == MAX - 1)
            {
                valid = 0;
                break;
            }

            brackets[++top] = ch;
            expectOperand = 1;
        }
        else if (ch == ')')
        {
            if (expectOperand || top == -1)
            {
                valid = 0;
                break;
            }

            top--;
            expectOperand = 0;
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^')
        {
            if (expectOperand)
            {
                valid = 0;
                break;
            }

            expectOperand = 1;
        }
        else
        {
            valid = 0;
            break;
        }
    }

    if (expectOperand || top != -1)
        valid = 0;

    if (valid)
        printf("Expression is Valid\n");
    else
        printf("Expression is Invalid\n");

    return 0;
}

