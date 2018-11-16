/* Name: lab5.c
   Purpose: Lab 5
   Author: Ben Davidson
           104924033
   CS254 Lab Section
   Date: 0612-2018 11:49
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sharedFunctions.h" // small library of personal shared functions

#define maxN 100
#define DEBUG 0

/* Global */
struct mcsData
{
    int sum;
    int left;
    int right;
};
typedef struct mcsData McsData;

int recursiveCounter;                       // used for debugging 

/* Prototypes */
McsData MaxSubSeqDivindeNCOnquer(long S[], int left, int right);
int parseString (char stringSeq[], long S[]);
int inputSequence (long S[]);
McsData MaxSpanSum(long S[], int left, int midPoint, int right);

int main()
{
    system("clear");
    header("Lab 5", "061-2018 11:49");      // some header info
    long S[maxN] = {0};                     // array for sequence

    /* Creating a sequence */
    int length = inputSequence(S);          // used to check array parsing
    
    /* Divide and Conquor */
    McsData result = MaxSubSeqDivindeNCOnquer(S, 0, length-1);  // the solving function

    /* Display Results */
    printf("\nThe sequence from %ld[pos %d] to %ld[pos %d] has a sum of %d\n\n", S[result.left], result.left, S[result.right], result.right, result.sum);
    
    return 0;
}

/* inputSequence
 * INPUT: a char array to store the sequnce
 * OUTPUT: the INPUT array populated with the sequence. Returns int num of elements
 */
int inputSequence (long S[])
{
    char stringSeq[maxN] = "";                      // input string
    printf("Input a space seprrated sequence: \n"); 
    scanf("%[^\n]s", stringSeq);
    int length = parseString(stringSeq, S);         // parse, return length
    
    /* Prints the sequence. Useful for redirection input */
    printf("The sequence is: ");                    // check the parsing
    for (int j = 0 ; j < length ; j++)
    {
        printf("%ld ", S[j]);
    }
    printf("Length: %d\n", length);

    return length;
}

/* parseString
 * INPUT: string, array to store ints in
 * OUTPUT: array populated with int, returns number of elements
 */
int parseString (char stringSeq[], long S[maxN])
{
    int i=0;
    char * end;
    char *p = strtok(stringSeq," ");          // tokenizes string by spaces
    while(p != NULL)                          // stop at end of string
    {
        S[i++] = strtol(p, &end, 10);         // convert each token to an long int
        p = strtok(NULL, " ");                // move to next token
    }
    
    return i;
   
}

McsData MaxSubSeqDivindeNCOnquer(long S[], int left, int right)
{
    // if (DEBUG) printf("%d ", recursiveCounter++);

    McsData result = { 0, 0, 0 };       // a struct for the result
    McsData maxSpan = { 0, 0, 0 };      // a struct for the spannig sequence

    /* Base Case */
    if (left == right)                  // if the beginning and end of sequence are the same position (length 1)
    {
        if (S[left] < 0)                
        {
            result.sum = 0;
            result.left = -1;
            result.right = 0;

            return result;
        }
        else
        {
            result.sum = S[left];
            result.left = left;
            result.right = right;

            return result;
        }
    }
    else
    {
        int midPoint = (left + right) / 2;  // find the midpoint
        
        /* These three function calls are for the three cases.
           1. The largest contiguous sequence is on the left half.
           2. The largest contiguous sequence is on the right half.
           3. The largest contiguous sequence is the spanning case.
        */

        /* Find the left half of the sequence */
        McsData resultLeft = MaxSubSeqDivindeNCOnquer(S, left, midPoint);
        if (DEBUG) printf("resultLeft sum: %d", resultLeft.sum);
        
        /* Find the right half of the sequence */
        McsData resultRight = MaxSubSeqDivindeNCOnquer(S, midPoint + 1, right);
        if (DEBUG)  printf("resultRight sum: %d", resultRight.sum);
        
        /* Find the spanning sequence */
        McsData resultSpan = MaxSpanSum(S, left, midPoint, right);

        /* If the left side is largest of the three cases */
        if ( (resultLeft.sum - resultRight.sum) >= 0 && (resultLeft.sum - resultSpan.sum ) >= 0 )
        {
            if (DEBUG) printf("Left: %d\n", resultLeft.sum);
            // resultLeft.right += 3;
            return resultLeft;
        }

        /* If the right side is the largest */
        if ( (resultRight.sum - resultLeft.sum) >= 0 && (resultRight.sum - resultSpan.sum ) >= 0)
        {
            if (DEBUG) printf("Right: %d\n", resultRight.sum);
            // resultRight.right += 3;
            return resultRight;
        }

        /* If the spanning sequence is the largest */
        if ( (resultSpan.sum - resultLeft.sum) >= 0 && (resultSpan.sum - resultRight.sum) >= 0 )
        {
            if (DEBUG) printf("Span: %d\n", resultRight.sum);
            return resultSpan;
        }

        return result;
    }
}

/* McsData
 * INPUT: array containing sequence, left, mid and right point
 * OUTPUT: returns McsData struct with result
 */
McsData MaxSpanSum(long S[], int left, int midPoint, int right)
    {
        McsData result = {0, 0, 0};

        // Find suffix sum
        int sum = 0;
        int leftSum = 0;
        for (int i = midPoint ; i >= left ; i--)
        {
            sum += S[i];
            if (sum > leftSum)      // if the current sum is the new largest
            {
                leftSum = sum;
                result.left = i;
            }
        }

        // Find prefix sum
        sum = 0;
        int rightSum = 0;
        for (int i = midPoint + 1 ; i <= right ; i++)
        {
            sum += S[i];
            if (sum > rightSum)     // if the current sum is the new largest
            {
                rightSum = sum;
                result.right = i;
            }
        }

        result.sum = leftSum + rightSum;    // the spanning sume is the sum of the left and right half

        return result;
    }