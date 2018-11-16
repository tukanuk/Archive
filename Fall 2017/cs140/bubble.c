#include <stdio.h>
#include <stdlib.h>	// rand(), srand()
#include <math.h> 	// floor()
#include <time.h> 	// time()

#define SIZE 10

int main(void)

{
	int a[SIZE] = {0}, i, ranNum = 0;

	time_t t;
	srand ((unsigned) time (&t));

	for (int i = 0; i < SIZE; ++i)
	{
		ranNum = ((rand() %99));
		a[i] = ranNum;
	}

	puts("Data iteshowms in original order");

	for (size_t i = 0; i < SIZE; ++i) {
		printf("%4d", a[i]);
	}

	printf("\n");
	// bubble sort
	// loop to control number of passes

	for (unsigned int pass = 1 ; pass < SIZE; ++pass) {

		// loop to control number of comparisions per pass
		for (size_t i = 0; i < SIZE - 1 ; ++i){
			if (a[i] > a[i + 1 ]){
				int hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
			}

			for (size_t j = 0; j < SIZE; ++j) {
					printf("%4d", a[j]);

			}
			printf("\n");
		}

	}

puts("\nData items in accending order");

for (size_t i = 0; i < SIZE; ++i) {
	printf("%4d", a[i]);
}

puts("");

return(0);

}

