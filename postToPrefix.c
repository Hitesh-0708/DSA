#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char postfix[max];
char infix[max];
char stack[max];

int top = -1;
int j = 0;

void push(char ch)
{
    if (top == max)
    {
        printf("stack overflow..\n");
        return;
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop(void)
{
    if (top == -1)
    {
        printf("Stack is underflow..\n");
        return 0;
    }
    else
    {
        char ch;
        ch = stack[top];
        top--;
        return ch;
    }
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int empty(void)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void intoPostExp(char *s)
{
    char symbol, ch, c;
    for (int i = 0; s[i]; i++)
    {
        symbol = s[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':
            while ((ch = pop()) != '(')
            {
                postfix[j++] = ch;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while ((!empty()) && ((precedence(stack[top])) >= (c = precedence(symbol))))
            {
              //  printf("c=%d\t", c);
                postfix[j++] = pop();
            }
            //printf("c_out_fn:%d", c);
            push(symbol);
            break;

        default:
            postfix[j++] = symbol;
        }
    }
    while (!empty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print()
{
    int i = 0;
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
}

int main()
{
    printf("Enter the infix exp..:\n");
    scanf("%[^\n]", infix);
    intoPostExp(infix);
    print();
    return 0;
}
