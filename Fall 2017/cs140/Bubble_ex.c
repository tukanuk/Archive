/* Bubble-ex1.c 			      */
/* time start: Dec 5, 4:25 - 4:38 */

#include <stdio.h>

// int sorter[] = {3, 7, 9, 56, 128, 5, 7, 7, 22, 25};

int main(){

	int p, s, holder, i, n;
	
	printf("\n");
	
	printf("How many numbers do you want ot sort?: ");
	scanf("%d", &n);
	
	int sorter[n];
	
	printf("Enter the numbers you would like to sort: ");
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &sorter[i]);
	}
		
	int aSize = sizeof(sorter) / sizeof(sorter[0]);
	printf("%d\n", aSize);
	
	/* Pass loop */
	for (p = 0 ; p < aSize - 1 ; ++p ){  		// used i < COUNT
		
		/* Sort loop */
		for (s = 0 ; s < aSize - 1 ; ++s){
			if (sorter[s] > sorter[s + 1]){
				holder = sorter[s + 1];			// sort instead of "sorter"
				sorter[s + 1] = sorter[s];
				sorter[s] = holder;
			}
		}
	}
	
	for (i = 0 ; i < aSize ; ++i){
		printf("%d, ", sorter[i]); 			// no new line
	}
		printf("\n\n");
		
	return (0);
}