#include <stdio.h>

void printRec(int array[], int index, int size)
{
	//base case
	if (index == size)
	{
		return;
	}
	else
	{
	// recursive case
		printf("%d ", array[index]);
		return printRec(array, ++index, size);
	}

}

int main()
{
	int vals[] = {1, 2, 3, 4, 5, 6, 9};
	int size = sizeof(vals)/sizeof(vals[0]);
	//printf("%d", size);
	printRec(vals, 0, size);

	return 0;
}
