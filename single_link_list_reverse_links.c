#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void add_node(struct node **head,int data)
{
    struct node *new=(struct node *)calloc(1,sizeof(struct node));
    new->data=data;

    struct node *temp=*head;
    if(temp==0)
    {
        *head=new;
    }
    else
    {
        while(temp->next  != 0)
        {
          temp=temp->next;
        }
        temp->next=new;
    }
}

void print_list(struct node *head)
{
    struct node *temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(struct node **head)
{
    struct node *current=*head;
    struct node *prev=NULL;
    struct node *next=NULL;

    while( current != NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;

    }
    *head=prev;
}

void main()
{
    struct node *head=0;
    int data,op;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1. Add node\n");    
        printf("2. Print list\n");
        printf("3. Reverse list\n");
        printf("4. Exit\n");
        scanf("%d",&op);    

        switch(op)
        {
            case 1:
                printf("Enter data\n");
                scanf("%d",&data);
                add_node(&head,data);
                break;

            case 2:
                print_list(head);
                break;  

            case 3:
                reverse(&head);
                break;      

            case 4:
                exit(0);
        }                           
    }
}   