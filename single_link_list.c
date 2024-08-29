#include<stdio.h>
#include<stdlib.h>
struct sin_link_list
{
    int a;
    struct sin_link_list * next;

};

void del_first(struct sin_link_list **p)
{
    int temp=0;
    struct sin_link_list *del=*p;
   
    if(del==0)
    {
        printf("No nodes are present..:\n");
        return;
    }
    else
    {
        *p=del->next;
        del->next=0;
    }
    free(del);
}


void del_last(struct sin_link_list **p)
{
    struct sin_link_list *del=*p,*last=*p;
    if(del==0)
    {
        printf("No node are present ..:\n");
        return;
    }
    else 
    {
        while(del->next!=0)
        {
            last=del;
            del=del->next;
        }
        last->next=0;
        free(del);
    }
}


/*
void sort_node(struct sin_link_list **p)
{
    int temp=0;
    struct sin_link_list *last=*p;
    while(last->next)
    {
        while()
        if((last->next)<(last))
        {
            temp=last->a;
            last->a=last->next->a;
            last->next->a=temp;
        }
    }

}*/
/*
void add_mid(struct sin_link_list **p)
{
    struct sin_link_list *new=0,*last=*p;
    new=(struct sin_link_list *) calloc(1,sizeof(struct sin_link_list));
    printf("Enter the int data for add at mid..:\n");
    scanf("%d",&new->a);

    if(last==0)
    {
        
        return ;
    }           
    else
    while(last                                                                                                                                                                                                                         

}
*/
void add_end(struct sin_link_list **p)
{
    struct sin_link_list *new=0,*last=*p;

    new = (struct sin_link_list *)calloc(1,sizeof(struct  sin_link_list));
    printf("Enter the data...:\n");
    scanf("%d",&new->a);

    if(*p==0)
    {
        *p=new;
        return ;
    }
    else
    {
        while(last->next)
        {
            last=last->next;
        }
        last->next=new;
    }
}

void count_node(struct sin_link_list *p)
{
    int c=0;
    if(p==0)
    {
        printf("No nodes are present..:\n");
        return;
    }
    else{
        while(p)
        {
            c++;
            p=p->next;
        }
    }

    printf("cout of nodes are = %d\n",c);
}


void add_begin(struct sin_link_list **p)
{
    struct sin_link_list *new = (struct sin_link_list *)malloc(sizeof(struct sin_link_list));
    printf("Enter the int num..:\n");
    scanf("%d",&new->a);

    if(new->next == 0)
    {
        *p = new;
        return;
    }
    else
    {
        new->next = *p;
        *p = new;
        return;
    }
}



void print(struct sin_link_list *p)
{
    if(p==0)
    {
            printf("No node present in this linked list\n");
            return;
    }
    else
    {
            printf("list of present data is given below..:\n");
            l1:
                 printf("%d\n",p->a);
            if(p->next != 0)
            {
                p=p->next;
                goto l1;
            }
            else
            {
                 //printf("no more node are present..:\n");
                 return ;
            } 

    }

    
}
void main()
{   
    struct sin_link_list *head=0;
    int op=0;
    while(1)
    {
        printf("1)add_node_at_begin\n2)print the nodes\n");
        printf("3)count the node\n4)add_end\n5)sort the data\n");
        printf("6)delete first node\n7)del last node\n");
        printf("chose one option..:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: add_begin(&head);
            break;

            case 2: print(head);
            break;

            case 3: count_node(head);
            break;

            case 4: add_end(&head);
            break;

            //case 5:sort_node(&head);
            //break;

            case 6:del_first(&head);
            break;
            
            case 7:del_last(&head);
            break;

            default :
            printf("wrong op selected..:\n");
        }
    }    
}