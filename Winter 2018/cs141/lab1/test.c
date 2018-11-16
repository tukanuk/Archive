#include <stdio.h>

void PrintTable (int);
int main (void)
{
    PrintTable(5);
    return 0;
}
void PrintTable (int n)
{
    for (int c = 1 ; c <= n ; c++)
    {
        PrintTable(c);
        printf("\n");
    }
}