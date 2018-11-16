/*  (c)2016 Ziad KOBTI. All Rights Reserved.
    This library may not be reproduced without written permission from the author.
    Users registered as students in 60-141 are licensed to use this library for education purposes only
    The author does not encourages gambling nor endorses the OLG, nor makes any guarantee for winning
    If you use these generators and win the lottery, you agree to share 10% of your winning with the author :)
*/

//#ifndef COMMONFUNCTIONS_H_INCLUDED
//#define COMMONFUNCTIONS_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <math.h>

#define SEED_RESET_INTERVAL 50

/*  Generate a new seed for the random number genrator
    Input: uses global SEED_RESET_INTERVAL to allow it to reset the seed value
    Output: sets the seed value in srand every SEED_RESET_INTERVAL calls for rand
*/
void randomSeed();
void randomSeed()
{
    static int seed_interval = SEED_RESET_INTERVAL;

    if (seed_interval % SEED_RESET_INTERVAL == 0)
    {
        srand(time(NULL));
        seed_interval--;
    }
    else if (seed_interval == 0)
    {
        seed_interval = SEED_RESET_INTERVAL;
    }
    else
    {
        seed_interval--;
    }

}
/*  swap the contents of two integer values
    Input: two pointers to integers
    Output: swaps the contents of the two integers
*/
void swap(int *ptr_a, int *ptr_b);
void swap(int *ptr_a, int *ptr_b)
{
    int temp;
    temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

/*  generateRandom(): generate a random integer number between min and max inclusive
    Input: a range for the integers to be generated between min and max
    Output: returns a random number between min and max inclusive
*/
int generateRandom(int min, int max);   // specification prototype or signature
int generateRandom(int min, int max)    // implementation or function definition
{
    randomSeed();

    // check min < max and make sure min is always less than or (equal) to max
    if (min > max) swap(&min, &max);


    return min + (rand() % (max - min));
}

/*  generates a random number between 1 and 49 based on a frequency histogram bias
    Input: Source: http://www.olg.ca/lotteries/viewFrequentWinningNumbers.do
    Output: return a random number between 1 and 49
*/
int generateRandomFrequencyBias();
int generateRandomFrequencyBias()
{
    int key=0;
    int counter=0;
    int sum=0;
    int i;
    int frequencyTable[50]; // 0 to 49
    frequencyTable[0] = 0;  // ignore
    frequencyTable[1] =	66;
    frequencyTable[2] = 53;
    frequencyTable[3] = 76;
    frequencyTable[4] = 59;
    frequencyTable[5] = 86;
    frequencyTable[6] = 49;
    frequencyTable[7] = 71;
    frequencyTable[8] = 70;
    frequencyTable[9] = 75;
    frequencyTable[10] = 66;
    frequencyTable[11] = 83;
    frequencyTable[12] = 69;
    frequencyTable[13] = 72;
    frequencyTable[14] = 66;
    frequencyTable[15] = 47;
    frequencyTable[16] = 70;
    frequencyTable[17] = 64;
    frequencyTable[18] = 76;
    frequencyTable[19] = 58;
    frequencyTable[20] = 62;
    frequencyTable[21] = 77;
    frequencyTable[22] = 71;
    frequencyTable[23] = 71;
    frequencyTable[24] = 66;
    frequencyTable[25] = 82;
    frequencyTable[26] = 71;
    frequencyTable[27] = 73;
    frequencyTable[28] = 69;
    frequencyTable[29] = 52;
    frequencyTable[30] = 68;
    frequencyTable[31] = 64;
    frequencyTable[32] = 64;
    frequencyTable[33] = 67;
    frequencyTable[34] = 70;
    frequencyTable[35] = 60;
    frequencyTable[36] = 80;
    frequencyTable[37] = 77;
    frequencyTable[38] = 66;
    frequencyTable[39] = 77;
    frequencyTable[40] = 57;
    frequencyTable[41] = 77;
    frequencyTable[42] = 78;
    frequencyTable[43] = 70;
    frequencyTable[44] = 61;
    frequencyTable[45] = 66;
    frequencyTable[46] = 64;
    frequencyTable[47] = 72;
    frequencyTable[48] = 65;
    frequencyTable[49] = 64;

    randomSeed();

    for (i=1, sum=0; i<=49; i++)
    {
        sum+= frequencyTable[i];
    }
    key = generateRandom(1, sum);
    for (i=1, counter=0; i <= 49; i++)
    {
        counter+=frequencyTable[i];
        if (counter >= key) break;
    }
    return i;
}

/*  reverse the contents of an integer
    Input: an integer to be reversed
    Output: the reverse of an integer, e.g. 123->321, note the left zero loss, e.g. 23400 -> 432 because of integer definition
*/
int reverseInteger(int n);
int reverseInteger(int n)
{
    int p=1;
    int r;
    int ans=0;
    int n2 = n;

    while(n2!=0)
    {
        n2=n2/10;
        p*=10;
    }
    p=p/10;
    while(n!=0)
    {
        r = n%10;
        n = n/10;
        ans = ans+(p*r);
        p=p/10;
    }
    return ans;
}

/*  count the number of digits in a given integer
    Input: an integer to count its digits
    Output: the number of digits in an integer (123123->6 digits)
    (warning: untested for negative and zero leading values)
*/
int countDigits(int n);
int countDigits(int n)
{
    int c=1;
    while (n>=10)
    {
        n=n/10;
        c=c+1;
    }
    return c;
}

/* a recursive version of the above */
/* only works for positive numbers n */
int countDigitsRecursive(const unsigned int n);
int countDigitsRecursive(const unsigned int n)
{
    if (n<10)   /* base case: a number with one digit */
        return 1;
    else        /* recursive case: a number with more than one digit, has at least 1 digit plus the rest. */
        return 1+ countDigitsRecursive(n/10);
}

/* reverse the contents of an integer using recursion as per above non-recursive example */
int reverseIntegerRecursive(int n);
int reverseIntegerRecursive(int n)
{
    /* base case: n < 10 */
    if (n < 10)
        return n;
    else
        return ((n%10) * (pow(10, countDigits(n))/10)) + reverseIntegerRecursive(n/10);
}
////#endif // COMMONFUNCTIONS_H_INCLUDED
