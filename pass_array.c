#include<stdio.h>
struct pass_array{
    int a;
    char ch;
};

void ary_pass(struct pass_array array[2])
{
    int i;
    for(i=0;i<2;i++)
    {
        printf(" %d %c\n",array[i].a,array[i].ch);
    }
}

void main()
{
 struct pass_array a[2]={{1,'A'},{3,'B'}};
 ary_pass(a);

}