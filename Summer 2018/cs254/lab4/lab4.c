/* Name: lab4.c
   Purpose: Lab 4
   Author: Ben Davidson
           104924033
   CS254 Lab Section
   Date: 0605-2018 12:05
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../sharedFunctions.h" // small library of personal shared functions

#define maxN 100
#define DEBUG 0


/* Prototypes */
unsigned long int partOne(int fibN);
unsigned long int partTwo(int fibN);
unsigned long int partThree(int fibN);

/* Global Variables */

int knownF[maxN] = {0};

int main (int argc, char *argv[]) 
{
    system("clear");
    header("Lab 4", "0605-2018 1:35");  // some header info
    printf("INPUT: %s\n", argv[1]);     // echo the input string
    if (DEBUG) printf("Fibonacci #s: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, ...\n"); // first several numbers for testing
    char * end;
    if (argv[1] == NULL)                // if the is no command line argument
    {
        printf("Include the n value for the Fibonaci number as a command line argument.\n");
    }
    else
    {
        int fibN = strtol(argv[1], &end, 10);   // parse the string to an integer
        if (fibN > 0)                           // if the value can be parsed, errors return 0
        {
            time_t start = clock();             // start the timer of  the function
            unsigned long int fib = partOne(fibN); 
            time_t end = clock();               // end the timer
            printf("Part 1: %lu in %ld seconds\n", partOne(fibN), (end - start)/CLOCKS_PER_SEC*2 ); // display the results 
            
            start = clock();
            fib = partTwo(fibN);
            end = clock();
            printf("Part 2: %lu in %ld seconds\n", partTwo(fibN), (end - start)/CLOCKS_PER_SEC );
            
            start = clock();
            fib = partThree(fibN);
            end = clock();
            printf("Part 3: %lu in %ld seconds\n\n", partThree(fibN), (end - start)/CLOCKS_PER_SEC );
        }
        else        // if the command line argument cannot be parsed to an int
        {
            printf("Include the n value for the Fibonaci number as a command line argument.\n");
        }
    }
    return 1;
}
/* partOne: Calculates the Fibonacci Number recursively according to Part 1
 * INPUT: integer
 * OUTPUT: returns the Fibonacci Number
 */
unsigned long int partOne(int fibN)
{
    int FibonacciNumber;

    if (fibN == 0)
    {
        return 0;
    }
    else if (fibN == 1)
    {
        return 1;
    }
    else
    {
        return partOne(fibN - 1) + partOne(fibN - 2);
    }
}

/* partTwo: Calculates the Fibonacci Number iteratively according to Part 2
 * INPUT: integer
 * OUTPUT: returns the Fibonacci Number
 */
unsigned long int partTwo(int fibN)
{
    int fibN2 = 0;
    int fibN1 = 1;
    int FibonacciNumber;

    for (int i = 0 ; i < fibN - 1 ; ++i)
    {
        FibonacciNumber = fibN1 + fibN2;
        fibN2 = fibN1;
        fibN1 = FibonacciNumber;
    }

    return FibonacciNumber;
}
/* partOne: Calculates the Fibonacci Number according to Part 3
 * INPUT: integer
 * OUTPUT: returns the Fibonacci Number
 */
unsigned long int partThree(int n)
{
    if (knownF[n] != 0)
    {
        return knownF[n];
    }
    int temp = n;
    if (n < 0) return 0;
    if (n > 1)
    {
        temp = partThree(n-1) + partThree(n-2);
    }
    knownF[n] = temp;

    return knownF[n];
}
