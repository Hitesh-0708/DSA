#include <stdio.h>
#include <stdlib.h>
struct dll
{
    struct dll *prev;
    int num;
    struct dll *next;
};
int c;
void add_begin(struct dll **head)
{
    struct dll *new = (struct dll *)calloc(1, sizeof(struct dll));
    printf("Enter the data ..:\n");
    scanf("%d", &new->num);
    if (*head == 0)
    {
        *head = new;
    }
    else
    {
        (*head)->prev = new;
        new->next = *head;
        *head = new;
    }
}

void print(struct dll *head)
{
    printf("present data is given below:\n");
    if (head == 0)
    {
        printf("No node's are present at moment..:\n");
        return;
    }
    else
    {
        while (head)
        {
            printf("%d\n", head->num);
            head = head->next;
        }
    }
}

void add_end(struct dll **head)
{
    struct dll *last = *head, *new = (struct dll *)calloc(1, sizeof(struct dll));
    printf("Enter the data..:\n");
    scanf("%d", &new->num);

    if (*head == 0)
    {
        *head = new;
    }
    else
    {
        while (last->next)
        {
            last = last->next;
        }
        new->prev = last;
        last->next = new;
    }
}

int count(struct dll *head)
{
    if (head == 0)
    {
        return 0;
    }
    else
    {
        while (head)
        {
            c++;
            head = head->next;
        }
        printf("count of node is %d\n", c);
        return c;
    }
}
void add_in_mid(struct dll **head)
{
    struct dll *new, *last = *head;
    int pos = 0, count1 = 0;
    new = (struct dll *)calloc(1, sizeof(struct dll));

    printf("Enter the data abd pos..:\n");
    scanf("%d %d", &new->num, &pos);

    if (last == 0)
    {
        *head = new;
        printf("New node is created in mid fn...:\n");
    }
    else
    {
        count1 = count(last);
        printf("count in add in mid fn..:%d\n", count1);
        if (count1 < pos)
        {
            printf("Sorry this position yet not created..:\n");
            return;
        }
        else
        {

           /* if (pos == 0)
            {
                add_begin(&last);
                return;
            }*/
            while (pos--)
            {
                last = last->next;
            }
            new->next = last->next;
            new->prev = last;
            if (last->next != 0)
                last->next->prev = new;
            last->next = new;
        }
    }
}
void main()
{
    struct dll *head = 0;
    int op = 0;
    while (1)
    {
        printf("1)add at begin\t2)print\t3)add at end\t4)add in middle\n");
        printf("chose one option..:\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            add_begin(&head);
            break;

        case 2:
            print(head);
            break;
        case 3:
            add_end(&head);
            break;

        case 4:
            add_in_mid(&head);
            break;

        default:
            printf("wrong option selected..:\n");
            return;
            {


//kkjkjk
//

            }
        }
    }
}