/*
 Name:		lab10.c
 Purpose:	Lab 10
            CS254
 Author:  	Ben Davidson
            104924033
 Date:    	0724-2018 1:06
*/

#include <stdio.h>
#include "../sharedFunctions.h"
#include <math.h>

#define MAX 10000

/** Linear Probe Notes
 * H0 = h(k) % n
 * H1 = (H0 + 1) % n
 * H2 = (H1 + 1) % n
 * Hi = *Hi01 + 1) % n
 */

/*** Prototypes ***/
int isPrime(int n);
int nextPrime(int n);
int linearProbe(int value, int linearHashTable[], int tableSize);
int quadraticProbe(int value, int quadraticHashTable[], int tableSize);

/*** Global ***/
int linearProbeCounter = 0;
int quadProbeCounter = 0;

int main ()
{
    /* Setup the problem */
    header("lab 10", "July 24, 2018");
    printf("Load factor (0.1 < a < 0.9): ");
    double load;
    scanf("%lf", &load);

    /*** Prompt for type ***/
    printf(" 1) Linear Probe\n 2) Quadratic Probe\n 3) Both\n ");
    int choice;
    scanf("%d", &choice);

    int baseTableSize = (int) MAX / load;
    printf("Load: %f \nBase table size: %d -> ", load, baseTableSize);

    int tableSize = nextPrime(baseTableSize);
    printf("%d (prime table size)\n", tableSize);
    
    int linearHashTable[tableSize];
    int quadraticHashTable[tableSize];
    int i;

    while (i < tableSize) // fills the tables with -1
    {
        linearHashTable[i] = -1;
        quadraticHashTable[i++] = -1;
    }

    time_t t;        // setup random number
    srand(time(&t));
    for (int i = 0 ; i < MAX ; i++) // fills with random MAX (10000) random numbers
    {
        int value = rand() % (MAX * 100);

        if (choice == 1 || choice == 3) linearProbe(value, linearHashTable, tableSize);
        if (choice == 2 || choice == 3) quadraticProbe(value, quadraticHashTable, tableSize);
    }

    double expectedProbe = (1.0 + 1.0/(1.0 - load))/2.0;

    if (choice == 1 || choice == 3) printf("Expected/Actual avg number of linear probes: %f / %f \n", expectedProbe, (double) linearProbeCounter / (double) MAX);
    if (choice == 2 || choice == 3) printf("Actual avg number of quadratic probes:                  %f \n",  (double) quadProbeCounter / (double) MAX);

    return 0;
}

int linearProbe(int value, int linearHashTable[], int tableSize)
{
    int hash = value % tableSize;
    int position, count;
    position = hash;

    for (count = 0 ; count != tableSize ; count++)
    {
        linearProbeCounter++;
        if (linearHashTable[position] == -1)
        {
            linearHashTable[position] = value;
            return 0;
        }
        position = (hash + count) % tableSize;
    }
    
    return 0;
}
    
int quadraticProbe(int value, int quadraticHashTable[], int tableSize)
{
    int hash = value % tableSize;
    int position, count;
    position = hash;
    

    for (count = 0 ; count < tableSize ; count++)
    {
        quadProbeCounter++;
        if (quadraticHashTable[position] == -1)
        {
            quadraticHashTable[position] = value;
            return 0;
        }
        position = (hash + (count * count)) % tableSize;
    }

    return 0;
}

int isPrime(int n)
{
    if ( n == 2 || n == 3) return 1;

    if (n == 1 || n % 2 == 0) return 0;

    for (int i = 3 ; i * i <= n ; i += 2)
    {
        if (n % i == 0) return 0;
    }

    return 1;
}

int nextPrime(int n)
{
    if (n % 2 == 0) n++;
    for ( ; !isPrime(n); n += 2);
    return n;
}