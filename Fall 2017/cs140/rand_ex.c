	#include <stdio.h>
	#include <stdlib.h> // srand and rand
	#include <time.h>
	
	int main (void)
	{
		srand(time(NULL)); // use current time for random generator
		
		for (int i = 0 ; i < 50 ; ++i)
		{
			int random_variable = (rand() % 9 + 2);
			printf("%3d ", random_variable);
		}
		printf("\n");
		return 0;
	}
