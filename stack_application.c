#include<stdio.h>
#include<stdlib.h>
#define ele 5
int top=-1;
int stack[6];

void push(void)
{
    if(top==5)
    {
        printf("Stack is overflow..:\n");
        return;
    }
    else
    top++;
    printf("Enter the data..:\n");
    scanf("%d",&stack[top]);
}

void pop(void)
{
    if(top==-1)
    {
        printf("Stack is underfloaw..:\n");
        return;
    }
    else
    {
        printf("%d is deleted..:\n",stack[top]);
        top--;
    }
}

void display(void)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}

void main()
{
    int op=0;
    while(1)
    {
        printf("\n1)push \t2)pop\t3)dispay\n");
        printf("Chose one oprtion..:\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1: push();
        break;

        case 2: pop();
        break;

        case 3: display();
        break;

        default:
        printf("wrong option selected..:\n");
        }
    }
}