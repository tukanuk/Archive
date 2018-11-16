/*  Name:    lab6.c
    Purpose: Lab 5
    Author:  Ben Davidson
            104924033
    CS254 Lab Section
    Date: 0625-2018 16:06
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../sharedFunctions.h" // small library of personal shared functions

#define MAX 1000                // size of array
#define LOWER 0                 // lower bound for random number calculation
#define UPPER 100               // upper bouynd for random number calculation
#define DEBUG 0                 // 1 to activate debug output
#define TESTS 10                // number of random tests to run

/*** Prototypes ***/
int CoinChange(int changeAmount, int numOfDenominations, int valueOfDenomination[]);
int changeTable(int changeAmount);

/*** Global Variables ***/

int minCoinsUsed[MAX]   = {0};                   // contains the number of coins required for a change amount
int lastCoinUsed[MAX]   = {0};                   // the denomination of the last coin used for a change amount 
        

int main()
{
    /* Variable setup */
    int changeAmount = 0;                           // the amount to make change for
    int numOfDenominations = 4;                     // the number of denominations
    int valueOfDenomination[MAX] = {1, 5, 10, 25};  // the value of the denominations
    int tests = TESTS;                              // sets tests to the #define value
    int ranChange[TESTS];                           // stores the random test values
    
    if (DEBUG != 1) header("Lab 6", "June 26, 2018");
    int menu;
    printf("1) Enter change amount.   2) Show %d random results: ", tests);
    scanf("%d", &menu);
    printf("\n");

    if (menu == 1)
    {
        /* Collect Input */
        printf("Change amount: ");
        scanf(" %d", &changeAmount);
        tests = 1;   
    }
    else if (menu == 2)
    {
        
        /* Random number array */
        time_t t;
        srand(time(&t));

        for (int i = 0 ; i < 10 ; i++)
        {
            ranChange[i] = rand() % (UPPER - LOWER) + LOWER;
        }

    }
    
    while (tests > 0)
    {
        if (menu == 2)
        {
            changeAmount = ranChange[tests - 1];
        }
        /* Get change */
        CoinChange(changeAmount, numOfDenominations, valueOfDenomination);

        /* Display Result */
        printf("For %2d cents ", changeAmount);
        if (minCoinsUsed[changeAmount] == 0)            // adjust text for different results
        {
            printf("you will need 0 coins.\n");

        }
        else if (minCoinsUsed[changeAmount] == 1)
        {
            printf("you will need a %d cent coin.\n", lastCoinUsed[changeAmount]);

        }
        else
        {
            printf("you will need %d coins with the denominations of ", minCoinsUsed[changeAmount]);
        }

        if (minCoinsUsed[changeAmount] > 1)         // if more than one coin is required move back through the array 
                                                    // to display the necesary coins
        {
            int index = changeAmount;
            printf("%d", lastCoinUsed[index]);
            index  -= lastCoinUsed[index];

            while (index > 0)
            {
                if ( index - lastCoinUsed[index] > 0 ) printf(", %d", lastCoinUsed[index]);
                else printf(" and %d", lastCoinUsed[index]);
                index  -= lastCoinUsed[index];
            }
            printf(".\n");

        }
        
        tests--;
    }

    /** Test output of the change required table **/
    if (DEBUG) changeTable(changeAmount);

    return 0;
}

/* CoinChange
 * INPUT: the change amount to look for for, the number of denominations of cahge, the values of the denominations
 * OUTPUT: minCoinsUsed and lastCoinsUsed global arrays are populated
 */
int CoinChange(int changeAmount, int numOfDenominations, int valueOfDenomination[])
{
    int cents = 1;                  // used to count up to changeAmount
    // int lastCoin[] = {0};
    if (DEBUG) printf("FUNCTION VAR DEFINED. \n");

    while (cents <= changeAmount)   // loops through each possible amount up to the amount requested. 
    {
        int minCoins = cents;       // initial value of min num of coins needed to make change
        int newCoin = 1;            // the first denomination to try
        int j = 0;                  // the index position of the denomination being tested
        
        if (DEBUG) printf("CENT LOOP cents= %d. ca= %d j=%d\n", cents, changeAmount, j);

        while (j < numOfDenominations)                  // loop to test each denomination
        {
            if (DEBUG) printf("J LOOP. \n");
            if (valueOfDenomination[j] <= cents)        // adjust do to lab
            {
                if (DEBUG) printf("1ST IF. \n");
                if (minCoinsUsed[ cents - valueOfDenomination[j] ] + 1 <= minCoins)
                {
                    minCoins = minCoinsUsed[cents - valueOfDenomination[j]] + 1;
                    newCoin = valueOfDenomination[j];
                    if (DEBUG) printf("2ND IF. minCoins= %d. newCoin= %d \n", minCoins, newCoin);
                }
            }

            j++;                                 // next denomination
            if (DEBUG) printf("END OF J LOOP. \n");
        }

        minCoinsUsed[cents] = minCoins;         // record min
        lastCoinUsed[cents] = newCoin;          // record coin that gave min
        if (DEBUG) printf("END OF CENT LOOP. minCoinsUsed: %d. lastCoinUsed: %d\n", minCoinsUsed[cents], lastCoinUsed[cents]);                           // increase amount
        cents++;                                // increment the change loop
    }
    return 0;
}

/* changeTable
 * INPUT: int of the changeAmount
 * OUTPUT: a table of the min coins required and last coin used for different change amounts
 */
int changeTable(int changeAmount)
{
    printf("\n| CHG ");
        for (int i = 0 ; i <= changeAmount; i++)
        {
            printf("| %2d ", i);
        }
        printf("\n| MIN ");
        for (int i = 0 ; i <= changeAmount; i++)
        {
            printf("| %2d ", minCoinsUsed[i]);
        }
        printf("\n| LST ");
        for (int i = 0 ; i <= changeAmount; i++)
        {
            printf("| %2d ", lastCoinUsed[i]);
        }
        printf("\n");

        return 0;
}
