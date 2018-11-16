/* Name: lab3.c
   Purpose: Lab 3
   Author: Ben Davidson
           104924033
   CS254 Lab Section
   Date: 0529-2018 11:40
*/

#include <stdio.h>
#include <string.h>

#define MAX 100                     // largest acceptable sequence

/*** Protypes ***/

void header();                      
void push(int stack[], int *sTop); 
void pop(int stack[], int *sTop);
void visualStack(int parenStack[]);

int main()
{
    int parenStack[MAX] = {0};      // the array used for stack
    int stackTop = 0;               // the top of the stack
    char sequence[MAX];             // the parenthesis sequence
    int loop = 1;                // for looping the test
    header();                       // formatting for lab

    while (loop == 1)
    {
        printf("Enter parentheses sequence: \n");
        scanf("%s", sequence);
        int parenLength = (int) strlen(sequence);

        printf("Sequence: %s Length: %3d\n", sequence, parenLength);

        for (int i = 0 ; i < parenLength ; ++i)         // loop through the parenthesis sequence
        {
            if ( sequence[i] == '(' )
            {
                push(parenStack, &stackTop);
            }
            else if ( sequence[i] == ')')
            {
                if ( stackTop > 0 )
                {
                    pop(parenStack, &stackTop);
                }
                else
                {
                    stackTop = -1;
                    break;
                }
            }
            else                                        // check for valid input
            {
                printf("Just parentheses please\n");
                break;
            }

            //visualStack(parenStack);                              // VISUALIZE THE STACK        
        }

        if (stackTop == 0)
        {
            printf("String Balanced!\n\n");
        }
        else
        {
            printf("Not Balanced!\n\n");
        }

        printf("More (1/0)? \n");
        scanf("%d", &loop);
    }
    return 1;
}

/* header: produces a formatted header
 * INPUT: none
 * OUTPUT: a formatted header
 */ 
void header()
{
    printf("\nLab 3: 60-254: Data Structures and Algorithms\n");
    printf("Ben Davidson #104924033\n");
    printf("0529-2018\n\n");
}

void push(int stack[], int *sTop)
{
    if (*sTop <= MAX -1)
    {
        stack[*sTop] = '(';
        (*sTop)++;
    }
    else
    {
        printf("Stack is full, cannot continue\n\n");
    }
}

void pop(int stack[], int *sTop)
{
    stack[*sTop-1] = ' ';
    (*sTop)--;
}

void visualStack(int parenStack[])
{
    for (int j = 0 ; j < MAX ; ++j)
        {
            printf("%c", parenStack[j]);
        }
        printf("\n");
}