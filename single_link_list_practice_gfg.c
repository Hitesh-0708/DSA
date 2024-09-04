#include<stdio.h>
#include<stdlib.h>
struct sll {
    int data;
    struct sll* next;
};

void add_node(struct sll **head)
{
    struct sll *new= (struct sll *)calloc(1,sizeof(struct sll));
    printf("Enter the  data\n");
    scanf("%d",&new->data);
    
    if(*head==0)
    {
        *head = new;
    }
    else
    {
        new->next = *head;
        *head=new;
    }
}


void reverse_link(struct sll **head)
{
    struct sll *curr = *head;
    struct sll *prev = NULL;
    struct sll *next = NULL;    

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    *head=prev;

}

void print(struct sll *head)
{
    struct sll *temp = head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void main()
{
    struct sll *head = NULL;

    while(1)
    {   
        printf("1)add\n 2)reverse\n3)print\n4)exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)  
        {
            case 1: add_node(&head); break;
            case 2: reverse_link(&head); break;
            case 3: print(head); break;
            case 4: exit(0); break;
            default: printf("invalid choice\n");

        }   
    }
}