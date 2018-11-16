
#include <stdio.h>
void main()
{
   /* ARRAYS 1D */

   int A[20];
   int B[] = {1, 2, 3, 5, 7, 11};

   int i, j = 0, k = 2;

   for (i = k; i < 10*k; i+=5)
   {
      A[i] = B[j++];
      printf("A[%d]\t<=>\"%d\"\n", i, A[i]);
   }
   while (--B[j] != 1)
      printf("B[%d] = %d\n", j, B[j]);
}

