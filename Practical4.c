
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }

    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;

    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    if (x == '^')
        return 3;

    return -1;
}

int main()
{
    char exp[MAX], ch;
    int i = 0;

    printf("Enter infix expression: ");
    scanf("%99s", exp);

    printf("Postfix Expression: ");

    while (exp[i] != '\0')
    {
        ch = exp[i];

        if (isalnum((unsigned char)ch))
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                printf("%c", pop());
            }

            if (top != -1 && stack[top] == '(')
                pop();
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   (priority(stack[top]) > priority(ch) ||
                   (priority(stack[top]) == priority(ch) &&
                    ch != '^')))
            {
                printf("%c", pop());
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        if (stack[top] == '(')
        {
            pop();
        }
        else
        {
            printf("%c", pop());
        }
    }

    printf("\n");

    return 0;
}
