/* Last big bubble attempt 
   Dec 11, 2017 10:55a - 11:08 */
   
#include <stdio.h>
   
int main(void)
{
	int pass, count, num, hold;
	
	printf("How many numbers do you want to sort? ");
	scanf("%d", &num);
	
	int sortSet[num];
	
	printf("Enter the numbers you want to sort: ");
	for (int i = 0 ; i < num ; ++i){
		scanf("%d", &sortSet[i]);
	}

	/* pass loop */
	
	for (pass = 0 ; pass < num  - 1 ; ++pass){
		
		/* sort loop */
		
		for (count = 0 ; count < num - 1 ; ++count){
			if (sortSet[count] > sortSet[count +1]){
				hold = sortSet[count + 1];
				sortSet[count + 1] = sortSet[count];
				sortSet[count] = hold;
			}
		}	
	}
	
	printf("Your sorted numbers are: ");
	for (int i = 0 ; i < num ; ++i){
		printf("%d, ", sortSet[i]);
	}
	
	putchar('\n');
	
	return 0;
}