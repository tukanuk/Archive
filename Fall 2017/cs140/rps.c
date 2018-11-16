	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	int main()
	{
		srand ( time(NULL) );
		int randomNumber;
		int no1 = 0, no2 = 0, no3 = 0, no4 = 0, no5 = 0, no6 = 0, no7 = 0, no8 = 0, no9 = 0, no10 = 0;
		printf("10000 Random Numbers\n\n");
		for (int a=0;a<100;a++)
		{
			randomNumber = rand() % 10 + 1;
			printf("%d ", randomNumber );
			// random number between 0 and 10
			
			switch (randomNumber) {
				case 1 : 
							no1++; break;
				case 2 : 
							no2++; break;
				case 3 : 
							no3++; break;							
				case 4 : 
							no4++; break;							
				case 5 : 
							no5++; break;							
				case 6 : 
							no6++; break;							
				case 7 : 
							no7++; break;							
				case 8 : 
							no8++; break;							
				case 9 : 
							no9++; break;							
				default: 
							no10++; break;
				}
		}
		printf("\n\n1 chosen %d times.\n", no1);
		printf("2 chosen %d times.\n", no2);
		printf("3 chosen %d times.\n", no3);
		printf("4 chosen %d times.\n", no4);
		printf("5 chosen %d times.\n", no5);
		printf("6 chosen %d times.\n", no6);
		printf("7 chosen %d times.\n", no7);
		printf("8 chosen %d times.\n", no8);
		printf("9 chosen %d times.\n", no9);
		printf("10 chosen %d times.\n", no10);
				
		return(0);
	}