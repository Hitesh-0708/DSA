#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int find_prime(int num)
{
    int c=0,i;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1; 
}

void delete_prime(struct node **head)
{
    struct node *current=*head,*temp=0;
    int num=0;
    while(current!=0)
    {
        if(find_prime(current->data))
        {
            if(temp==0)
            {   
                *head=current->next;
                free(current);
                current=*head;
                current->prev=0;
                temp=current;
            }
            else if(current->next!=0)
            {
                temp->next=current->next;
                current->next->prev=temp;
                free(current);
                current=temp->next;
            }      
            else
            {
                temp->next=0;
                free(current);
                current=0;
            }
        } 
        else
        {
            temp=current;
            current=current->next;
        }  
    }
}

void add_node(struct node **head,int data)
{
    struct node *new=(struct node *)calloc(1,sizeof(struct node)),*temp=*head;
    new->data=data;

    if(temp==0)
    {
        *head=new;
    }
    else
    {
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
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
void main()
{
    struct node *head=0;
    int op=0;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1. Add node\n");
        printf("2. Delete prime\n");        
        printf("3. Print list\n");
        printf("4. Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d",&data);
                add_node(&head,data);
                break;
            }
            case 2:
                delete_prime(&head);
                break;      
            case 3:
                print_list(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");       
        }
    }

}