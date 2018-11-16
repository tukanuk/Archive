#include <stdio.h>
#include <stdlib.h>	// rand(), srand()
#include <math.h> 	// floor()
#include <time.h> 	// time()

#define LOWER 2
#define UPPER 10
#define SAMPLE 1110

int main(void)  
{
     int ranNum, i, j;	/* setting up variables, adding an extra row and colunm to the array to hold sums */
     int counter[SAMPLE] = {0};

    time_t t;									    /* setting up random number generator	*/ 	
 	srand((unsigned) time (&t));

 	for (int i = 0; i < SAMPLE; i++)					
 	{
 			ranNum = (rand() % (UPPER - LOWER) + LOWER);			// -1 is task specific modifier 
            printf("%d \n", ranNum);
            counter[ranNum] += 1;
     };

     printf("\n\nRough distribution check:\n");

     for (i = 0 ; i < UPPER ; i++){
         printf("%d: %d\t", i, counter[i]);
     }

     printf("\n");
     
return 0;

}