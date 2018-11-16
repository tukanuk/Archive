# Lab 7: Dynamic Memory Allocation
 
## Objectives:
- Design Self-Referential Data Records using Structures.
- Implement dynamic data structures.
 

## Background:
When we want to allocate storage in memory (RAM) we simply declare a variable in our code. If we want to allocate storage for a list, we declare an array. The disadvantage of declaring an array is that we must specify a constant value for its size at compile time.

Compile time refers to the point where the program is compiled, while run time refer to the point when the program is loaded and running in memory. The key point is that once a program is running we must first stop it, re-edit its source and make the necessary changes if any, recompile, then run it again. When working with lists (arrays), it is often difficult to predict the exact size of the list, especially when working interactively with the user.

Arrays thus present a dilemma: the list would either be too short or too long. For instance, if you declare an array of size 100, and later you realize you needed a larger capacity, then you must re-edit, re-compile and run again. On the other hand, if you only use a small portion of the array then you would be wasting a lot of unnecessary space in memory.
 
The alternative is to resort to dynamic memory allocation mechanisms where we are able to manage our own memory allocation and de-allocation programmatically, that is at run time. Consider this: while the program is executing, if it requires an extra space to store a value requested by the user, it would "dynamically" allocate the space for it "on the fly" without ever having to exit the program and without a need to modify any code and recompile. The end result would be a very flexible program that has no limitations (other than the total physical memory of course).

It is one thing to discuss dynamic memory allocation concepts, and another to actually manage them. To work with these and simulate lists we often customize data structures such as linked-lists. A linked-list is based on a self-referential structure; this is a regular struct with only one addition - a self-referential pointer (ie. a pointer to itself).
 

## Example:

    struct point
    {
    int x;
    int y;
    char label[21];
    struct point *ptrNext;  // self referential pointer
    };

 
It is important that you carefully draw these structures in memory so you know what is being allocated and how to trace the inner values. It is also imperative that you manually release (or free) every memory allocation you make. **Here is a simple rule to live by: for every `malloc()` there is a `free()` .** In other words, everything you allocate manually you will need to release from memory manually. The danger is that you may exit the program without releasing the memory and therefore causing a memory leak! The allocated memory will remain allocated, and worse, it will be lost. The only remedy would be to shut off the machine (full power off) and allow the memory buffer circuitry to release its storage charge.

## SPECS:

In this lab you will use structure point as designed in the example above. Your task is to design a simple linked list and an interactive menu. 

The menu would have the following:

1. Add a point at the END of the list.
2. Add a point at the BEGINNING of the list.
3. Is the list empty?
4. Erase all points from the list (reset).
5. Display the list.
6. Save the list to a sequential file (reset/replace file contents)
7. Read the list back from a sequential file (reset/replace current memory content)
0. Exit

**Start** by creating the self-referential structure described in the example above. Then setup useful variables like: `struct point *ptrFirst, *ptrLast` ; to represent pointers to the beginning and end of the list. Remember to initialize your pointers to `NULL`. (include stdlib.h). 

**Then design each of the functions required by the menu.** When designing these functions you need to draw the memory structures and carefully keep track of where each pointer is pointing and what values are in each memory location. Also remember that since you are using pointers to access structures, you need to use the arrow '->' operator to access the members of the structures.
 

**Q.What does it mean to have an empty list?** (A. check if the `ptrFirst` is `NULL`, since `ptrFirst` is designed to point to the first element in the list, and if so happens that the first element is `NULL`, then that means that there is no first element and consequently the list is empty). 

    #include <stdlib.h>
    #include <stdio.h>

    // DOCUMENT!!!!!!
    struct point
    {
    int x;
    int y;
    char label[21];
    struct point *ptrNext;  // self referential pointer
    };

    int isEmptyList(struct point *ptrF);
    void PrintList(struct point *ptrF);
    void ResetList(struct point *ptrF, struct point *ptrL);
    void AddToBeginning(struct point *ptrF, struct point *ptrL);
    void AddToEnd(struct point *ptrF, struct point *ptrL);
    void InputRecord(struct point *ptrNew); // used by Add to interactively get the values from the user

    struct point *ptrFirst = NULL;
    struct point *ptrLast = NULL;

    void main()
    {

    // do the menu
    }

- Design the self referential structure, read and practice how to create and free individual nodes.
- Complete the requirements and all the functions as specified.
 

Document EVERY function (purpose/input/output), and EVERY declaration (Variables and Arrays), and every structure definition. 
 

## IMPORTANT: 
ASK QUESTIONS IF YOU GET STUCK, BUT DO YOUR OWN CODE. ANY CODE SUSPECTED TO BE SIMILAR TO ANOTHER SUBMISSION WILL CAUSE BOTH SUBMISSIONS TO RECEIVE A ZERO MARK ON ALL LABS AND BE REPORTED FOR PLAGIARISM.
