
/*
   Create a dynamic linked list and store it into file
   The input is entered from the keyboard

   prepared by: Ziad Kobti
   Written on: June 19, 2002
*/

#include<stdio.h>
#include<stdlib.h>


/* student structure definition */
struct student
{
   int id;        /* stores a unique student id number */
   char name[40];    /* stores a student's full name */
   struct student * pNext; /* self referencial pointer */
            /* used to point to the next student record in the linked list */ };


/* prototypes */
void PrintList(struct student *pF);
void ClearList(struct student *pF);


/* global pointers used to maintain a pointer to the first and last record (node) in the linked list */ struct student *pFirst = NULL; struct student *pLast = NULL;

/* main program starts here */
int main()
{
   int done = 0;        /* done used as a flag to exit the interactive loop (-1) and as an ID input */
   struct student * pNew = NULL; /* pNew is used as a temporary pointer to refer to the newly created record */

   /* interactive repeat and ask for the user's input, -1 to quit */
   /* this is used to illustrate that the user may enter as many records as he/she wishes */
   /* arrays cannot be used to do this properly, since we do not know in advance how many records are being entered */
   do
   {
      /* prompt the user for an id, or -1 to quit */
      printf("Enter an id (-1 to quit): ");
      scanf("%d", &done);

      if (done == -1)
         break;   /* use break and NOT return because in the case when we have already created a number of 
               records then we should free these records before we exit the program to avoid a memory
               leak 
             */

      /* create a new record, note the cast used for compliance with strict typing in C */
      pNew = (struct student *) (malloc( sizeof( struct student)) );

      /* check if the memory space was actually allocated */
      if (pNew == NULL)
         break;   /* again, we may still need to clear already allocated records */

      /* store the id in the newly created student record */
      pNew->id = done;

      /* prompt for the name and store it */
      printf("Enter a name: ");
      scanf("%s", pNew->name);

      /* we are adding the new nodes to the end of the list, so the newly created node will have 
        its pNext (pointer to the next record) as NULL to indicate the end of the list */
      pNew->pNext = NULL;

      /* special case: if this is the first record, then make pFirst point to it */
      if (pFirst == NULL)
         pFirst = pNew;

      /* special case: if this is the first record then do not increment the pLast pointer */
      /* which by the way was the problem causing the "segmentation fault" in class */
      /* you really have to draw this and trace it manually to see why! */
      if (pLast != NULL)
         pLast->pNext = pNew;

      /* update the last pointer, ie: make the new node the last one */
      pLast = pNew;

   } while(done != -1);


   /* display what we have in that list, we only need to supply the pointer to the first element in the list */
   PrintList(pFirst);

   /* WE MUST FREE ALL DYNAMICALLY ALLOCATED RECORDS!!!! Rule: for every malloc there is a free */
   /* again, we only need to supply the function the first node, it can find the remaining nodes easily */
   ClearList(pFirst);


   /* we can safely exit the program now provided we freed all dynamically allocated records */
   return 0;
}


/*
  PrintList: traverses a single linked list and displays all the record values to the console, starting with the node 
  whose pointer is supplied.
  Input: the pointer to the beginning of the list you want to print
  Output: displays each record in the list in sequence from first to last */ void PrintList(struct student *pF) {
   /* use a different pointer so I don't modify the initial pointer which points to the beginning of the list */
   struct student *pC = pF;

   while(pC != NULL)
   {
      printf("ID: %d\nName: %s\n", pC->id, pC->name);
      pC = pC->pNext;  /* this is how a list is traversed! */
   }
}


/* ClearList: traverses the list and frees the memory space of each node 
   Input: the pointer to the beginning of the list
   output: frees all the nodes in the list
   NOTE: THIS FUNCTION MUST BE CALLED IN ORDER TO PROPERLY RELEASE THE DYNAMICALLY ALLOCATED MEMORY */ void ClearList(struct student *pF) {
   /* refer to the lecture slide to see the logic diagram on how the list is carefully being traversed */
   struct student *pD = pF;  /* pD points to the node that is to be deleted */

   while(pD != NULL)
   {
      pF = pF->pNext;   /* update the pointer to the beginning of the list to point to the next */
      free(pD);      /* this (previous) node is erased! */
      pD = pF;    /* set the pD to point to the next node to be deleted */
   }

}

/* end of program */

/*  SAMPLE OUTPUT:

(17)% cc file1.c
(18)% a.out
Enter an id (-1 to quit): 10
Enter a name: tony
Enter an id (-1 to quit): 20
Enter a name: lisa
Enter an id (-1 to quit): 30
Enter a name: marco
Enter an id (-1 to quit): 40
Enter a name: john
Enter an id (-1 to quit): -1
ID: 10
Name: tony
ID: 20
Name: lisa
ID: 30
Name: marco
ID: 40
Name: john
(19)% 

*/


