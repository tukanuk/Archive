/*  Name:   assign1.c
    Purpose: To generate a magic numebr sequence
             60-141 Assignment #1
    Author:  Benjamin Davidson
             104924033
             I acknowledge that this is my own work and did 
             not receive any unauthorized help with it.
    Date:    January 23, 2018
*/

#include <stdio.h>
#include <math.h>

#define DEBUG 0 // 0 for regular operation 1 to activate debug checks

/********************** Global Variables ********************/

unsigned int largestDiff = 0; // holds the value of the largest absolute difference

/******************** Protoype Functions ********************/

unsigned int reverseInteger(unsigned int num);
unsigned int generateMagicNumber(unsigned int currentNumber);

int main(void)

{
    int magicCounter = 0;
    int currentNumber = 0;

    scanf("%d", &magicCounter);

    for (int i = 0; i < magicCounter; i++)
    {
        scanf("%d", &currentNumber);
        printf("%d ", generateMagicNumber(currentNumber));
    }
    printf("\n%d\n", largestDiff);
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
 *	generateMagicNumber: generates a magic number as described in assignment 1
 *		INPUT: unsigned int
 *		OUTPUT: unsigned int magic number
*/
unsigned int generateMagicNumber(unsigned int currentNumber)
{
    unsigned int rInt = reverseInteger(currentNumber); // using reverseInterger to get rInt
    unsigned int absDiff; // store the absolute differnce 

    // detmines which number is larger
    if (currentNumber > rInt)
    {
        absDiff = currentNumber - rInt;
    }
    else
    {
        absDiff = rInt - currentNumber;
    }

    // checks if the current absDiff is largest and then stores it
    if (absDiff > largestDiff)
        largestDiff = absDiff;

    // reverse the absDiff to get the magic number and returns it
    return reverseInteger(absDiff);
}
