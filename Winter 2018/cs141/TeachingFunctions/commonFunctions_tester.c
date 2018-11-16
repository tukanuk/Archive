/* test module for the commonFunctions library */

void commonFunctions_tester()
{


  int n=6;    /* counter to keep track of random numbers that needs to be generated */
    int n1, n2, n3, n4, n5, n6;

    /* METHOD 1: flawed! */
    printf("Generate 6 random numbers between 1 and 49:\n");

    while (n--)
    {
        printf("%d ", generateRandom(1, 49));
    }
    printf("\n\n");



    /* METHOD 2: unique numbers! */
    n = 6;

    printf("Generate UNIQUE random numbers between 1 and 49:\n");
    while (n--)
    {
        n1 = generateRandom(1, 49);

        do
        {
            n2 = generateRandom(1, 49);
        }while (n2 == n1);

        do
        {
            n3 = generateRandom(1, 49);
        }while (n3 == n1 || n3 == n2);

        do
        {
            n4 = generateRandom(1, 49);
        }while (n4 == n1 || n4 == n2 || n4 == n3);

        do
        {
            n5 = generateRandom(1, 49);
        }while (n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4);

        do
        {
            n6 = generateRandom(1, 49);
        }while (n6 == n1 || n6 == n2 || n6 == n3 || n6 == n4 || n6 == n5);

        printf("%d %d %d %d %d %d\n", n1, n2, n3, n4, n5, n6);

    }



  /* METHOD 3: unique numbers with roulette wheel selection! */
    n = 6;

    printf("\nGenerate UNIQUE random numbers between 1 and 49 using a biased number frequency technique:\n");
    while (n--)
    {
        n1 = generateRandomFrequencyBias();

        do
        {
            n2 = generateRandomFrequencyBias();
        }while (n2 == n1);

        do
        {
            n3 = generateRandomFrequencyBias();
        }while (n3 == n1 || n3 == n2);

        do
        {
            n4 = generateRandomFrequencyBias();
        }while (n4 == n1 || n4 == n2 || n4 == n3);

        do
        {
            n5 = generateRandomFrequencyBias();
        }while (n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4);

        do
        {
            n6 = generateRandomFrequencyBias();
        }while (n6 == n1 || n6 == n2 || n6 == n3 || n6 == n4 || n6 == n5);

        printf("%d %d %d %d %d %d\n", n1, n2, n3, n4, n5, n6);

    }


    /* Reverse an integer number - generate 10 test runs */
    printf("\nReversing integers:");
    n=10;
    while(n--)
    {
        n1 = generateRandom(0, 999999999);
        printf("%d has %d digits (%d using recursion), in reverse is %d (using recursion: %d)\n",
               n1, countDigits(n1), countDigitsRecursive(n1), reverseInteger(n1), reverseIntegerRecursive(n1));
    }
/*    DrawLine('x', 5);
    printf("\n");
    DrawLineR('x',5);
    printf("\n");
    DrawRectangle('x', 10, 5);
    printf("\n");
    DrawSquare('x', 6);
    printf("\n");
    DrawHollowRectangle('x', 10, 4);
    printf("\n");
    DrawFilledRectangle('x', '-', 10, 4);
    printf("\n");
    DrawTriangle('x',5);
    printf("\n");
    DrawReversedTriangle('x', 5);
*/

}
