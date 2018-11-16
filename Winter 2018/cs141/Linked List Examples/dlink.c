#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure definition: for double linked list
struct employee
{
	int id;
	char name[40];

	struct employee *ptrNext;	// self-ref. ptr to next node
	struct employee *ptrPrevious;   // self-ref. ptr to prev node
};

// Define an empty list:
struct employee *ptrFirst = NULL;	// always points to the beginning
struct employee *ptrLast = NULL;	// always points to the end


struct employee *CreateRecord();
struct employee *InputRecord(struct employee *ptrNew);
struct employee *AddAtEnd(struct employee *ptrNew);
struct employee *AddAtBeginning(struct employee *ptrNew);
void DeleteLast();
void DeleteFirst();

struct employee *InsertSort(struct employee* ptrNew);
struct employee *Search(int key_id);
int GetCount();


void PrintList(struct employee *ptrF);
void PrintListReverse(struct employee *ptrF);
void PrintRecord(struct employee *ptrCurrent);
void ClearList(struct employee *ptrF);
int isEmpty();


int main()
{

/*	AddAtEnd(InputRecord(CreateRecord()));
	AddAtEnd(InputRecord(CreateRecord()));
	AddAtEnd(InputRecord(CreateRecord()));
	AddAtBeginning(InputRecord(CreateRecord()));
	AddAtBeginning(InputRecord(CreateRecord()));
*/
	InsertSort(InputRecord(CreateRecord()));
	InsertSort(InputRecord(CreateRecord()));
	InsertSort(InputRecord(CreateRecord()));
	InsertSort(InputRecord(CreateRecord()));
	
	PrintList(ptrFirst);	

	PrintRecord(Search(5));

	DeleteFirst();
	DeleteLast();

	PrintList(ptrFirst);

	PrintListReverse(ptrFirst);
		
	ClearList(ptrFirst);
	ptrFirst=NULL;
	ptrLast=NULL;

	return 0;
}

/* Create a new record dynamically
I: none
O: ptr to the new record or NULL if unable to create it.
*/
struct employee *CreateRecord()
{
	struct employee* ptrNew;
	ptrNew = (struct employee *) (malloc(sizeof(struct employee)));
	
	// initialize pointers here
	ptrNew->ptrNext = NULL;
	ptrNew->ptrPrevious = NULL;
	
	return ptrNew;
}

/* Input the data for a record from user
I: a pointer to a record to populate
O: populated record
*/
struct employee *InputRecord(struct employee *ptrNew)
{
	printf ("Enter id and name: ");
	scanf("%d%s", &ptrNew->id, ptrNew->name);

	return ptrNew;
}

/* add a new node to the end of the list
I: a new node that is initialized properly
O: new node added to the end of the list
*/
struct employee *AddAtEnd(struct employee *ptrNew)
{
	if(isEmpty())
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}
	else
	{
		ptrLast->ptrNext = ptrNew;
		ptrNew->ptrPrevious = ptrLast;
		ptrLast = ptrNew;
	}

	return ptrNew;
}

/* display the list in order
I: a pointer to the beginning of the list
O: the printed list
*/
void PrintList(struct employee *ptrF)
{
	if (ptrF == NULL)
	{
		return;
	}
	else
	{
		PrintRecord(ptrF);
		PrintList(ptrF->ptrNext);
	}
}

/* display the list in REVERSE order
I: a pointer to the beginning of the list
O: the printed list in REVERSE
*/
void PrintListReverse(struct employee *ptrF)
{
	if (ptrF == NULL)
	{
		return;
	}
	else
	{
		PrintListReverse(ptrF->ptrNext);
		PrintRecord(ptrF);
	}
}


/* Print one record
I: pointer to a valid record
O: display one record in a good format
*/
void PrintRecord(struct employee *ptrCurrent)
{
	if (ptrCurrent != NULL)
		printf("id: %d, name: %s\n", ptrCurrent->id, ptrCurrent->name);
	else
		printf("ERROR: empty record.");
}

/* erase the contents of a list
I: the pointer to the beginning of the list
O: erase all nodes starting from ptrF, note: user must update Global 
   ptrFirst and ptrLast
*/
void ClearList(struct employee *ptrF)
{
	if (ptrF == NULL)
	{
		return;
	}
	else
	{
		ClearList(ptrF->ptrNext);
		free(ptrF);
	}
}

/* predicate function to test an empty list (global)
I: assume ptrFirst is defined globally
O: return 1 if empty, 0 otherwise
*/
int isEmpty()
{
	if (ptrFirst == NULL)
		return 1;
	else
		return 0;
}

/* Add a new node at the beginning of the list
I: a valid node
O: add to beginning of the list
*/
struct employee *AddAtBeginning(struct employee *ptrNew)
{
	if (isEmpty())
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}
	else
	{
		ptrFirst->ptrPrevious = ptrNew;
		ptrNew->ptrNext = ptrFirst;
		ptrFirst = ptrNew;
	}
	
	return ptrNew;
}

/* delete the last node
I: assume ptrLast is defined globally
O: remove the last node
*/
void DeleteLast()
{
	struct employee *ptrPrev;	// temp hold of previous node

	// case: empty list
	if (isEmpty())
	{
		return;
	}

	// case: one element in the list
	if (ptrFirst == ptrLast)
	{
		free(ptrLast);
		ptrFirst = NULL;
		ptrLast = NULL;
	}
	else
	{
		// case: more than one element in the list
		ptrPrev = ptrLast->ptrPrevious;
		free(ptrLast);
		ptrLast = ptrPrev;
		ptrLast->ptrNext = NULL;
	}
}

/* delete the first node
I: assume ptrFirst is defined globally
O: remove the first node
*/
void DeleteFirst()
{
	struct employee *ptrN;	// temp hold of next node

	// case: empty list
	if (isEmpty())
	{
		return;
	}

	// case: one element in the list
	if (ptrFirst == ptrLast)
	{
		free(ptrLast);
		ptrFirst = NULL;
		ptrLast = NULL;
	}
	else
	{
		// case: more than one element in the list
		ptrN = ptrFirst->ptrNext;
		free(ptrFirst);
		ptrFirst = ptrN;
		ptrFirst->ptrPrevious = NULL;
	}
}


/* insertion sort on the list
I: assume a sorted list, get a new record to add
O: a sorted list, add the record in the correct position so the list remains sorted
use the id as a primary key for the sort
*/
struct employee *InsertSort(struct employee* ptrNew)
{
	struct employee *ptrCurrent = NULL;

	// case: empty list
	if (isEmpty())
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}
	else if(ptrNew->id >= ptrLast->id)
	{
		AddAtEnd(ptrNew);
	}
	else if(ptrNew->id <= ptrFirst->id)
	{
		AddAtBeginning(ptrNew);
	}
	else
	{
		ptrCurrent = ptrFirst;
		while (ptrCurrent->ptrNext->id < ptrNew->id)
		{
			ptrCurrent=ptrCurrent->ptrNext;
		}

		ptrCurrent->ptrNext->ptrPrevious = ptrNew;
		ptrNew->ptrNext = ptrCurrent->ptrNext;
		ptrCurrent->ptrNext = ptrNew;
		ptrNew->ptrPrevious = ptrCurrent;
	}
	return ptrNew;
}

/* count the number of records in the list
I: assume ptrFirst is defined
O: number of nodes
*/
int GetCount()
{
	int count = 0;
	struct employee *ptrCurrent = ptrFirst;

	while (ptrCurrent != NULL)
	{
		ptrCurrent=ptrCurrent->ptrNext;
		count++;
	}
	
	return count;	
}

/* linear search on a linked list
I: id of record to find
O: pointer to the record if found, or NULL otherwise
*/
struct employee *Search(int key_id)
{
	struct employee *ptrCurrent = NULL;
	ptrCurrent = ptrFirst;
	while (ptrCurrent != NULL && ptrCurrent->id != key_id)
	{
		ptrCurrent=ptrCurrent->ptrNext;
	}

	return ptrCurrent;
}

