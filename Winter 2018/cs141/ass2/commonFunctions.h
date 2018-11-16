/* Name: commonFunctons.h
   Purpose: Personal library of common functions
   Author: Ben Davidson
           104924033
   Date: Ver 0.5 0130-2018 10:45 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// #define ROW 10
// #define COL 5
// #define RMIN 1
// #define RMAX 100

/******************** Protoype Functions ********************/

void ZeroPopulate2DArray(int A[][COL], int r, int c);
void RanPopulate2DArray(int A[][COL], int r, int c, int min, int max);
void Print2DArray(int A[][COL], int r, int c);
int Search2DArray(int A[][COL], int r, int c, int key);
int keyValue(int min, int max);
void Sort2DArray(int A[][COL], int r, int c, int order);
void Shift2DArrayLeft(int A[][COL], int r, int c);
int ReallyBasicMenu(int A[][COL], int r, int c);
unsigned int reverseInteger(unsigned int num);
void MinMerge (float A[][COL], float B[][COL], float C[][COL], int r, int c);
void Populate2DArray(int A[][COL], int rowsize, int colsize, int dir);
void Sort2DArrayE(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int order);


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
 *             for the random range
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
            A[current_r][current_c] = (rand() % (max - min + 1) + min);
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

    printf("\n");

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

        printf("\nEnter a value between %d and %d: ", min, max);
        scanf("%d", &key);

    } while (key < min || key > max);

    return key;
}

/*
 *	Sort2DArray: Sorts a 2D array from smallest integer to largest
 *		INPUT: An array, number of rows and colums, value for order (future option)
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

    for (current_r = 0; current_r < rSize; current_r++)
    {
        for (current_c = 0; current_c < cSize; current_c++)
        {
            // the current elment is the smallest
            minR = current_r;
            minC = current_c;

            // search the sublist for a new min
            sc = current_c + 1;
            for (sr = current_r; sr < rSize; sr++, sc = 0)
            {
                for (; sc < cSize; sc++)
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

/*
 *	Shift2DArrayLeft: Shifts a 2D array to the left
 *		INPUT: an array and it's number of rows and columns
 *		OUTPUT: Shifts the array.
*/
void Shift2DArrayLeft(int A[][COL], int rSize, int cSize)
{
    int current_r; // counter to track the current row
    int current_c; // counter to track the current column
    int sr;        // sublist row index
    int sc;        // sublist column index
    int minR;      // row index where min was found
    int minC;      // column index where min was found

    int tmp; // tmp swapping

    tmp = A[0][0];

    for (current_r = 0; current_r < rSize; current_r++)
    {
        for (current_c = 0; current_c < cSize; current_c++)
        {
           if (current_c < cSize - 1)
           {
               A[current_r][current_c] = A[current_r][current_c + 1];
           } else
           {
               A[current_r][current_c] = A[current_r + 1][0];
           }
        }
    }

    A[rSize - 1][cSize - 1] = tmp;

}

/*
 *	ReallyBasicMenu: A quick menu to select funcitons
 *		INPUT: None
 *		OUTPUT: the chosen function
*/
int ReallyBasicMenu(int A[][COL], int r, int c)
{
    printf("\n**** Lab #2 ****\n");
    printf("1. Initialize the Array\n");
    printf("2. Randomly populate the Array\n");
    printf("3. Sort the Array\n");
    printf("4. Search the Array\n");
    printf("5. Left-shift the Array\n");
    printf("6. Print the Array\n");
    printf("7. Quit\n");

    int key;

    switch(keyValue(1,7))
    {
        case 1:
                // Fill an array with zeros
                ZeroPopulate2DArray(A, ROW, COL);  
                break;
        case 2:
                // Fill the array with random numbers
                RanPopulate2DArray(A, ROW, COL, RMIN, RMAX);
                break;
        case 3: 
                // Sort the array from lowest interger to highest
                Sort2DArray(A, ROW, COL, 1);
                break;
        case 4:
                // Perform a linear search of the array and return results
                key = keyValue(RMIN, RMAX);
                printf("The value %d was %s\n", key, 
                    Search2DArray(A, ROW, COL, key) ? "found" : "not found");
                break;
        case 5:
                // Shifts the values of the array left
                Shift2DArrayLeft(A, ROW, COL);
                break;
        case 6:
                // Prints the array
                Print2DArray(A, ROW, COL);
                break;
        case 7:
                // Exits the program
                return 7;
                break;
    }

    return 1;

}

/*
 *	reverseInteger: to reverse the input
 *		INPUT: unsigned int the current number ot be worked on
 *		OUTPUT: unsigned int that is the reverse of the input
*/
unsigned int reverseInteger(unsigned int num)
{
    unsigned int rInt = 0; // the reverse int
    unsigned int digits = 0; // a counter for the number of digits in the interger
    unsigned int counter = num; // a counter to assist with the digit counter

    // counts the digits input int
    while (counter > 0)
    {
        counter /= 10;
        digits++;
    }

    if (DEBUG) printf("num: %d digit count: %d\n", num, digits); // Debug code confirms correct digit count

    // loop to reverse the digits 
    while (num > 0)
    {
        rInt += num % 10 * pow(10, digits - 1);
        num /= 10;
        
        if (DEBUG) printf("%d digit: %d\n", digits, rInt); // debug code to confirm the pow function
        
        digits--;
    }

    if (DEBUG) printf("reverse: %d\n", rInt); // debug code to check the reverse int

    return rInt;
}

/*
 *	MinMerg: compares two arrays and finds the smallest values in each position
 *		INPUT: Two arrays (A & B) as source data, array C to store the results
             the number of rows and columns in the arrays
 *		OUTPUT: An 2D array (C) of the results
*/
void MinMerge (float A[][COL], float B[][COL], float C[][COL], int r, int c)
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

/*
 *	Populate2DArray: sequentially populate a 2D array large small or small to large
 *		INPUT: An Array, the number of rows and columns, 1 for increasing, 0 for decreasing
 *		OUTPUT: An sequentially populated 2D array
*/
void Populate2DArray(int A[][COL], int rowsize, int colsize, int dir)
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

// int basicMenu (void)
// {
//   int choice = 0; // choose a function
//   char recChoice = 0; // recursive or not
  
//   printf("\n\n");
//   printf("************************************************************** \n");
//   printf("*      Welcome to Lab 1: Scopes, Functions and Recursion     * \n");
//   printf("************************************************************** \n");
//   printf("* 1. Simple summation       * 2. Advanced summation          * \n");
//   printf("* 3. Fibonacci              * 4. GCD                         * \n");
//   printf("* 5. Power function         * 6. Print(n)                    * \n");
//   printf("* 7. DrawTriangle           * 8. DrawTriangle2               * \n");
//   printf("************************************************************** \n");
//   printf("*          Choose a number (1...8) and choose either         * \n");
//   printf("*           (N)on-Recursive or (R)ecursive (ie 1,R):         * \n");
//   printf("*                   Or enter '9' to quit                     * \n");
//   printf("************************************************************** \n");
//   printf("                            ");
  
//   scanf("%d", &choice); //first menu choice

// //   printf("%d", choice);
// //   return 1;

//   // exits the program
//   if (choice == 9)
//   {
//       return 1;
//   }
//   else if (choice > 9 || choice < 1) // forces a valid choice
//   {
//       printf("Please choose from 1..9\n");
//       scanf("%d", &choice); 
//   };

//   scanf(",%c", &recChoice);

//   printf("\n\n");
  
//   if (recChoice == 'R' || recChoice == 'r')
//   {
//     choice += 8;
//   }

//   switch (choice)
//   {
//     case 1: 
//             // Intructions and input
//             printf("1. Simple Summation\n");
//             printf("-------------------\n");
//             functionInputs(1);
//             // Function call
//             SimpleSummation(firstFunctionInput);
//             break;

//     case 2: 
//             // Intructions and input
//             printf("2. Advanced Summation\n");
//             printf("---------------------\n");
//             functionInputs(1);
//             // Function call
//             AdvancedSummation(firstFunctionInput);
//             break;
//     case 3: 
//             // Intructions and input
//             printf("3. Fibonacci Sequence\n");
//             printf("---------------------\n");
//             functionInputs(1);
//             // Function call
//             Fibonacci(firstFunctionInput);
//             break;
//     case 4: 
//             // Intructions and input
//             printf("4. Greatest Common Denominator\n");
//             printf("------------------------------\n");
//             functionInputs(2);
//             // Function call
//             Gcd(firstFunctionInput, secondFunctionInput);
//             break;
//     case 5: 
//              // Intructions and input
//             printf("5. Power Function\n");
//             printf("-----------------\n");
//             functionInputs(2);
//             // Function call
//             PowerFunction(firstFunctionInput, secondFunctionInput);
//             break;
//     case 6: 
//             // Intructions and input
//             printf("6. Print(n) countdown\n");
//             printf("---------------------\n");
//             functionInputs(1);
//             // Function call
//             PrintN(firstFunctionInput);
//             break;
//     case 7: 
//             // Intructions and input
//             printf("7. DrawTriangle(n)\n");
//             printf("------------------\n");
//             functionInputs(1);
//             // Function call
//             DrawTriangle(firstFunctionInput);
//             break;
//     case 8: 
//             // Intructions and input
//             printf("7. DrawTriangle2(n)\n");
//             printf("-------------------\n");
//             functionInputs(1);
//             // Function call
//             DrawTriangle2(firstFunctionInput);
//             break;

//     case 9: 
//              // Intructions and input
//             printf("1. Recursive Simple Summation\n");
//             printf("-----------------------------\n");
//             functionInputs(1);
//             // Function call
//             printf("The summation of %d is: %d", firstFunctionInput, SimpleSummationRec(firstFunctionInput));
//             break;
//     case 10: 
//             // Intructions and input
//             printf("2. Advanced Recursive Summation\n");
//             printf("-------------------------------\n");
//             functionInputs(1);
//             // Function call
//              printf("The summation of %d is: %d", firstFunctionInput, AdvancedSummationRec(firstFunctionInput));
//              break;
//     case 11: 
//             // Intructions and input
//             printf("3. Recursive Fibonacci Sequence\n");
//             printf("-------------------------------\n");
//             functionInputs(1);
//             // Function call
//             printf("f(%d) in the fibonacci sequence is: %llu ", firstFunctionInput, FibonacciRec(firstFunctionInput));
//             break;
//     case 12: 
//             // Intructions and input
//             printf("4. Recursive Greatest Common Denominator\n");
//             printf("----------------------------------------\n");
//             functionInputs(2);
//             // Function call
//              printf("The greatest common denominator of %d and %d is: %d.", 
//                 firstFunctionInput, secondFunctionInput, GcdRec(firstFunctionInput, secondFunctionInput));
//              break;
//     case 13: 
//             // Intructions and input
//             printf("5. Recursive Power Function\n");
//             printf("---------------------------\n");
//             functionInputs(2);
//             // Function call
//              printf("%d to the power of %d is: %lld.", firstFunctionInput, secondFunctionInput, 
//                 PowerFunctionRec(firstFunctionInput, secondFunctionInput));
//              break;
//     case 14: 
//             // Intructions and input
//             printf("6. Recursive Print(n)\n");
//             printf("---------------------\n");
//             functionInputs(1);
//             // Function call    
//              printf("Print(%d) = ", firstFunctionInput);
//              PrintNRec(firstFunctionInput);
//              break;
//     case 15: 
//              // Intructions and input
//              printf("7. Recursive * Triangle\n");
//              printf("-----------------------\n");
//              functionInputs(1);
//              // Function call
//              printf("\n");    
//              DrawTriangleRec(firstFunctionInput);
//              break;
//     case 16: 
//              // Intructions and input
//              printf("8. Recursive Reverse * Triangle\n");
//              printf("-------------------------------\n");
//              functionInputs(1);
//              // Function call    
//              printf("\n");
//              // counter = 1;
//              DrawTriangle2Rec(1, firstFunctionInput);
//              break;
//     default:
//              return 1;
//              break;
//   }

//    return 0;
// }