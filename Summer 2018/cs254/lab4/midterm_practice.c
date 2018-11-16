#include <stdio.h>
#include <stdlib.h>

unsigned long int betterFib(int n);

int knownFib[100] = {0};

int main(int argc, char *argv[])
{
    char * end;
    int n = strtol(argv[1], &end, 10);
    printf("%lu\n\n", betterFib(n) ) ;
    return 1;
}

unsigned long int betterFib(int n)
{
    if (knownFib[n] != 0)
    {
        return knownFib[n];
    }    
    int temp = n;
    if (n < 0) return 0;
    if (n > 1)
    {
        temp = betterFib(n - 1 ) + betterFib(n - 2);
    }
    knownFib[n] = temp;

    return knownFib[n];

    
}