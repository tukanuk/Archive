#include <stdio.h>

void mysterySort(int a[], int l, int r);

void swap (int *a, int *b);

int main() 
{
    int a[] = {5, 60, 2, 25, 55, 1};

    mysterySort(a, 0, 5);

    for (int i = 0 ; i < 6; i++)
    {
        printf("%d, ", a[i]);
    }

    int c = 5;
    int d = 6;

    swap (&c, &d);

    printf ("\n\n%d %d\n\n", c, d);
}

void mysterySort(int a[], int l, int r)
{
    for (int i=l; i < r; i++)
    {
        int min = i;
        for (int j = i+1; j<r; j++)
        {
            if (a[j] < a[min]) min = j;
            swap(&a[i], &a[min]);
        }
      }
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}