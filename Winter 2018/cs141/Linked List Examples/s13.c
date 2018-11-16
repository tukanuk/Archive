#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Self-Ref. Struct Definition
struct node
{
	int value;
	struct node *ptrNext;
	struct node *ptrPrevious;
};


struct node *CreateNode();

struct node* InputNodeFromUser(struct node *ptrNew);

void AddFirst(struct node *ptrNew);
void AddLast(struct node *ptrNew);

void ClearList(struct node * ptrF);
void PrintList(struct node * ptrF);
void PrintListReverse(struct node * ptrF);
void PrintListReverseUsingPrev(struct node *ptrL);


int CountList(struct node * ptrF);

void DeleteFirst();
void DeleteLast();
void DeleteLastUsingPrev();

int isEmpty();

void Insert(struct node *ptrN);

struct node * Search(int key);
struct node * SearchRecursive(struct node *ptrF, int key);

// Global Variables for the List
struct node *ptrFirst = NULL;
struct node *ptrLast = NULL;

int main()
{

	// Predefined/simulated user input:
//	AddFirst(InputNodeFromUser(CreateNode()));
//	AddFirst(InputNodeFromUser(CreateNode()));
//	AddLast(InputNodeFromUser(CreateNode()));

	Insert(InputNodeFromUser(CreateNode()));
	Insert(InputNodeFromUser(CreateNode()));
	Insert(InputNodeFromUser(CreateNode()));
	Insert(InputNodeFromUser(CreateNode()));
	Insert(InputNodeFromUser(CreateNode()));

	PrintList(SearchRecursive(ptrFirst, 5));
	//PrintListReverse(ptrFirst);

	ClearList(ptrFirst);

	return 0;
}

// user needs to check if it is NULL
struct node *CreateNode()
{
	return (struct node*) (malloc (sizeof(struct node)));
}

struct node* InputNodeFromUser(struct node *ptrNew)
{
	printf("Please enter a number: ");
	scanf("%d", &ptrNew->value); 
	ptrNew->ptrNext = NULL;
	ptrNew->ptrPrevious = NULL;
	return ptrNew;
}

// assume ptrFirst and ptrLast are global
void AddFirst(struct node *ptrNew)
{
	if (isEmpty())
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}
	else
	{
		ptrNew->ptrNext = ptrFirst;
		ptrFirst->ptrPrevious = ptrNew;
		ptrFirst = ptrNew;
	}
}

void AddLast(struct node *ptrNew)
{
	if (isEmpty())
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
}

int isEmpty()
{
	if(ptrFirst == NULL)
		return 1;
	else 
		return 0;
}

// user must clear ptrFirst and ptrLast
void ClearList(struct node * ptrF)
{
	// base case: empty list
	if (ptrF == NULL)
		return;
	else
	{
		ClearList(ptrF->ptrNext);
		free(ptrF);
	}
}

void PrintList(struct node * ptrF)
{
	// base case: empty list
	if (ptrF == NULL)
		return;
	else
	{
		printf("%d ", ptrF->value);
		PrintList(ptrF->ptrNext);
	}
}

void PrintListReverse(struct node * ptrF)
{
	// base case: empty list
	if (ptrF == NULL)
		return;
	else
	{
		PrintListReverse(ptrF->ptrNext);
		printf("%d ", ptrF->value);
	}
}

void PrintListReverseUsingPrev(struct node *ptrL)
{
	while (ptrL != NULL)
	{
		printf("%d ", ptrL->value);
		ptrL = ptrL->ptrPrevious;
	}
}

int CountList(struct node * ptrF)
{
	// base case: empty list
	if (ptrF == NULL)
		return 0;
	else
	{
		return CountList(ptrF->ptrNext) + 1;
	}
}

void DeleteFirst()
{
	struct node * ptrDelete = NULL;

	if (isEmpty())
	{
		return;
	}
	
	if (ptrFirst == ptrLast)  // if there is only one node!
	{
		free(ptrFirst);
		ptrFirst = NULL;
		ptrLast = NULL;
	}
	else
	{
		// delete from a big list
		ptrDelete = ptrFirst;
		ptrFirst = ptrFirst->ptrNext;
		ptrFirst->ptrPrevious = NULL;
		free(ptrDelete);
	}
}

void DeleteLast()
{
	struct node * ptrDelete = NULL;
	struct node * ptrPrevious = NULL;

	if (isEmpty)
	{
		return;
	}
	
	if (ptrFirst == ptrLast)
	{
		free(ptrFirst);
		ptrFirst = NULL;
		ptrLast = NULL;
	}
	else
	{
		// delete from a big list
		ptrDelete = ptrLast;
		ptrPrevious = ptrFirst;
		
		while (ptrPrevious->ptrNext != ptrLast)
		{
			ptrPrevious = ptrPrevious->ptrNext;
		}

		ptrLast = ptrPrevious;
		ptrLast->ptrNext = NULL;

		free(ptrDelete);
	}
}

void DeleteLastUsingPrev()
{
	struct node * ptrDelete = NULL;

	if (isEmpty())
	{
		return;
	}
	
	if (ptrFirst == ptrLast)  // is there only one node left?
	{
		free(ptrFirst);
		ptrFirst = NULL;
		ptrLast = NULL;
	}
	else
	{
		// delete from a big list
		ptrDelete = ptrLast;
		ptrLast = ptrLast->ptrPrevious;
		ptrLast->ptrNext = NULL;
		free(ptrDelete);
	}
}

void Insert(struct node *ptrNew)
{
	struct node *ptrP = ptrFirst;

	if (ptrNew == NULL)
		return;

	if (isEmpty())
	{
		AddFirst(ptrNew);
		return;
	}
	
	if (ptrNew->value <= ptrFirst->value)
	{
		AddFirst(ptrNew);
		return;
	}

	if (ptrNew->value >= ptrLast->value)
	{
		AddLast(ptrNew);
		return;
	}

	while(ptrNew->value >= ptrP->value)
	{
		ptrP = ptrP->ptrNext;
	}
	ptrP = ptrP->ptrPrevious;
	
	ptrNew->ptrNext = ptrP->ptrNext;
	ptrP->ptrNext->ptrPrevious = ptrNew;
	ptrP->ptrNext = ptrNew;
	ptrNew->ptrPrevious = ptrP;

}

struct node * Search(int key)
{
	struct node *ptrCurrent = ptrFirst;

	if (isEmpty())
		return NULL;

	while(ptrCurrent != NULL && ptrCurrent->value != key)
	{
		ptrCurrent=ptrCurrent->ptrNext;
	}
	return ptrCurrent;
}


struct node * SearchRecursive(struct node *ptrF, int key)
{
	if (ptrF == NULL)
		return NULL;
	if (ptrF->value == key)
		return ptrF;

	return SearchRecursive(ptrF->ptrNext, key);
}
