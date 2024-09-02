#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
int x=0;
int matching(char st,char ar)
{
    if(st=='{'&&ar=='}')
    return 1;
    if(st=='<'&&ar=='>')
    return 1;
    if(st=='['&&ar==']')
    return 1;
    if(st=='('&&ar==')')
    return 1;
    else
    return 0;
}

int pop(void)
{
    if(top==-1)
    {
        printf("stack is underflow..\n");
        return 0;
    }
    x=stack[top];
    top--;
    return x;
}

void push(char ch)
{
    if(top==max)
    {
        printf("stack is overflow..");
        return ;
    }
    top++;
    printf("++\n");
    stack[top]=ch;
}

int empty(void)
{
    if(top==-1)
    {
        return 1;
    }
    else
    return 0;
}

int check_exp (char *s)
{
    for(int i=0;s[i];i++)
    {
        if(s[i]=='{'||s[i]=='('||s[i]=='['||s[i]=='<')
        {
            push(s[i]);
        }
        else if(s[i]=='}'||s[i]==')'||s[i]=='>'||s[i]==']')
        {
            if(empty())
            {
                printf("invalid expession..\n");
                printf("right breaket's are more than left brekates..\n");
                return 0;
            }
            else
            {
                char temp=pop();
                int match = matching(temp,s[i]);
                if(match==0)
                {
                    printf("breakets are missed matched..\n");
                    return 0;
                }
            }

        }
    }
    if(empty())
    {
        printf("braekets are well organized..\n");
        return 1;
    }
    printf("left breakets are more then right breakets..\n");
    return 0;
}


void main()
{
    char arr[max];
    int balanced=0;
    printf("Enter the expression..:\n");
    scanf("%[^\n]",&arr);

    //printf("%s\n",arr);

    balanced=check_exp(arr);
    if(balanced==1)
    {
        printf("valid expression..\n");
    }
    else
    printf("Invalid expression..\n");
}