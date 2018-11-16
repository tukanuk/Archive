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

#define RMIN 0
#define RMAX 999

/*** Prototypes ***/

void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
void Display2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], int rowsize, int colsize);

int main( int argc, char *argv[] )
{
    // check for correct number of arguments 
    if (argc != 6)
    {
        printf("usage: assign2 rowsize, colsize, random min, random max, column to sum\n");
    } 
    else
    {

        // take the command line arguments and make them variables
        unsigned int row = atoi(argv[1]);
        unsigned int col = atoi(argv[2]);
        unsigned int rMin = atoi(argv[3]);
        unsigned int rMax = atoi(argv[4]);
        unsigned int colToSum = atoi(argv[5]);

        //printf("row %d, col %d, rMin %d, rMax %d, colToSum %d\n", row, col, rMin, rMax, colToSum);

        // check to make sure row and col do not exceed ROW and COL
        if (row > ROW || col > COL)
        {
            printf("Row must be less then %d. Columns must be less then %d.\n", ROW, COL);
        }
        // check to make sure there are enough random numbers 
        else if ( row * col > rMax - rMin + 1)
        {
            printf("Shrink array size or increase random number range\n");    
        }
        else
        {     
            //initialize arrays
            int array[ROW][COL];
            int array2[ROW][COL];

            printf("\nPopulate Array with unique random integers between %d and %d...\n", rMin, rMax);
            PopulateArray2DUnique(array, row, col, rMin, rMax);
            
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
            CopyArray2DSpiral(array, array2, row, col);
            Display2DArray(array2, row, col);
            
            return 0;
        }
    }
}

/*
 *	PopulateArray2DUnique: populate a 2D array with random unique values in the given range
 *		INPUT: a 2D array, the rows and columns of the array and a min and max
 *             for the random range
 *		OUTPUT:  an array of random numbers
*/
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column

    bool randomTracker[RMAX] = {false}; // tracks the used random numbers
    int check; // loop condition 
    int ran; // the random number

    int counter = 0;
    
    srand(time(NULL));

    for (current_r = 0; current_r < rowsize; current_r++)
    {
        for (current_c = 0; current_c < colsize; current_c++)
        {
            check = 0;
            do 
            {
                ran = rand() % (max - min + 1) + min;  // generates random number
                
                if (!randomTracker[ran]) // check for random number beign unique
                {
                    check = 1;
                    randomTracker[ran] = true;
                
                }
            } while (check == 0);
        
            A[current_r][current_c] = ran; // places random number in array
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

    for (current_r = 0; current_r < rowsize; current_r++)
    {
        for (current_c = 0; current_c < colsize; current_c++)
        {
            printf("%4d", A[current_r][current_c]);
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
            // checks if the current array position is larger then the currenet largest
            if (A[current_r][current_c] > largest) 
            {
                largest = A[current_r][current_c];
            }
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
    int sum = 0; // the sum of the column

    for (int r = 0 ; r < rowsize ; r++)
    {
        sum += A[r][col_to_sum]; //add the current array positon to the sum
    }
    return sum;
}

/*
 *	Sort2DArray: Sorts a 2D array from smallest integer to largest
 *		INPUT: An array, number of rows and colums
 *		OUTPUT: return 0 for successful copy and a sorted array
*/
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
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

    return 0;
}

/*
 *	CopyArray2D: copys the first array into the second array
 *		INPUT: the source array, the destinatioon array, the number of rows and columns of the arrays
 *		OUTPUT: return 0 for sucess and a copied array
*/
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
    for (int r = 0 ; r < rowsize ; r++)
    {
        for (int c = 0 ; c <colsize ; c++)
        {
            B[r][c] = A[r][c]; // copies the current positon of A into the matching position of B
        }
    }

    return 0;
}

/*
 *	CopyArray2DSpirial: copies the first array into the second array in a clockwise spiral pattern
 *		INPUT:  a sorted source array, the destination array, the number of rows and columns of the arrays.
                will not work with an unsorted array
 *		OUTPUT:  return 0 at completion and a copied and sorted 2D array  
*/
int CopyArray2DSpiral(int A[][COL], int B[][COL], int rowsize, int colsize)
{
    
    int rowEnd = rowsize; // last row
    int rowStart = 0; // first row
    int colEnd = colsize; // last column
    int colStart = 0; // first column
    int lastValue = A[rowsize - 1][colsize -1]; //FindLargest(A, rowsize, colsize); // the last value in the sorted array
    
    /* copies array A into a rowsize * colsize sized array 
       allows for easy pointer increment through the array */
    int tempA[rowsize][colsize];
    for (int r = 0 ; r < rowsize ; r++)
    {
        for (int c = 0 ; c <colsize ; c++)
        {
            tempA[r][c] = A[r][c];
        }
    }

    // allows ptrA to increment through the array
    int *ptrA = *tempA;

    while (rowStart < rowEnd && colStart < colEnd )
    {
        //top
        for (int c = colStart ; c < colEnd ;  c++)
        {
            B[rowStart][c] = *ptrA;
            // checks for last value. 
            // necessary for end cases where a column also finishes a row or
            // a row finihses a column
            if (*ptrA == lastValue)
            { 
                //printf("*1\n"); 
                return 0;
            }
            ptrA++;
        }
        
        ++rowStart;
        --colEnd;
        
        //right
        for (int r = rowStart ; r < rowEnd ; ++r)
        {
            B[r][colEnd] = *ptrA;
            // checks for last value. 
            if (*ptrA == lastValue)
            { 
                //printf("*2\n"); 
                return 0;
            }
            ptrA++;
        }
        
        --rowEnd;
           
        //bottom
        for (int c = colEnd ; c > colStart ; --c)
        {
            B[rowEnd][c-1] = *ptrA;
            // checks for last value. 
            if (*ptrA == lastValue)
            { 
                //printf("*3\n"); 
                return 0;
            }
            ptrA++;
        }
        
        //left
        for (int r = rowEnd-1 ; r > rowStart - 1; --r)
        {
            B[r][colStart]= *ptrA;
            // checks for last value. 
            if (*ptrA == lastValue)
            { 
                //printf("*4\n"); 
                return 0;
            }
            ptrA++;
        }
        ++colStart;
    }

    return 0;
}
