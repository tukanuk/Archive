/* Name: labExam1.c
   Purpose: Lab Exam #1
   Author: Ben Davidson
           104924033
   CS141 Lab Section
   Date: 0116-2018 2:44p
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 15
#define RMIN 1
#define RMAX 100

#define DEBUG 0

/******************** Protoype Functions ********************/

void ZeroPopulate2DArray(int A[][COL], int current_r, int current_c);
void RanPopulate2DArray(int A[][COL], int current_r, int current_c, int min, int max);
void Print2DArray(int A[][COL], int current_r, int current_c);
int Search2DArray(int A[][COL], int current_r, int current_c, int key);
int keyValue(int min, int max);
void Sort2DArray(int A[][COL], int r, int c, int order);

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

/*
 *	ZeroPopulate2DArray: Zeros out an array
 *		INPUT: An Array, the number of rows and columns
 *		OUTPUT: A array full of '0's.
*/  
void ZeroPopulate2DArray(int A[][COL], int r, int c)
{
  int current_r; // counter to track the current row
  int current_c; // counter to track the current column

  for (current_r = 0; current_r < r; current_r++)
  {
    for (current_c = 0; current_c < c; current_c++)
    {
      A[current_r][current_c] = 0;
    }
  }
}


/*
 *	RanPopulate2DArray: populate a 2D array with random values in the given range
 *		INPUT: a 2D array, the rows and columns of the array and a min and max
 *           for the random range
 *		OUTPUT:  an array of random numbers
*/
void RanPopulate2DArray(int A[][COL], int r, int c, int min, int max)
{
  int current_r; // counter to track the current row
  int current_c; // counter to track the current column

  srand(time(NULL));

  for (current_r = 0; current_r < r; current_r++)
  {
    for (current_c = 0; current_c < c; current_c++)
    {
      A[current_r][current_c] = (rand() % ( max - min + 1) + min);
    }
  }
}

/*
 *	Print2DArray: prints a 2D array
 *		INPUT: The array to print and its number of rows and columns
 *		OUTPUT: An 2D array
*/
void Print2DArray(int A[][COL], int r, int c)
{
  int current_r; // counter to track the current row
  int current_c; // counter to track the current column

  for (current_r = 0; current_r < r; current_r++)
  {
    for (current_c = 0; current_c < c; current_c++)
    {
      printf("%6d", A[current_r][current_c]);
    }

    printf("\n");
  }
}

/*
 *	Search2DArray: Searches an array for the inputed key
 *		INPUT: An array, it's number of rows and columns and a search key
 *		OUTPUT: Returns 1 if the key was found, 0 if it wasn't
*/
int Search2DArray(int A[][COL], int r, int c, int key)
{

  int current_r; // counter to track the current row
  int current_c; // counter to track the current column

  if (DEBUG)
    printf("search for %d...", key);

  for (current_r = 0; current_r < r; current_r++)
  {
    for (current_c = 0; current_c < c; current_c++)
    {
      if (A[current_r][current_c] == key)
      {
        return 1;
      }
    }
  }

  return 0;
}

/*
 *	keyValue: A request for input in a range of integers
 *		INPUT: the min and max values allowed
 *		OUTPUT: the integer chosen as the key
*/
int keyValue(int min, int max)
{
  int key = 0;

  do
  {

    printf("\nEnter a search between %d and %d: ", min, max);
    scanf("%d", &key);

  } while (key < min || key > max);

  return key;
}

/*
 *	Sort2DArray: Sorts a 2D array from smallest integer to largest
 *		INPUT: An array, number of rows and colums
 *		OUTPUT: a sorted array
*/
void Sort2DArray(int A[][COL], int rSize, int cSize, int order)
{
  int current_r; // counter to track the current row
  int current_c; // counter to track the current column
  int sr;        // sublist row index
  int sc;        // sublist column index
  int minR;      // row index where min was found
  int minC;      // column index where min was found

  int tmp; // tmp swapping

  for (current_r = 0; current_r < rSize ; current_r++)
  {
    for (current_c = 0; current_c < cSize ; current_c++)
    {
      // the current elment is the smallest
      minR = current_r;
      minC = current_c;

      // search the sublist for a new min
      sc = current_c + 1;
      for (sr = current_r; sr < rSize; sr++, sc = 0)
      {
        for ( ; sc < cSize ; sc++)
        {
          //find a new min
          if (A[sr][sc] < A[minR][minC])
          {
            minR = sr;
            minC = sc;
          }
        }
      }

      // swap min and current
      tmp = A[current_r][current_c];
      A[current_r][current_c] = A[minR][minC];
      A[minR][minC] = tmp;
    }
  }
  
}