/* Name:    lab7.c
            Quicksort
   Purpose: Lab 7
   Author:  Ben Davidson
            104924033
   CS254 Lab Section
   Date:    0703-2018 10:00
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../sharedFunctions.h" // small library of personal shared functions

#define maxN  100
#define DEBUG 0
#define LOWER 0
#define UPPER 10000

/** Prototypes **/

int InsertionSort(long int a[], long int arraySize);
int QuickSort(long int a[], long p, long q);
long Partition(long int L[], long p, long q);
int RandomArray(long int a[], long int arraySize);
int printArray(long int a[], long int arraySize);
void swap (long *a, long *b);

int main (int argc, char *argv[])
{
    if (argv[1] == NULL) 
    {
        printf("usage: lab7 size_of_array\nSpecify the size of the array as a command line argument.\nArray sizes larger than 1000 have output suppressed.\n");
        return 0;
    }

    /** Setup the header and the random array **/
    header("Lab 7", "July 3, 2018");
    char * finish;
    long int arraySize = strtol(argv[1], &finish, 10);
    long int ra[arraySize];
    RandomArray(ra, arraySize);
    // long int ra[8] = {5, 3, 2, 6, 4, 1, 3, 7};
    if (arraySize <=1000) printArray(ra, arraySize);
    long ia[arraySize];                         // make a copy of the array for the insertion sort
    memcpy(ia, ra, arraySize*sizeof(long));
    
    /** Test the Insertion Sort **/
    time_t start = clock();                                                                     // record the start time
    InsertionSort(ia, arraySize);
    time_t end = clock();                                                                       // record the end time
    printf("\nInsertion Sort\nTime to run: %f seconds\n\n", (double)(end - start)/CLOCKS_PER_SEC );  // display the time to run in seconds
    if (arraySize <= 1000) printArray(ia, arraySize);                                           // if array is 1000 or smaller print the output

    start = clock();                                                                            // record the start time
    QuickSort(ra, 0, arraySize-1);
    end = clock();                                                                              // record the start time
    printf("\nQuick Sort\nTime to run: %f seconds\n\n", (double)(end - start)/CLOCKS_PER_SEC );     // display the time to run in seconds
    if (arraySize <= 1000) printArray(ra, arraySize);
   
    return 0;
}

int QuickSort(long int L[], long p, long q)
{
    long r;
    if (p < q)                  // if p and q haven't crossed each other or met
    {
        r = Partition(L, p, q);
        QuickSort(L, p, r);     // left half of partition
        // printf("TEST\n");    
        QuickSort(L, r+1, q);   // right half of partition
    }

    return 0;
}

long Partition(long int L[], long p, long q)
{
    long a = L[p];      // the initial pivot
    long *rp;
    long *lp;
    lp = &L[p-1];       // lp to the beginning;
    rp = &L[q+1];       // rp to the end;
    // int counter = 0;
    if (DEBUG) printf("pivot: %ld\n", a);
         
    while (lp < rp) 
    {
        do                  // move rp to the left until rp <= a
        {
            rp--;
        } while (*rp > a);

        do                  // move lp ro the right until lp >= a
        {
            lp++;
        } while (*lp < a);

        if (lp < rp) swap(lp, rp);
        // if (DEBUG) printf("partition count: %d new array: \n", counter++);
        if (DEBUG) printArray(L, q+1);
    } 

    /** Converts the rp to an index value to pass back to the QuickSort function **/
    long setIndex =  rp - &L[0];                        // rp - the address of the 0 index of the array
    if (DEBUG) printArray(L, setIndex+1);
    if (DEBUG) printf("NEW rp is: %ld\n\n", setIndex);

    return setIndex;

    
}

/* Swap function
 */
void swap (long *a, long *b)
{
    if (DEBUG) printf("swaping %ld and %ld... ", *a, *b);
    long temp = *a;
    *a = *b;
    *b = temp;
    if (DEBUG) printf("now %ld and %ld!\n", *a, *b);
}


/* RandomArray - builds a random array of size arraySize
 * INPUT: array, size of array, min value, max value
 * OUTPUT: the array populated by random values
 */
int RandomArray(long int a[], long int arraySize)
{
    time_t t;
    srand(time(&t));

    for (long int i = 0 ; i < arraySize ; i++)
    {
        a[i] = rand() % (UPPER - LOWER) + LOWER;
        if (DEBUG) printf("%ld ", a[i]);
    }

    if (DEBUG) 
    {
        printf("\n"); 
        for (int i = 0 ; i < 80 ; i++)
        {
            printf("*");
        } 
        printf("\n\n");
    }

    return 0;
}

int InsertionSort(long int a[], long int arraySize)
{
    int i = 1;
    
    while (i <= arraySize - 1)
    {
        int temp = a[i];
        int j = i;
        while (j > 0 && a[j-1] > temp)
        {
            a[j] = a[j-1];
            j--;
        }

        a[j] = temp;
        i++;
    }
    return 0;
}

/* printArray 
 * output the contents of an array to screen
 */
int printArray(long int a[], long int arraySize)
{
    for (long i = 0 ; i < arraySize ; i++)
    {
        printf("%9ld", a[i]);
    }

    printf("\n");

    return 0;
}