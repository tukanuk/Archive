/* (c) Dr. Ziad Kobti, 2016. All Rights Reserved.
   Permission to use this file for educational purposes is granted
   to students and instructors of the 60-141 class, University of Windsor.
   You may not replicate any part of this code in your assignment submission
*/

#include <stdio.h>
#include "commonFunctions.h"

#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

#define ROW 5
#define COL 10

/* populate an array with Random integers between min and max
   Input: A 2D Array, number of rows and columns of the array as positive integers,
     and the min and max values for the range of random numbers used to populate it
   Output: will alter the contents of the array and populate it with random numbers
*/

void PopulateArray2DRandom(int A[][COL],
                    const unsigned int r, const unsigned int c,
                    const int min, const int max);

void PopulateArray2DRandom(int A[][COL],
                    const unsigned int r, const unsigned int c,
                    const int min, const int max)
{
  int current_row;  // counter to track the current row in the array
  int current_col;  // counter to track the current column in the array

  for (current_row = 0; current_row < r; current_row++)
  {
      for (current_col = 0; current_col < c; current_col++)
      {
          A[current_row][current_col] = generateRandom(min, max);
      } // end for
  }// end for
}

/* populate an array with a given value parameter
   Input: A 2D Array, number of rows and columns of the array as positive integers,
     and the value used to populate it
   Output: will alter the contents of the array and populate it with the value given
*/
void PopulateArray2D(int A[][COL],
                    const unsigned int r, const unsigned int c,
                    const int value);

void PopulateArray2D(int A[][COL],
                    const unsigned int r, const unsigned int c,
                    const int value)
{
  int current_row;  // counter to track the current row in the array
  int current_col;  // counter to track the current column in the array

  for (current_row = 0; current_row < r; current_row++)
  {
      for (current_col = 0; current_col < c; current_col++)
      {
          A[current_row][current_col] = value;
      } // end for
  }// end for
}

/* Display the contents of an array in a tabular format
   Input: A 2D Array, number of rows and columns of the array as positive integers
   Output: will display its contents one row per line
*/
void DisplayArray2D(int A[][COL],
                    const unsigned int r, const unsigned int c);

void DisplayArray2D(int A[][COL],
                    const unsigned int r, const unsigned int c)
{
  int current_row;  // counter to track the current row in the array
  int current_col;  // counter to track the current column in the array

  for (current_row = 0; current_row < r; current_row++)
  {
      for (current_col = 0; current_col < c; current_col++)
      {
          printf("%d ", A[current_row][current_col]);
      } // end for
      printf("\n");
  }// end for
}

int SumRow(const int A[][COL], int r, int c, int row);
int SumRow(const int A[][COL], int r, int c, int row)
{
  int current_row;  // counter to track the current row in the array
  int current_col;  // counter to track the current column in the array
  int total=0;      // total of the sum

  for (current_row = row, current_col = 0; current_col < c; current_col++)
  {
    total+=A[current_row][current_col];
  } // end for
  return total;
}

/* search an array for a given value parameter
   Input: A 2D Array, number of rows and columns of the array as positive integers,
     and the value to be searched for
   Output: will return 1 if value is found, 0 if not found
*/
int FindArray2D(int A[][COL],
                    const unsigned int r, const unsigned int c,
                    const int value);

int FindArray2D(int A[][COL],
                    const unsigned int r, const unsigned int c,
                    const int value)
{
  int current_row;  // counter to track the current row in the array
  int current_col;  // counter to track the current column in the array

  for (current_row = 0; current_row < r; current_row++)
  {
      for (current_col = 0; current_col < c; current_col++)
      {
          if (A[current_row][current_col] == value)
            return 1;
      } // end for
  }// end for

  return 0; // not found!
}



#endif // ARRAY2D_H_INCLUDED
