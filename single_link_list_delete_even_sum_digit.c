#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void add_node(struct node **head, int data)
{
    struct node *new = (struct node *)calloc(1, sizeof(struct node));
    new->data = data;

    if (*head == 0)
    {
        *head = new;
        return;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = 0;
    }
}

int find_sum(int num)
{
    int sum = 0, c = 0;
    while (num != 0)
    {
        c = num % 10;
        sum = sum + c;
        num = num / 10; 
    }
    return sum;
}

void print_list(struct node *head)
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void find_and_delete_even_sum_digit(struct node **head)
{
    int num = 0, sum = 0, c = 0;
    struct node *current = *head,*prev=0,*t;
    while (current != 0)
    {
        sum = find_sum(current->data);
        if (sum % 2 == 0)
        {
            // deleting the even digits..
            if (prev==0)
            {
                *head = current->next;
                free(current);
                current = *head;
            }
            else
            {
                prev->next=current->next;
                free(current);
                current = prev->next;
            }
        }
        // link creating the odd digits..
        else
        {
            prev=current;
            current=current->next;
        }
    }
    print_list(*head);
}
    void main()
    {
        struct node *head = 0;
        int op, data;
        while (1)
        {
            printf("1. Add node\n2. Print list\n3. Find and delete even sum digit\n4. Exit\n");
            printf("Enter your choice:\n");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("Enter data:\n");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                find_and_delete_even_sum_digit(&head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                break;
            }
        }
    }