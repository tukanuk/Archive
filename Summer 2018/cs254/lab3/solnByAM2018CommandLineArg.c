// my interactive version of the balanced parenthesis program using a stack 
// rewritten 28 May, 2018

// written by AM 31 May, 2018
// This is an interactive version. It reads in a parentheses string input by user
// and then reports if it is balanced or not 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <strings.h>

void pop(char stack[], int limit);
void push(char stack[], int limit, char c);

int stackTop = -1; 

int main(int argc, char *argv[]){
    
    printf("%s\n", argv[1]);  // echo the input string
    int strLength = strlen(argv[1]); // get the length of the string
    // printf("SL: %d\n", strLength);
    int i; // loop variable
    
    char *stack = (char *)calloc(strLength, sizeof(char)); // allocate memory for stack
    
    char* inputSeq = argv[1]; // pntr to pntr assignment

     // push and pop works correctly
     for (i = 0; i < strLength; i++) {
         if (*(inputSeq + i) == '(') push(stack, strLength, '(');
         else if (*(inputSeq + i) == ')') pop(stack, strLength);
         else printf("Invalid character in input");
     }
     if (stackTop == -1) printf("The sequence is balanced\n");
     else printf("The sequence is not balanced\n");
     
} // end main 

// implementation of push and pop when the stack is 
// implemented using an array

void pop(char stack[], int strLength)
{
     if (stackTop == -1) { printf("The string is not balanced \n"); exit(0);}
     else --stackTop;
}

void push(char stack[], int strLength, char c)
{
     if (stackTop == strLength -1) {printf("The stack is full \n"); exit(0);}
     else stack[++stackTop] = '(';
}

    
    
