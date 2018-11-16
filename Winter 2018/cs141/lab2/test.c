/* Name: lab2.c
   Purpose: Lab 2: Advanced Arrays
   Author: Ben Davidson
           104924033
   CS141 Lab Section
   Date: 0116-2018 2:44p
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
#include "commonFunctions.h"

// #define ROW 10
// #define COL 15
// #define RMIN 1
// #define RMAX 100

// #define DEBUG 0

/******************** Protoype Functions ********************/

// void ZeroPopulate2DArray(int A[][COL], int current_r, int current_c);
// void RanPopulate2DArray(int A[][COL], int current_r, int current_c, int min, int max);
// void Print2DArray(int A[][COL], int current_r, int current_c);
// int Search2DArray(int A[][COL], int current_r, int current_c, int key);
// int keyValue(int min, int max);
// void Sort2DArray(int A[][COL], int r, int c, int order);

int main()
{
  int A[ROW][COL]; // main array

  printf("\nZeros:\n");
  ZeroPopulate2DArray(A, ROW, COL);
  Print2DArray(A, ROW, COL);
  
  printf("\nRandom integers between %d and %d:\n", RMIN, RMAX);
  RanPopulate2DArray(A, ROW, COL, RMIN, RMAX);
  Print2DArray(A, ROW, COL);

  int key = keyValue(RMIN, RMAX);
  printf("The value %d was %s\n", key, Search2DArray(A, ROW, COL, key) ? "found" : "not found");

  printf("\nThe sorted array is: \n");  
  Sort2DArray(A, ROW, COL, 1);
  Print2DArray(A, ROW, COL);

  return 0;
}