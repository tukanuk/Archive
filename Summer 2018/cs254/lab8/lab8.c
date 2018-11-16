/*
 Name:		lab8.c
 Purpose:	Lab 8
            CS254
 Author:  	Ben Davidson
            104924033
 Date:    	0709-2018 15:15
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "../sharedFunctions.h"

#define LOWER  -50
#define UPPER   50
#define DEBUG   0

/** Prototypes **/
void RandomAccArray(int a[], int arraySize, int min, int max);
void binarySearch(int b[], int low, int high, int searchNum);
int QuickSort(int a[], int p, int q);
int Partition(int L[], int p, int q);

int main (int argc, char * argv[])
{
    if (argv[1] == NULL) 
    {
        printf("usage: lab8 size_of_array\nSpecify the size of the array as a command line argument.\n");
        return 0;
    }

    /** Setup the header and the random array **/
    header("Lab 8", "July 9, 2018");
    char * finish;
    int arraySize = strtol(argv[1], &finish, 10);
    int ra[arraySize];
    RandomAccArray(ra, arraySize, LOWER, UPPER); 
    QuickSort(ra, 0, arraySize-1);
    // int ra[9] = {-5, -4, 0, 3, 5, 6, 7, 8, 10};
    printf("A[]: ");
    printArray(ra, arraySize);

    printf("\nBinary Search\n");

    // build the b array
    int b[arraySize];
    for (int j = 0 ; j < arraySize ; j++)
    {
        b[j] = ra[j] - j;
    }
    printf("B[]: ");
    printArray(b, arraySize);

    binarySearch(b, 0, arraySize, 0);

    return 0;
}

void RandomAccArray(int a[], int arraySize, int min, int max)
{
    int previous = 0;
    time_t t;
    srand(time(&t));

    for (int i = 0 ; i < arraySize ; i++)
    {
        a[i] = rand() % abs(min - max) + min;
        previous = a[i];
    }
}


void binarySearch(int b[], int low, int high, int searchNum)
{
    int midpoint = floor( (low + high) / 2);
    // printf("l: %d[%d] h: %d[%d] mp: %d [%d]\n", b[low], low, b[high-1], high, b[midpoint], midpoint);
    int i;

    // base case
    if (b[midpoint] == searchNum)  // || b[low] == searchNum || b[high] == searchNum)
    {
        printf("FOUND A MATCH!\n");
        return;
    }
    else if (high - low == 0)
    {
        printf("nope\n");
        return;
    }

    // recursive case 
    if ( b[midpoint] > searchNum)
    {
        return binarySearch(b, low, midpoint, searchNum);
    }
    else if (b[midpoint] < searchNum)
    {
        return binarySearch(b, midpoint+1, high, searchNum);
    }


}

int QuickSort(int L[], int p, int q)
{
    int r;
    if (p < q)                  // if p and q haven't crossed each other or met
    {
        r = Partition(L, p, q);
        QuickSort(L, p, r);     // left half of partition
        // printf("TEST\n");    
        QuickSort(L, r+1, q);   // right half of partition
    }

    return 0;
}

int Partition(int L[], int p, int q)
{
    int a = L[p];      // the initial pivot
    int *rp;
    int *lp;
    lp = &L[p-1];       // lp to the beginning;
    rp = &L[q+1];       // rp to the end;
    // int counter = 0;
    if (DEBUG) printf("pivot: %d\n", a);
         
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
    int setIndex =  rp - &L[0];                        // rp - the address of the 0 index of the array
    if (DEBUG) printArray(L, setIndex+1);
    if (DEBUG) printf("NEW rp is: %d\n\n", setIndex);

    return setIndex;
}
