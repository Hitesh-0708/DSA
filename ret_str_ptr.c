#include<stdio.h>
#include<stdlib.h>
struct str_name{
    int a;
    int b;
};
void print(struct str_name *ptr)
{
    printf(" a=%d b=%d\n",ptr->a,ptr->b);
}

struct str_name * fun(int a, int b)
{
    struct str_name *ptr=(struct str_name * ) malloc(sizeof(struct str_name));
    ptr->a=++a;
    ptr->b=b+5;

    return ptr;
}

void main()
{
    struct str_name *p1,*p2;
    p1=fun(10,20);
    p2=fun(30,40);

    print(p1);
    print(p2);
}