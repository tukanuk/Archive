#include <stdio.h>

int test (int a)
{
    return ++a;
}
void main()
{
    int a= 3;
    a++;
    printf("%d\n", a);
    a = test(a);
    printf("%d\n", a);
}