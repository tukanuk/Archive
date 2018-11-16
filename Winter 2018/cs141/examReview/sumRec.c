#include <stdio.h>

int sumRec(int array[], int index, int size)
{
	// base case
	if (index == size)
	{
		return 0;
	}
	// recursive case
	else
	{
		return array[index++] + sumRec(array, index, size);
	}
}

int main()
{
	int vals[] = {1, 2, 3, 4, 5, 6, 7, 1000};
	int size = sizeof(vals)/sizeof(vals[0]);
	printf("Sum: %d\n", sumRec(vals, 0, size) );

	return 0;
}
		
