
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char exp[MAX], ch;
    int stack[MAX], top = -1;
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (isdigit((unsigned char)ch))
        {
            stack[++top] = ch - '0';
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/')
        {
            if (top < 1)
            {
                printf("Invalid postfix expression\n");
                return 0;
            }

            b = stack[top--];
            a = stack[top--];

            switch (ch)
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero\n");
                        return 0;
                    }
                    result = a / b;
                    break;
            }

            stack[++top] = result;
        }
        else
        {
            printf("Invalid character\n");
            return 0;
        }
    }

    if (top != 0)
        printf("Invalid postfix expression\n");
    else
        printf("Result = %d\n", stack[top]);

    return 0;
}

