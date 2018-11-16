/* Name: assign2.c
   Purpose: Assigmnent 2: 2D Array Manipulation
   Author: Ben Davidson
           104924033
           CS141
   Date: 0224-2018 13:14 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define ROW 20
#define COL 20

#define RMIN 1
#define RMAX 99

#define DEBUG 0

/*** Prototypes ***/

void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
void Display2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);
void Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], int rowsize, int colsize);
void Sort2DArrayE(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int order);

void ZeroPopulate2DArray(int A[][COL], int r, int c);
void Populate2DArray(int A[][COL], int r, int c, int dir);

int main()
{
    // take the command line arguments and make them variables
    unsigned int row = 10;
    unsigned int col = 10;
    unsigned int rMin = 1;
    unsigned int rMax = 150;
    unsigned int colToSum = 0;

    printf("row %d, col %d, rMin %d, rMax %d, colToSum %d\n", row, col, rMin, rMax, colToSum);


    int array[ROW][COL];
    int array2[ROW][COL];

    printf("\nPopulate Array with unique random integers between %d and %d...\n", rMin, rMax);
    PopulateArray2DUnique(array, row, col, rMin, rMax);
    printf("\nTEST %d\n", array[1][1]);
    printf("DisplayArray2D\n");
    Display2DArray(array, row, col);
    printf("FindLargest: %d\n", FindLargest(array, row, col));
    printf("FindColSum of col %d: %d\n", colToSum, FindColSum(array, row, col, colToSum));
    printf("Sort2DArray followed by DisplayArray2D:\n");
    Sort2DArray(array, row, col);
    Display2DArray(array, row, col);
    printf("CopyArray2D from A to B, then Display B:\n");
    CopyArray2D(array, array2, row, col);
    Display2DArray(array2, row, col);

    printf("CopyArray2DSpiral from A to B, then Display B:\n");
    //Populate2DArray(array, row, col, 1);
    //Display2DArray(array, row, col);

    CopyArray2DSpiral(array, array2, row, col);
    Display2DArray(array2, row, col);
    
    return 1;
}

/*
 *	PopulateArray2DUnique: populate a 2D array with random values in the given range
 *		INPUT: a 2D array, the rows and columns of the array and a min and max
 *             for the random range
 *		OUTPUT:  an array of random numbers
*/
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column
//printf("!");
    bool randomTracker[ROW * COL] = {false};
    int check;
    int ran;

    int counter =0;
    
    srand(time(NULL));

    for (current_r = 0; current_r < rowsize ; current_r++)
    {
        for (current_c = 0; current_c < colsize; current_c++)
        {
            A[current_r][current_c] = (rand() % (max - min + 1) + min);
        }
    }

}


/*
 *	Display2DArray: prints a 2D array
 *		INPUT: The array to print and its number of rows and columns
 *		OUTPUT: An 2D array
*/
void Display2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column

    //printf("ROW: %d, COL: %d\n", rowsize, colsize);

    for (current_r = 0; current_r < rowsize; current_r++)
    {
        //printf("ROW: %d, COL: %d\n", rowsize, colsize);
        for (current_c = 0; current_c < colsize; current_c++)
        {
            printf("3%d ", A[current_r][current_c]);
        }

        printf("\n");
    }
}

/*
 *	FindLargest: Finds the largest value in the array
 *		INPUT: An array, it's number of rows and columns
 *		OUTPUT: Returns the largest value found
*/
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize)
{

    int current_r; // counter to track the current row
    int current_c; // counter to track the current column

    int largest = 0; //holds the largest found int

    for (current_r = 0; current_r < rowsize; current_r++)
    {
        for (current_c = 0; current_c < colsize; current_c++)
        {
            if (A[current_r][current_c] > largest) largest = A[current_r][current_c];
        }
    }

    return largest;
}

/*
 *	FindColSum: Find the sum of the given column of the given array
 *		INPUT: A 2D array, it's number of rows and columns and the column number to sum
 *		OUTPUT: the sum of the given column
*/
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum)
{
    int sum = 0; // the sum of hte column

    for (int r = 0 ; r < rowsize ; r++)
    {
        sum += A[r][col_to_sum]; 
    }
    return sum;
}

/*
 *	Sort2DArray: Sorts a 2D array from smallest integer to largest
 *		INPUT: An array, number of rows and colums
 *		OUTPUT: a sorted array
*/
void Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column
    int sr;        // sublist row index
    int sc;        // sublist column index
    int minR;      // row index where min was found
    int minC;      // column index where min was found

    int tmp; // tmp swapping

    for (current_r = 0; current_r < rowsize; current_r++)
    {
        for (current_c = 0; current_c < colsize; current_c++)
        {
            // the current element is the smallest
            minR = current_r;
            minC = current_c;

            // search the sublist for a new min
            sc = current_c + 1;
            for (sr = current_r; sr < rowsize; sr++, sc = 0)
            {
                for (; sc < colsize; sc++)
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

/*
 *	CopyArray2D: copys the first array into the second array
 *		INPUT: the source array, the destinatioon array, the number of rows and columns of the arrays
 *		OUTPUT: return 1 for sucess and a copied array
*/
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
    for (int r = 0 ; r < rowsize ; r++)
    {
        for (int c = 0 ; c <colsize ; c++)
        {
            B[r][c] = A[r][c];
        }
    }

    return 1;
}

/*
 *	CopyArray2DSpirial: copies the first array into the second array in a clockwise spiral pattern
 *		INPUT:  the source array, the destinatioon array, the number of rows and columns of the arrays
 *		OUTPUT:  return 1 at complateion and a copied and sorted 2D array  
*/
int CopyArray2DSpiral(int A[][COL], int B[][COL], int rowsize, int colsize)
{
    /* @TODO I NEED A BETTER TEST FOR THE END FO THE POINTER. DUCPLICATE FINAL VALUES PREMATURINLY ABORTS 
    THE TEST. CHAGE POINTER TEST TO END OF ARRAY NOT FINAL VALUE. */

    int rowEnd = rowsize; // last row
    int rowStart = 0; // first row
    int colEnd = colsize; // last column
    int colStart = 0; // first column
    
    int *ptrA = *A;

    while (rowStart < rowEnd && colStart < colEnd )
    {
        // printf("\nrowStart: %d rowEnd: %d colStart: %d, colEnd: %d", rowStart, rowEnd, colStart, colEnd);

        //top
        if (colStart <= colEnd && rowStart <= rowEnd)
        {
            for (int c = colStart ; c < colEnd ;  c++)
            {
                B[rowStart][c] = *ptrA;
                if (*ptrA == FindLargest(A, ROW, COL)) return 1;
                *ptrA++;
            }
            //printf("rowStart: %d\n", ++rowStart);
        ++rowStart;
        --colEnd;
        }

        if (colStart <= colEnd && rowStart <= rowEnd)
        {
            //right
            for (int r = rowStart ; r < rowEnd ; ++r)
            {
                B[r][colEnd] = *ptrA;
                if (*ptrA == FindLargest(A, ROW, COL)) return 1;
                *ptrA++;
            }
            // printf("colEnd: %d\n", --colEnd);
            //--colEnd;
         --rowEnd;
           
        }
        if (colStart <= colEnd && rowStart <= rowEnd)
        {
            //bottom
            for (int c = colEnd ; c > colStart ; --c)
            {
                B[rowEnd][c-1] = *ptrA;
                if (*ptrA == FindLargest(A, ROW, COL)) return 1;
                *ptrA++;
            }
        }
        
        if (colStart <= colEnd && rowStart <= rowEnd)
        {
            //left
            for (int r = rowEnd-1 ; r > rowStart - 1; --r)
            {
                B[r][colStart]= *ptrA;
                if (*ptrA == FindLargest(A, ROW, COL)) return 1;
                *ptrA++;
            }
            ++colStart;
        }
        // temp--;
    }

    return 1;
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

    for (current_r = 0; current_r < r ; current_r++)
    {
        for (current_c = 0; current_c < c; current_c++)
        {
            A[current_r][current_c] = 0;
        }
    }
}

/*
 *	Populate2DArray: sequentially populate a 2D array large small or small to large
 *		INPUT: An Array, the number of rows and columns, 1 for increasing, 0 for decreasing
 *		OUTPUT: An sequentially populated 2D array
*/
void Populate2DArray(int A[][COL], int r, int c, int dir)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column
    
    int counter = 0;
    if (dir) counter = 0;
    else counter = r * c;

    for (current_r = 0; current_r < r; current_r++)
    {
        for (current_c = 0; current_c < c; current_c++)
        {
            A[current_r][current_c] = ( (dir) ? (counter++) : (counter--) );
        }
    }
}


/*
 *	Sort2DArrayE: Sorts a 2D array in both directions
 *		INPUT: An array, number of rows and colums, directon (1 for ascending, 0 for descending)
 *		OUTPUT: a sorted array
*/
void Sort2DArrayE(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int order)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column
    int sr;        // sublist row index
    int sc;        // sublist column index
    int sortR;      // row index where min was found
    int sortC;      // column index where min was found

    int tmp; // tmp swapping

    char direction  = ( (order == 1) ? '<' : '>');

    for (current_r = 0; current_r < rowsize; current_r++)
    {
        for (current_c = 0; current_c < colsize; current_c++)
        {
            // the current elment is the smallest
            sortR = current_r;
            sortC = current_c;

            // search the sublist for a new min
            sc = current_c + 1;
            for (sr = current_r; sr < rowsize; sr++, sc = 0)
            {
                for (; sc < colsize; sc++)
                {
                    //find a new min
                    if ( (order == 1 ) ? (A[sr][sc] < A[sortR][sortC]) : (A[sr][sc] > A[sortR][sortC]) )
                    {
                        sortR = sr;
                        sortC = sc;
                    }
                }
            }

            // swap min and current
            tmp = A[current_r][current_c];
            A[current_r][current_c] = A[sortR][sortC];
            A[sortR][sortC] = tmp;
        }
    }
}