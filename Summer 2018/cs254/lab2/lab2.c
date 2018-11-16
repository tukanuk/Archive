/* Name: lab2.c
   Purpose: Lab 2
   Author: Ben Davidson
           104924033
   CS254 Lab Section
   Date: 0522-2018 12:24
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MIN -99         // min random value
#define MAX 99          // max random value
#define SIZE 15         // size of the array
#define TESTS 10        // how many times to test

#define DEBUG 0

/***** PROTOTYPE FUNCTIONS ******/
int randomNumberGenerator();
void header();

int main()
{
    // Random number seed
    time_t t;
    srand(time(&t));

    // test random num loop
    if (DEBUG)
    {
        for(int i = 0 ; i < 100 ; ++i)
        {
            printf("%5d", randomNumberGenerator());
        }
    }
    
    // header
    header();

    // Run the algorithm TESTS (10) times
    for (int i = 0 ; i < TESTS; ++i)
    {
        // Generate an array of 15 random int
        //int sequence[SIZE] = {-99, 94, -96, 12, 99, 41, -4, -62, -29, 50};
        int sequence[SIZE];                                         // array for the random int
        char seqString[97] = {};                                    // char array to hold the sequence as a string
        for (int i = 0 ; i < SIZE ; ++i)                            // builds the random int array
        {
            if (!DEBUG) sequence[i] = randomNumberGenerator();                  // inserts a random int in the array

            // builds a string of the sequence. Used to confirm results
            int length = snprintf(NULL, 0, "%3d ", sequence[i]);    // determines the length
            char* digit = malloc(length + 1);                       // allocates memory to the string
            snprintf(digit, length + 1, "%3d ", sequence[i]);       // creates a string from the random int
            strcat(seqString, digit);                               // concats the newest random in to the string 
            // printf("\n%60s\n", seqString);
            free(digit);                                            // frees the memory

        }

        // setup variables
        //int i = 1;                                                  // the next potential starting point for a max sum
        int j = 0;                                                  // the current position in the array
        int maxSum = 0;                                             // the max sum found
        int sum = 0;                                                // the current sum
        int start = -1;                                             // the start of the max sum
        int end = -1;                                               // the end of the max sum
        int tracker[SIZE][3] ={};                                   // end[index], start, sum

        // algorithm 2 from text
        // while (j <= SIZE)                                           // run while less then the SIZE of the array
        // {
        //     sum = sum + sequence[j];                                // the current sum plus the current value in the array
        //     if (sum > maxSum)                                       // set a new max sum
        //     {
        //         maxSum = sum;
        //         start = i;                                          // new max sum start position
        //         end = j;                                            // new max sum end position (same as start)
        //     }
        //     if (sum <= 0)                                           // if sum is <= 0 current value cannot be part of the sequence
        //     {
        //         i = j + 1;
        //         sum = 0;
        //     }

        //     j++;                                                    // increment the position
        // }

        while (j <= SIZE)
        {
            // set the sum
            if (j > 0) 
            {
                tracker[j][2] = tracker[j-1][2] + sequence[j];
            }
            else
            {
                tracker[j][2] = sequence[j];
            }

            if (tracker[j][2] < 0) tracker[j][2] = 0;                   // if less then 0, use empty set

            // set the start
            if (j >= 0  && tracker[j-1][2] > 0)                         // if the previous has a +ve sum use its start
            {
                tracker[j][1] = tracker[j-1][1];
            }
            else 
            {
                tracker[j][1] = j;                                      // use fresh start position
            }

            // set the end
            tracker[j][0] = j;                                          // end at the currrent postiion

            if (tracker[j][2] <= 0)                                     // adjust for empty set
            {
                //i = j + 1;
                tracker[j][0] = j;
                tracker[j][1] = -1;
                tracker[j][2] = 0;
            }

            j++;
        }

        j = 0;

        // loop to find max
        while (j <= SIZE)
        {
            
            if (j == 0 || tracker[j][2] > maxSum)                       // set initial valuea and change max values 
            {
                maxSum = tracker[j][2];
                start = tracker[j][1];
                end = tracker[j][0];
            }
            // else if (j == 0)
            // {
            //     maxSum = tracker[j][2];
            //     start = tracker[j][1];
            //     end = tracker[j][0];
            // }

            j++;
        }
        //output
        printf("+------------------------------------------ Test %2d -------------------------------------------+\n", i+1);
        printf("| %60s | %5d | %5d | %5d | %5d |\n| ", seqString, start, end, sum, maxSum);

        for (int i = 0; i < SIZE ; ++i)
        {
            printf("%3d ", tracker[i][1]);
        }
        printf(" | Start sequence\n| ");

        for (int i = 0 ; i < SIZE ; ++i)
        {
            printf("%3d ", tracker[i][2]);
        }
        printf(" | Segment sum\n\n");

    }
    
    printf("\n\n");
    return 1;
}

/* randomNumberGenerator: generates random numbers according the defined MAX and MIN values
 * INPUT: none
 * OUTPUT: returns a random number with the MAX and MIN values
*/
int randomNumberGenerator()
{
    return rand() % (MAX - MIN) + MIN;
}

/* header: produces a formatted header as long as MIN and MAX do not exceed +-99 (works but gets messy)
 * INPUT: none
 * OUTPUT: a formatted header
 */ 
void header()
{
    printf("\nLab 2: 60-254: Data Structures and Algorithms\n");
    printf("Ben Davidson #104924033\n");
    printf("0522-2018");
    printf("\n\n| %60s | %5s | %5s | %5s | %5s |\n| ", "Sequence", "Start", "End", "Sum", "Max");
    for (int i = 0 ; i < SIZE; ++i)
    {
        printf("%3d ", i);
    }
    printf(" |       |       |       |       |\n");
}
