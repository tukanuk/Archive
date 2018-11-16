
#include <stdio.h>
void main()
{
   /* ARRAYS 2D */

   int A[5][3];
   int a = 5, b = 3;
   int i, j;
   for (i=a-1;a>=0; a--, b+=2)
      for(j = --b;b>=0; b--)
      {
         A[i][j] = a + b;
         printf("%d\n", A[i][j]);
      }
}


