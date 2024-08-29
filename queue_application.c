#include<stdio.h>
#include<stdlib.h>
#define ele 5

int queue[ele];
int top=-1;

void push(void)
{
    if(top==4)
    {
        printf("queue is overflow..:\n");
        return;
    }
    else
    {
        top++;
        printf("Enter the data:\n");
        scanf("%d",&queue[top]);
    }
}

void pop(void)
{
    if(top==-1)
    {
        printf("queue is underflow\n");
        return;
    }
    else
    {
        printf("%d is deleted..\n",queue[0]);
        for(int i=0;i<top;i++)
        {
            queue[i]=queue[i+1];
        }
        top--;
    }
}
    void display(void)
    {
        if(top<0)
        { 
            printf("Nothing is there in queue..\n");
            printf("First add something in queue..\n");
            return;
        }
            for(int i=0;i<=top;i++)
            {
                printf("%d\t",queue[i]);
            }
            printf("\n");
    }
void main()
{
    int op;
    while(1)
    {
        printf("1)push\t2)pop\t3)display\n");
        printf("Chose one option..:\n");
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
            printf("Wrong option selcted..:\n");

        }
    }
}