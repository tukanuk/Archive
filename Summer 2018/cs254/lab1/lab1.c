#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define UPPER 100
#define LOWER 1


int main ()
{
    // Step 1
    // initial variables
    int m;
    int n;
    int u;
    int v;
    int counter;

    // primes
    int up;
    int vp;
    int mp;
    int np;

    // setting up random number generator
    time_t t;
    srand(time(&t));

    // formatting
    printf("\n+--------------------------------------------+----+----+-----+\n");
    printf("%-44s %-3s %-3s\n", "| um + vn", "| n`", "| ct | log |");
    printf("|--------------------------------------------+----+----+-----|\n");


    for (int i = 0 ; i < 50 ; i++)          // loops fifty times to produce fifty results
    {
        
        // settinng m with a random number
        m = (rand() % (UPPER - LOWER) + LOWER);
        mp = m;
        
        // settinng n with a random number
        n = (rand() % (UPPER - LOWER) + LOWER);
        np = n;

        // set u and u`
        u = 0;
        up = 1;

        // set v and v`
        v = 1;
        vp = 0;
        
        counter = 0;
        
        // Step 2
        while (mp % np != 0) // continues looping until no remainder
        {

            // Step 3
            // save u, v in temp variables
            int temp1 = u;
            int temp2 = v;

            u = up - (mp / np) * u;
            v = vp - (mp / np) * v;

            up = temp1;
            vp = temp2;

            // Step 4
            int r = mp % np;
            mp = np;
            np = r;

            counter++; // to track the number of divisions
        }

        // Step 5
        
        // prints the math statement to buff so that I can format the math as a single string
        char *buff;
        size_t sz;
        sz = snprintf(NULL, 0, "(%d)(%d) + (%d)(%d) = %d + %d =", u, m, v, n, u*m, v*n); // returns the size of the string 
        buff = (char *)malloc(sz+1); // allocates memory for buff
        snprintf(buff, sz + 1, "(%d)(%d) + (%d)(%d) = %d + %d =", u, m, v, n, u*m, v*n); // produces the math expression


        int logNum = (int) (2 * ceil(log( (m > n) ? n : m  ) ) + 1); // gets the log expression. 
                                                                     // uses conditional operator to determine largest num
        printf("| %38s %3d |%3d |%3d |%3d  |\n", buff, (u*m+v*n), np, counter, logNum ); // final output
    }

    printf("+--------------------------------------------+----+----+-----+\n\n");

    return 0;
}