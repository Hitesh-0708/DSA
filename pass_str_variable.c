#include<stdio.h>
struct structure
{
    int a;
    int b;
};
void pass_str_var(struct structure *var)
{
    printf(" a= %d b= %d",var->a,var->b);
}

void main()
{
    struct structure var1 = {10,20};
    struct structure var2 = {30,40};

    pass_str_var(&var1);
    pass_str_var(&var2);

}