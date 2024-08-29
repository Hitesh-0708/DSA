#include <stdio.h>
#include <stdlib.h>
struct csll
{
    int num;
    struct csll *next;
};

void add_beg(struct csll **head)
{
    struct csll *new, *last = *head;
    new = (struct csll *)calloc(1, sizeof(struct csll));
    printf("Enter the data..:\n");
    scanf("%d", &new->num);

    if (last == 0)
    {
        *head = new;
        new->next = *head;
    }
    else
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = new;
        new->next = *head;
        *head = new;
    }
}

void print(struct csll *head)
{
    struct csll *last = head;
    if (head == 0)
    {
        printf("No nodes are present..:\n");
        return;
    }
    else
    {
        printf("Availble data is present below..:\n");
        do
        {
            printf("%d\n", last->num);
            last = last->next;
        } while (last != head);
    }
}
void add_end(struct csll **head)
{
    struct csll *new, *last = *head;
    new = (struct csll *)calloc(1, sizeof(struct csll));
    printf("Enter the data..:\n");
    scanf("%d",&new->num);

    if (last == 0)
    {
        *head = new;
        new->next = *head;
    }
    else
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        new->next = *head;
        last->next = new;
    }
}

void add_mid(struct csll **head)
{
    int pos=0;
    struct csll *new,*last=*head;
    new=(struct csll *)calloc(1,sizeof(struct csll));
    printf("Enter the data and pos where to add new node..:\n");
    scanf("%d %d",&new->num,&pos);
    if(last==0)
    {
       printf("Pls first add node after the we can add in middle..:\n");
       return;
    }
    else
    {
        while((--pos))
        {
            int i=0,j=0;
            if(last->next==*head)
            {
              //  printf("dummy=%d",i++);
                new->next=*head;
                return;
            }
            else
            {
                //printf("dummy==%d\n",j++);
                last=last->next;
            }
        }
        new->next=last->next;
        last->next=new;
    }
}
void main()
{
    struct csll *head = 0;
    int op = 0;
    while (1)
    {
        printf("1)add at beg\t2)print\t3)add end\t4)add mid\n");
        printf("Chose ont option..:\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            add_beg(&head);
            break;

        case 2:
            print(head);
            break;
        
        case 3:
        add_end(&head);
        break;

        case 4:
        add_mid(&head);
        break;

        default:
            printf("Wrong option selected..:\n");
        }
    }
}