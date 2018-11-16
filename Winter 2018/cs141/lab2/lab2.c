/* Name: lab2.c
   Purpose: Lab 2: Advanced Arrays
   Author: Ben Davidson
           104924033
   CS141 Lab Section
   Date: 0116-2018 2:44p
*/

#define ROW 10
#define COL 5
#define RMIN 1
#define RMAX 100
#define DEBUG 0

#include "commonFunctions.h"

int main()
{
    int A[ROW][COL]; // creates the main array

    while (ReallyBasicMenu(A, ROW, COL) != 7)
    {

    };

    if (DEBUG == 1)
    {
        // Fill an array with zeros and display it
        printf("\nZeros:\n");
        ZeroPopulate2DArray(A, ROW, COL);
        Print2DArray(A, ROW, COL);

        // Fill the array with random numbers and display it
        printf("\nRandom integers between %d and %d:\n", RMIN, RMAX);
        RanPopulate2DArray(A, ROW, COL, RMIN, RMAX);
        Print2DArray(A, ROW, COL);

        // Sort the array from lowest interger to highest
        printf("\nThe sorted array is: \n");
        Sort2DArray(A, ROW, COL, 1);
        Print2DArray(A, ROW, COL);

        // Perform a linear search of the array and return results
        int key = keyValue(RMIN, RMAX);
        printf("The value %d was %s\n", key, Search2DArray(A, ROW, COL, key) ? "found" : "not found");

        // Shifts the values of the array left and prints the result
        printf("\nThe shifted array is: \n");
        Shift2DArrayLeft(A, ROW, COL);
        Print2DArray(A, ROW, COL);
    }

    printf("\n");

    return 0;
}

