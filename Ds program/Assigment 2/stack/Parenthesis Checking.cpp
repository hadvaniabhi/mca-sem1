
#include <stdio.h>
#include <string.h>

#define MAX 200

int main(void)
{
    char exp[MAX], stack[MAX];
    int top = -1, i, valid = 1;
    char ch;

    printf("Enter expression: ");
    fgets(exp, MAX, stdin);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            if (top == MAX - 1)
            {
                valid = 0;
                break;
            }
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                valid = 0;
                break;
            }

            if ((ch == ')' && stack[top] == '(') ||
                (ch == '}' && stack[top] == '{') ||
                (ch == ']' && stack[top] == '['))
            {
                top--;
            }
            else
            {
                valid = 0;
                break;
            }
        }
    }

    if (top != -1)
        valid = 0;

    if (valid)
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are Not Balanced\n");

    return 0;
}

