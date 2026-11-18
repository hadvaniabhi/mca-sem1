
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main(void)
{
    char infix[MAX], stack[MAX], postfix[MAX];
    int top = -1, i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];

            if (top < 0)
            {
                printf("Invalid expression\n");
                return 0;
            }

            top--;
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^')
        {
            while (top >= 0 && stack[top] != '(' &&
                  (priority(stack[top]) > priority(ch) ||
                  (priority(stack[top]) == priority(ch)
                   && ch != '^')))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }
        else
        {
            printf("Invalid character\n");
            return 0;
        }
    }

    while (top >= 0)
    {
        if (stack[top] == '(')
        {
            printf("Invalid expression\n");
            return 0;
        }

        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

