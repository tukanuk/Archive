#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* header: produces a formatted header
 * INPUT: none
 * OUTPUT: a formatted header
 */ 
void header(char * lab, char * date)
{
    printf("\n%s: 60-254: Data Structures and Algorithms\n", lab);
    printf("Ben Davidson #104924033\n");
    printf("%s\n\n", date);
}

/* RandomArray - builds a random array of size arraySize
 * INPUT: array, size of array, min value, max value
 * OUTPUT: the array populated by random values
 */
void RandomArray(int a[], int arraySize, int min, int max)
{
    time_t t;
    srand(time(&t));

    for (int i = 0 ; i < arraySize ; i++)
    {
        a[i] = rand() % (max - min) + min;
    }
}

/* printArray:  Displays the contents of array to stdout 
 * INPUT:       array, array size
 * OUTPUT:      output the contents of an array to stdout
 */
int printArray(int a[], int arraySize)
{
    for (int i = 0 ; i < arraySize ; i++)
    {
        printf("%6d", a[i]);
    }

    printf("\n");

    return 0;
}

/* Swap function
 * INPUT: two array positions
 * OUTPUT: swapped array postions 
 */
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}