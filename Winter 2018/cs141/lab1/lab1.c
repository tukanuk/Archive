/* Name: lab1.c
   Purpose: To explore recursive and non-recursive functions
   Author: Ben Davidson
   Date: 0116-2018 2:44p */

#include <stdio.h>
#include <math.h>

/********************** Global Variables ********************/

int firstFunctionInput = 0; // first input paramenter for functions (required)
int secondFunctionInput = 0; // second input parameter for functions (if required)

/******************** Protoype Functions ********************/

int basicMenu (void);
int functionInputs (int);

/* Non-recursive functions */

int SimpleSummation(int);
int AdvancedSummation(int);
int Fibonacci(int);
int Gcd(int, int);
int PowerFunction(int, int);
int PrintN(int);
int DrawTriangle(int);
int DrawTriangle2(int);

/* Recursive funcitons */

int SimpleSummationRec(int);
int AdvancedSummationRec(int);
unsigned long long FibonacciRec(unsigned int);
int GcdRec(int, int);
long long PowerFunctionRec(int, int);
int PrintNRec(int);
int DrawTriangleRec(int);
int DrawTriangle2Rec(int, int);

int starDraw(int); 

int main(void)

{
    int status = 0; // variable to exit the program

    /* Basic program loop. Will exit if basicMenu returns 1 */
    while (status == 0)
    {
        status = basicMenu();
    }
    return 0;
}

/* basicMenu: A basic menu to select a function 
   INPUT: none
   OUTPUT: returns 0 to keep the program going, returns 1 to exit the program
*/
int basicMenu (void)
{
  int choice = 0; // choose a function
  char recChoice = 0; // recursive or not
  
  printf("\n\n");
  printf("************************************************************** \n");
  printf("*      Welcome to Lab 1: Scopes, Functions and Recursion     * \n");
  printf("************************************************************** \n");
  printf("* 1. Simple summation       * 2. Advanced summation          * \n");
  printf("* 3. Fibonacci              * 4. GCD                         * \n");
  printf("* 5. Power function         * 6. Print(n)                    * \n");
  printf("* 7. DrawTriangle           * 8. DrawTriangle2               * \n");
  printf("************************************************************** \n");
  printf("*          Choose a number (1...8) and choose either         * \n");
  printf("*           (N)on-Recursive or (R)ecursive (ie 1,R):         * \n");
  printf("*                   Or enter '9' to quit                     * \n");
  printf("************************************************************** \n");
  printf("                            ");
  
  scanf("%d", &choice); //first menu choice

//   printf("%d", choice);
//   return 1;

  // exits the program
  if (choice == 9)
  {
      return 1;
  }
  else if (choice > 9 || choice < 1) // forces a valid choice
  {
      printf("Please choose from 1..9\n");
      scanf("%d", &choice); 
  };

  scanf(",%c", &recChoice);

  printf("\n\n");
  
  if (recChoice == 'R' || recChoice == 'r')
  {
    choice += 8;
  }

  switch (choice)
  {
    case 1: 
            // Intructions and input
            printf("1. Simple Summation\n");
            printf("-------------------\n");
            functionInputs(1);
            // Function call
            SimpleSummation(firstFunctionInput);
            break;

    case 2: 
            // Intructions and input
            printf("2. Advanced Summation\n");
            printf("---------------------\n");
            functionInputs(1);
            // Function call
            AdvancedSummation(firstFunctionInput);
            break;
    case 3: 
            // Intructions and input
            printf("3. Fibonacci Sequence\n");
            printf("---------------------\n");
            functionInputs(1);
            // Function call
            Fibonacci(firstFunctionInput);
            break;
    case 4: 
            // Intructions and input
            printf("4. Greatest Common Denominator\n");
            printf("------------------------------\n");
            functionInputs(2);
            // Function call
            Gcd(firstFunctionInput, secondFunctionInput);
            break;
    case 5: 
             // Intructions and input
            printf("5. Power Function\n");
            printf("-----------------\n");
            functionInputs(2);
            // Function call
            PowerFunction(firstFunctionInput, secondFunctionInput);
            break;
    case 6: 
            // Intructions and input
            printf("6. Print(n) countdown\n");
            printf("---------------------\n");
            functionInputs(1);
            // Function call
            PrintN(firstFunctionInput);
            break;
    case 7: 
            // Intructions and input
            printf("7. DrawTriangle(n)\n");
            printf("------------------\n");
            functionInputs(1);
            // Function call
            DrawTriangle(firstFunctionInput);
            break;
    case 8: 
            // Intructions and input
            printf("7. DrawTriangle2(n)\n");
            printf("-------------------\n");
            functionInputs(1);
            // Function call
            DrawTriangle2(firstFunctionInput);
            break;

    case 9: 
             // Intructions and input
            printf("1. Recursive Simple Summation\n");
            printf("-----------------------------\n");
            functionInputs(1);
            // Function call
            printf("The summation of %d is: %d", firstFunctionInput, SimpleSummationRec(firstFunctionInput));
            break;
    case 10: 
            // Intructions and input
            printf("2. Advanced Recursive Summation\n");
            printf("-------------------------------\n");
            functionInputs(1);
            // Function call
             printf("The summation of %d is: %d", firstFunctionInput, AdvancedSummationRec(firstFunctionInput));
             break;
    case 11: 
            // Intructions and input
            printf("3. Recursive Fibonacci Sequence\n");
            printf("-------------------------------\n");
            functionInputs(1);
            // Function call
            printf("f(%d) in the fibonacci sequence is: %llu ", firstFunctionInput, FibonacciRec(firstFunctionInput));
            break;
    case 12: 
            // Intructions and input
            printf("4. Recursive Greatest Common Denominator\n");
            printf("----------------------------------------\n");
            functionInputs(2);
            // Function call
             printf("The greatest common denominator of %d and %d is: %d.", 
                firstFunctionInput, secondFunctionInput, GcdRec(firstFunctionInput, secondFunctionInput));
             break;
    case 13: 
            // Intructions and input
            printf("5. Recursive Power Function\n");
            printf("---------------------------\n");
            functionInputs(2);
            // Function call
             printf("%d to the power of %d is: %lld.", firstFunctionInput, secondFunctionInput, 
                PowerFunctionRec(firstFunctionInput, secondFunctionInput));
             break;
    case 14: 
            // Intructions and input
            printf("6. Recursive Print(n)\n");
            printf("---------------------\n");
            functionInputs(1);
            // Function call    
             printf("Print(%d) = ", firstFunctionInput);
             PrintNRec(firstFunctionInput);
             break;
    case 15: 
             // Intructions and input
             printf("7. Recursive * Triangle\n");
             printf("-----------------------\n");
             functionInputs(1);
             // Function call
             printf("\n");    
             DrawTriangleRec(firstFunctionInput);
             break;
    case 16: 
             // Intructions and input
             printf("8. Recursive Reverse * Triangle\n");
             printf("-------------------------------\n");
             functionInputs(1);
             // Function call    
             printf("\n");
             // counter = 1;
             DrawTriangle2Rec(1, firstFunctionInput);
             break;
    default:
             return 1;
             break;
  }

   return 0;
}

/*
 *	functionInputs: to collect the inputs for the functions
 *		INPUT: 1 or 2 to set how many inputs to collect
 *		OUTPUT: the inputs for the functions
*/
int functionInputs (int numInputs)
{
    printf("Enter a number: ");
    scanf("%d", &firstFunctionInput);
    if (numInputs == 2)
    {
        printf("Enter a second number: ");
        scanf("%d", &secondFunctionInput);
    }

    return 0;
}

/* Non-recursive functions */

/*
 *	SimpleSummation: to perform a basic summation
 *		INPUT: the number to perform the summation calculation on
 *		OUTPUT: none
*/

int SimpleSummation(int numToSum)
{
    int sumTotal = 0; // the total summation

    // Perform the summation
    for ( ; numToSum > 0 ; numToSum--)
    {
        sumTotal += numToSum; 
    }

    // Display the results
    printf("The total is: %d", sumTotal);

    return 0;
};

/*
 *	AdvancedSummation: to perform an more advanced summaiton
 *		INPUT: the number to perform the summation calculation on
 *		OUTPUT: NONE
*/
int AdvancedSummation(int numToSum)
{
    int sumTotal = 0; // the total summation

    // Perform the summation
    for ( ; numToSum > 0 ; numToSum--)
    {
        sumTotal += (numToSum + 1) * (numToSum + 1); 
    }

    // Display the results
    printf("The total is: %d", sumTotal);

    return 0;
};

/*
 *	fibonacci: to calculate a fibonacci sequence
 *		INPUT: the number to perform the sequence on
 *		OUTPUT: NONE3

*/
int Fibonacci(int firstInput)
{
    printf("F(0) to F(%d) in the fibonacci sequence are: ", firstInput);

    int fibNumber = 0; // the fibonacci number for fibCounter
    int fibNumberOne = 1; // n-1
    int fibNumberTwo = 0; // n-2

    // loop to calculate the fibonacci number
    for (int fibCounter = 0; fibCounter <= firstInput ; fibCounter++)
    {
        if (fibCounter == 0)
        {
            fibNumber = 0;
        }
        else if (fibCounter == 1)
        {
            fibNumber = 1;
        }
        else
        {
            fibNumber = fibNumberOne + fibNumberTwo;
            fibNumberTwo = fibNumberOne;
            fibNumberOne = fibNumber;
        };
        
        printf("%d, ", fibNumber);
    };
    printf("\n");

    return 0;
};

/*
 *	Gcd: finds the greatest common denomonator
 *		INPUT: the two numbers to perform the calculation on
 *		OUTPUT: NONE
*/          
int Gcd(int firstInput, int secondInput)
{
    int denominator = 2; // the denominator currently being tested
    int Gcd = 1 ; // the greatest common denominator

    int smallerValue = 0; // used for limiting the search for the Gcd

    // find the smaller of the two values
    if (firstInput >= secondInput)
    {
        smallerValue = secondInput;
    }
    else
    {
        smallerValue = firstInput;
    };

    
    if (secondInput == 0) // if one value is 0, the Gcd is the other value
    {
        Gcd = firstInput;
    }
    else if (firstInput == 0)
    {
        Gcd = secondInput;
    }
    else if (firstInput % secondInput == 0) // check if the numbers divide by themselves
    {
        Gcd = secondInput;
    }
    else if (secondInput % firstInput == 0)
    {
        Gcd = firstInput;
    }
    else
    {
        // the main Gcd calculation. check denominators up to half of the smaller of the two numbers
        // if the mod is 0 of both then it is a common denominator
        for ( ; denominator <= (smallerValue / 2); denominator++)
        {
            if ( (firstInput % denominator == 0) && (secondInput % denominator == 0) )
            {
                Gcd = denominator;
            }
        }
    }
    
    printf("The greatest common denomonator of %d and %d is: %d", firstInput, secondInput, Gcd);

    return 0;
};

/*
 *	powerFunciton: calculates the power 
 *		INPUT: the base and the exponent
 *		OUTPUT: NONE
*/          
int PowerFunction(int firstInput, int secondInput)
{
    long long answer = firstInput; // the answer to the power function

    for (int counter = 1 ; counter < secondInput ; counter++)
    {
        answer *= firstInput;
    };

    printf("%d to the power of %d is: %lld", firstInput, secondInput, answer);

    return 0;
};

/*
 *	PrintN: displays a countdown
 *		INPUT: inputs the number to countdown from
 *		OUTPUT: NONE
*/
int PrintN(int firstInput)
{
    printf("Print(%d) = ", firstInput);

    for ( ; firstInput > 0 ; firstInput--)
    {
        printf("%d ", firstInput);
    };

    printf("\n");

    return 0;
};

/*
 *	DrawTriangle: draws a * triangle big to small
 *		INPUT: the numner of lines of stars
 *		OUTPUT: NONE
*/
int DrawTriangle(int firstInput)
{
    printf("\n");

    for ( ; firstInput >= 1; firstInput--)
    {
        for (int inner = firstInput ; inner > 0 ; inner--) 
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
};

/*
 *	DrawTriangle2: draws a * triangle small to big
 *		INPUT: the numner of lines of stars
 *		OUTPUT: NONE
*/
int DrawTriangle2(int firstInput)
{
    printf("\n");

    for (int outer = 0 ; outer < firstInput ; outer++)
    {
        for (int inner = 0 ; inner <= outer ; inner++) 
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
};

/* Recursive functions */

/*
 *	SimpleSummation: to perform a basic summation recursively
 *		INPUT: the number to perform the summation calculation on
 *		OUTPUT: int result of the summation
*/
int SimpleSummationRec(int firstInput)
{
    if (firstInput == 1) // base case
    {
        return 1;
    }
    else 
    {
        // recursive case
        return firstInput + SimpleSummationRec(firstInput - 1); 
    }
};

/*
 *	AdvancedSummationRec: recursively calculates a more advanced summation
 *		INPUT: int input to perform the calculation on
 *		OUTPUT: the result of the summation
*/
int AdvancedSummationRec(int firstInput)
{
    if (firstInput == 1) // base case
    {
        return 4;
    }
    else
    {
        //recursive case
        return pow(firstInput + 1, 2) + AdvancedSummationRec(firstInput - 1);
    }
};

/*
 *	FibinacciRec: to output the nth fibonacci number
 *		INPUT: F(n) of the fibonacci number required
 *		OUTPUT: the fubonacci number
*/
unsigned long long FibonacciRec(unsigned int firstInput)
{
    
    // base case
    if (firstInput == 0 || firstInput == 1)
    {
        return firstInput;
    }
    
    // recursive case
    return FibonacciRec(firstInput - 1) + FibonacciRec(firstInput - 2);
    
};

/*
 *	GcdRec: to detmine the greatest common denominator of two inputs
 *		INPUT: two int that the gcd will be found for
 *		OUTPUT:  the gcd
*/
int GcdRec(int firstInput, int secondInput)
{
    // base case
    if (firstInput == 0)
    {
        return secondInput;
    }
    else if (secondInput == 0)
    {
        return firstInput;
    }

    //recursive case
    return GcdRec(secondInput, firstInput % secondInput);


    return 0;
};

/*
 *	PowerFunctionRec: recursive power function
 *		INPUT: two interger inputs
 *		OUTPUT: result of power function 
*/
long long PowerFunctionRec(int firstInput, int secondInput)
{
    //base case
    if (secondInput == 0)
    {
        return 1;
    }

    //recursive case
    return firstInput * PowerFunctionRec(firstInput, secondInput - 1);
};

/*
 *	PrintRec: display of countdown of int starting at n
 *		INPUT: Intial value
 *		OUTPUT:  return value or resulting outcome
*/
int PrintNRec(int firstInput)
{
    printf("%d ", firstInput);

    // base case
    if (firstInput == 1)
    {
        return 1;
    }

    // recursive case
    return PrintNRec(firstInput - 1);
};

/*
 *	DrawTrinangleRec: Draw a triangle of * with n as the frist line, largest to smallest
 *		INPUT: The largest number of stars 
 *		OUTPUT: a line of the triangle
*/
int DrawTriangleRec(int firstInput)
{
    starDraw(firstInput);
    printf("\n");

    // base case
    if (firstInput == 1)
    {
        return 1;
    }

    // recursive case
    return DrawTriangleRec(firstInput - 1 );
};

/*
 *	DrawTrinangl2eRec: Draw a triangle of * with n as the last line, smallest to largest
 *		INPUT: The largest number of stars 
 *		OUTPUT: a line of the triangle
*/
int DrawTriangle2Rec(int counter, int firstInput)
{
    
    starDraw(counter);
    printf("\n");

    // base case
    if (firstInput == 1)
    {
        return 1;
    }

    counter++;

    // recursive case
    return DrawTriangle2Rec(counter, firstInput - 1 );
};

/*
 *	starDraw: a helper function for the DrawTriangle functions, draws lines of *
 *		INPUT: the number of *
 *		OUTPUT: *stars
*/
int starDraw(int firstInput)
{
    printf("*");
  
    // base case
    if (firstInput == 1)
    {
        return 1;
    }

    // recursive case
    return starDraw(firstInput - 1);
}
