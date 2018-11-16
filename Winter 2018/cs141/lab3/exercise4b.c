/* Name: exercise4b.c
 * Purpose: Lab 3: Pointers in C
 * Author: Ben Davidson
 * 	   104924033
 * CS141 Lab Section 
 * Date: 0206-2018 3:43PM
 */
 

#include <stdio.h>

#define DEBUG 0 // enables extra output to aid debugging
#define ROW 1 
#define COL 10 
#define SORTORDER -1 // 1 for ascending -1 for decending
#define MAX 20 // max size of array


/*** protoypes functions  ***/

void Swap (int *valAptr, int *valBptr);
int Triple (int *triplePtr);
void BubbleSort (int * const array, const int c, int order);
void PrintArray (int *ptrA, int c);

void PopEven (int *array, int size);
void ArrayTriple(int *ptrA, int c);
void PtrBubbleSort(int *ptrA, int c, int sort);
                   
int main ()   
{                  
	int a = 2; // for swap function in part 2
	int b = 4; // for swap function in part 2
	int d = 10; // for triple function in part 2
	int array[COL] = {1, 5657, 4, 9, 364, 67, 235, 973, 234, 3}; // for buble sort in part 2
	int NumList[MAX] = {0};

	int *ptrArray  = array;
	int *ptrNumList = NumList; // creates an int pointer to the array NumList


	// Swap
	Swap(&a, &b);
	printf("SWAP a: %d (2) b: %d (4)\n", a, b);

	// Triple
	Triple(&d);
	printf("TRIPLE d: %d (3)\n", d);

	// Bubble Sort
	printf("\nOriginal array: \n");
	PrintArray(ptrArray, COL);
	BubbleSort(array, COL, SORTORDER);
	PrintArray(ptrArray, COL);

	// Populate NumList array with even numbers, triple values and
	// sort in both direcitions
	printf("\nNumList Array:\n");
	PrintArray(ptrNumList, MAX);
	
	PopEven(ptrNumList, MAX);
	PrintArray(ptrNumList, MAX);
	
	ArrayTriple(ptrNumList, MAX);
	PrintArray(ptrNumList, MAX);
	
	PtrBubbleSort(ptrNumList, MAX, -1);
	PrintArray(ptrNumList, MAX);
	
	PtrBubbleSort(ptrNumList, MAX, 1);
	PrintArray(ptrNumList, MAX);

	return 0;
}

/* Swap: takes int pointers and exchanges values
 * INPUT: two int pointers
 * OUTPUT: none
 */
void Swap (int *aptr, int *bptr)
{
	if (DEBUG) printf("a: %p (2) b: %p (4)\n", aptr, bptr);
	
	int temp = *aptr;
	*aptr = *bptr;
	*bptr = temp;

	if (DEBUG) printf("a: %p (2) b: %p (4)\n", aptr, bptr);

}

/* Triple: takes input and triples its value
 * INPUT: int pointer
 * OUTPUT: a value triple of the input 
 */
int Triple (int *triplePtr)
{ 
	return *triplePtr *= 3;
}


/* BubbleSort: takes a int array, it's size and a sort order and sorts
 * INPUT: array[], COL size of array, and sortOrder. 
 *        1 is ascending, -1 decending
 * OUTPUTL: none
 */
void BubbleSort (int * const array, const int c, int sortOrder)
{
	//pass loop
	for (unsigned int pass = 0 ; pass < c - 1 ; pass++)
	{
		// sort loop
		for (int j = 0 ; j < c - 1 ; j++)
		{
			// swap direction
			if (sortOrder == 1)
			{
				if (array[j] > array[j+1])
				{
					Swap(&array[j], &array[j+1]);
				}
			} else
			{
				if (array[j] < array[j+1])
				{
					Swap(&array[j], &array[j+1]);
				}
			}
		}
	}
}


/* PrintArray: takes a int array and prints it to the screen.
 * INPUT: array[], COL size of array
 * OUTPUTL: outputs contenets of array to screen
 */
void PrintArray (int *ptrA, int c)
{
	int i;

	for (i = 0 ; i < c ; i++)
	{
		printf("%6d", *(ptrA + i));
	}
	
	printf("\n");
}

/*
 *	PopEven: populate an array with even numbers starting at 4
 *		INPUT: an int * array, the size of the array
 *		OUTPUT: a popualted array
*/
void PopEven (int *array, int size)
{
	int inc = 4;

	for (int i = 0 ; i < size ; i++)
	{
		*(array + i) = inc;

		inc += 2;
	}	
}

/*
 *	ArrayTripe: triples each element in an array
 *		INPUT: int *array, size of array
 *		OUTPUT: triples each element
*/
void ArrayTriple(int *ptrA, int c)
{
	for (int i = 0 ; i < c ; i++)
	{
		*ptrA *= 3;
		ptrA++; 
	}
}

/*
 *	ptrBubbleSory: Performs a bubble sort on an array
 *		INPUT: int *array, size, order
 *		OUTPUT: sorts the array accordign to the order
*/
void PtrBubbleSort(int *ptrA, int c, int sort)
{
	// pass loop
	for (int i = 0 ; i < c - 1 ; i++)
	{
		// sort loop
		for (int j = 0 ; j < c - 1 ; j++)
		{
			//sort and swap according to sort direction
			if (sort == 1)
			{
				if (*(ptrA + j) > *(ptrA + j + 1) )   
				{
					Swap( (ptrA + j) , (ptrA + j + 1) );
				}
			} 
			else 
			{
				if (*(ptrA + j) < *(ptrA + j + 1) )
				{
					Swap( (ptrA + j) , (ptrA + j + 1) );
				}
			}
		}
	}
}
