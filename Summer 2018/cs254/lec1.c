#include <stdio.h>

int main()
{
    int a[4] = {3, 4, 2, 1};
    int i=0;
    
    for (int k = 0 ; k < 3 ; k++)
    {
        i = 0;
        while (i < 3)
        {
            if (a[i] > a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
            i++;
        }
    }

    for (int j = 0 ; j < 4; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");

    return 0;
}