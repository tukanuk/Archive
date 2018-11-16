/*
 Name:		lab9.c
 Purpose:	Lab 9
            CS254
 Author:  	Ben Davidson
            104924033
 Date:    	0718-2018 11:35
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "../sharedFunctions.h"

#define LOWER -1000
#define UPPER  1000
#define DEBUG  0

#define TIME(n) time_t start = clock(); \
                (n); \
                time_t end = clock(); \
                double runTime = (double)(end - start)/CLOCKS_PER_SEC; \
                printf("Time to run: %f seconds\n", runTime);

/** Prototypes **/
void heapify (int a[], int i, int total);
void buildHeap  (int a[], int n);
void heapSort (int a[], int n);

/* Global */
// int total;

int main (int argc, char * argv[])
{
    if (argv[1] == NULL) 
    {
        printf("usage: lab8 size_of_array\nSpecify the size of the array as a command line argument.\n");
        return 0;
    }

    /** Setup the header and the random array **/
    header("Lab 9", "July 17, 2018");
    char * finish;
    int arraySize = strtol(argv[1], &finish, 10);
    
    /* Random Array */
    int ra[arraySize];
    RandomArray(ra, arraySize, LOWER, UPPER); 
    
    /* Test Array */
    // int ra[7] = {12, 10, 20, 19, 8, 7, 15};
    
    /* Print Array */
    printf("ra[]:   ");
    if (arraySize <= 1000) printArray(ra, arraySize); // surpress large outputs
    printf("\n");

    TIME(heapSort(ra, arraySize));

    /* Print the heap sorted array */
    printf("sorted: ");
    if (arraySize > 1000) printf("\n");     // surpress large outputs
    else printArray(ra, arraySize);

    return 0;
}

void heapSort (int a[], int n)
{
    buildHeap (a, n);

    int i = n-1;
    while (i > 0)
    {
        swap(&a[0],&a[i]);
        --i;
        heapify(a, 0, i);
    }
}

void buildHeap (int a[], int n)
{
    int total = n-1;

    // starting with the non-children heapify
    for (int i = total / 2 ; i >= 0 ; i--)
    {
        heapify(a, i, total);
    }
}

void heapify (int a[], int i, int total)
{
    
    int root   = i;         // the root node
    int lChild = i * 2;     // the left child
    int rChild = i * 2 + 1; // the right child

    if (lChild <= total && a[lChild] > a[root]) // if left is greater than the root
    {
        root = lChild;
    }
    if (rChild <= total && a[rChild] > a[root]) // if right is greater that the root
    {
        root = rChild;
    }

    if (root != i) // if root has changed value then swap right and larger child
    {
        swap(&a[i], &a[root]);
        heapify(a, root, total);    // if the root changed call heapify again
    }


}