/* Name: labtest.c
   Purpose: Lab Exam #1
   Author: Ben Davidson
           104924033
   CS141 Lab Section
   Date: January 30, 2018
*/

#include <stdio.h>

#define ROWS 20
#define COLS 20

/*** Function Protoype ***/

void Print(float A[][COLS], int r, int c);
void MinMerge (float A[][COLS], float B[][COLS], float C[][COLS], int r, int c);

void main ()
{
  int p, q ;
  int rows, cols;
  float A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];

  printf("Enter # of rows, # of cols: " ) ;
  scanf( "%d%d", &rows, &cols ) ;

  for ( p = 0 ; p < rows ; p++ )
  {
    printf(" Enter %d column values for row %d:\n", cols, p+1);
    for ( q = 0; q < cols; q++)
    {
      scanf("%f", &A[p][q] );
    }
  } // TODO: Repeat this loop to obtain the contents of B[][]

  for ( p = 0 ; p < rows ; p++ )
  {
    printf(" Enter %d column values for row %d:\n", cols, p+1);
    for ( q = 0; q < cols; q++)
    {
      scanf("%f", &B[p][q] );
    }
  }

  Print ( A, rows, cols );
  Print ( B, rows, cols );
  MinMerge (A, B, C, rows, cols ) ;
  Print ( C, rows, cols ) ;

}

/*
 *	Print: prints a 2D array
 *		INPUT: The array to print and its number of rows and columns
 *		OUTPUT: An 2D array
*/
void Print(float A[][COLS], int r, int c)
{
  int current_r; // counter to track the current row
  int current_c; // counter to track the current column

  for (current_r = 0; current_r < r; current_r++)
  {
    for (current_c = 0; current_c < c; current_c++)
    {
      // setting up a tab format output
      printf("%6.2f", A[current_r][current_c]);
    }

    printf("\n");
  }
  printf("\n\n");
}

/*
 *	MinMerg: compares two arrays and foind the smallest values in each position
 *		INPUT: Two arrays (A dn B) as source data, array C to store the results
             the number of rows and columns in the arrays
 *		OUTPUT: An 2D array (C) of the results
*/
void MinMerge (float A[][COLS], float B[][COLS], float C[][COLS], int r, int c)
{
  int current_r; // counter to track the current row
  int current_c; // counter to track the current column

  for (current_r = 0; current_r < r; current_r++)
  {
    for (current_c = 0; current_c < c; current_c++)
    {
      // determines if A or B is the smaller value
      if (A[current_r][current_c] < B[current_r][current_c])
      {
          // if A is smaller store the min value in array C
          C[current_r][current_c] = A[current_r][current_c];
      } else
      {
        // if B is smaller or equal
        C[current_r][current_c] = B[current_r][current_c];
      }
    }
  }
}
