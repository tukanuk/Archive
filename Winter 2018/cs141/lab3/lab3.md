# Lab 3: Pointers In C
 
Page 1 of 1


## Objectives:

1. Pointer variable declaration, referencing and dereferencing operators, and pointer arithmetic
2. Passing parameters to functions by reference
3. Relationship between pointers and arrays

## Pre-requisite(s):

- Refer to lecture notes on arrays.
- Read Chapters 6 and 7 in the textbook.

## Instructions:

Each part has an estimated time of completion associated with it. This is used to assist you in managing your time better and keeping your pace in check so you can prepare yourself to code more efficiently under limited time constraints. This will help your to prepare for the lab exam!

PART I: Introduction to Pointers [ESTIMATED TIME 15 MINUTES]
Read the code example from your textbook figure 7.4 and experiment with it.
Next, type the following program and document every line by explaining its function and output.
If any line produces an error, comment that specific line and explain the nature of the error.

Write, your code for this part in a file called: exercise4a.c

    1.  #include <stdio.h>
    2.  int main()
    3.  {
    4.       int a = 7;
    5.       int *aPtr;
    6.       aPtr = &a;
    7.       printf("%p", &a);
    8.       printf("%p", aPtr);
    9.       printf("%p", &aPtr);
    10.      printf("%d", a);
    11.      printf("%d", *aPtr);
    12.      printf("%p", *&aPtr);
    13.      printf("%p", &*aPtr);
    14.      printf("%d", *&a);
    15.      printf("%d", &*a);
    16.      return 0;
    17. }

## PART II: Parameter Passing by Reference [ESTIMATED TIME 15 MINUTES]

Write, document and test each of the following function specifications (exercise4b.c):

- A function called **Swap** that takes two integer pointers and exchanges the values of each. It returns void. Example: given two integers 'a=2' and 'b=4', after Swap(&a, &b) is called, 'a' will be 4 and 'b' will be 2.

- A function called **Triple** that takes a single parameter of type pointer to an integer and triples its value. It also returns an integer (the tripled value). Example: if 'd=10', then after we call Triple(&d) we have 'd=30'.

- A function called **BubbleSort** that accepts an integer array, its size, and sort order. (Use the function Swap that you designed in part II above.)(the Sort order is defined by a flag parameter in the function call - for instance, you can make the flag an integer and if it is equal to 1 then it sorts in ascending order, and if the flag is -1 then it sorts in descending order). 

## PART III: Algorithms with Arrays and Pointers [ESTIMATED TIME 40 MINUTES]

Follow the following steps, write your code in the same file as part II (exercise4b.c).

1. Declare an array in main() called NumList of type integer and size MAX (define MAX as 20).

2. ***RULE: From this point forward, you may NOT use the array operator [ ] anywhere else in your program (except when declaring the array).

3. Populate the array with increasing even numbers starting with 4. (example: 4, 6, 8, ...)

4. Display the Array contents. (Write a function for this, call it PrintArray that accepts the array to be printed and its size as parameters)

5. Triple the value of each element in the array. (use the function Triple from Part II)

6. Display the Array contents. (call your PrintArray).

7. Sort the array in any order as desired by the user (Write a function called BubbleSort that accepts the array, size, and sort order). (Use the function Swap that you designed in part II above.)(the Sort order is defined by a flag parameter in the function call - for instance, you can make the flag an integer and if it is equal to 1 then it sorts in ascending order, and if the flag is -1 then it sorts in descending order)

8. Display the SORTED Array in Ascending and Descending order (use PrintArray to display).

## How to document functions? 

    /* Line1: Describe the function/its purpose briefly
       Line2: Describe the input parameters, or the   
              assumptions/requirements going into the function
       Line3: Describe the output of the function. (what does it 
              return? what does it print?)
    */

### EVALUATION: The marks you will receive for this lab are made of two parts: in-lab mark and attendance mark.

### In-Lab Mark: You will be evaluated based on your solution for the problem by the end of lab based on the following schema:

0 mark = Work not done / No documentation / Invalid documentation (even if program works)
1 mark = COMPLETE PART I AND II
2 marks = COMPLETE PART I, II and III

### Attendance Mark: You will receive 1 mark for attendance.

NOTE: Every lab is written so it may be completed within 80 minutes allocated for the lab. You are strongly encouraged to practice completing your lab within the lab time. Although you are given extra time to submit the work, in the future you will be required to complete the lab within the 80 minutes. You can achieve this by reading the lab and the assigned textbook chapters ahead of time and practice coding as much as you can.

IMPORTANT: It is your responsibility to follow the correct submission procedure and verify that your work has been properly received and graded.

NO LATE SUBMISSIONS ARE ACCEPTED. LATE PENALTY WAIVER COUPON DOES NOT APPLY. UNDOCUMENTED AND IMPROPERLY DOCUMENTED CODE WILL RECEIVE A MARK OF ZERO. DO YOUR OWN CODE, ANY CODE SUSPECTED TO BE SIMILAR TO ANOTHER SUBMISSION WILL CAUSE BOTH SUBMISSIONS TO RECEIVE A ZERO MARK AND REPORTED FOR PLAGIARISM.