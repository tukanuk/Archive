#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct node
{
	char s[10];
	int n;

	struct node *ptrNext;
	struct node *ptrPrevious;
};


struct node *ptrFirst = NULL;
struct node *ptrLast = NULL;


struct node *CreateNode();
struct node *InputNode(struct node *ptrCurrent);

int isEmpty();

void AddAtBeginning(struct node* ptrNew);
void AddAtEnd(struct node* ptrNew);

void InsertS(struct node* ptrNew);
void InsertN(struct node* ptrNew);

void ClearList(struct node* ptrF);
void PrintList(struct node* ptrF);
void PrintListReverse(struct node* ptrF);

int main()
{
	InsertS(InputNode(CreateNode()));
	InsertS(InputNode(CreateNode()));
	InsertS(InputNode(CreateNode()));
	InsertS(InputNode(CreateNode()));

	PrintList(ptrFirst);
	ClearList(ptrFirst);

	return 0;
}

struct node *CreateNode()
{
	struct node *ptrNew = NULL;
	ptrNew = (struct node*)(malloc(sizeof(struct node)));
	if (ptrNew != NULL)
	{
		ptrNew->ptrNext = NULL;
		ptrNew->ptrPrevious = NULL;
	}
	return ptrNew;
}

struct node *InputNode(struct node *ptrCurrent)
{
	if (ptrCurrent != NULL)
	{
		printf("Enter s and n: ");
		scanf("%s%d", ptrCurrent->s, &ptrCurrent->n); 
	}

	return ptrCurrent;
}


int isEmpty()
{
	if (ptrFirst == NULL)
		return 1;
	else
		return 0;
}

void AddAtBeginning(struct node* ptrNew)
{
	if (ptrNew == NULL)
		return;

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
}


void AddAtEnd(struct node* ptrNew)
{
	if (ptrNew == NULL)
		return;

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

void InsertS(struct node* ptrNew)
{
	struct node* ptrCurrent = ptrFirst;

	if (ptrNew == NULL)
		return;

	if (isEmpty())
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}	
	else if (strcmp(ptrNew->s, ptrFirst->s) <= 0)
	{
		AddAtBeginning(ptrNew);
	}
	else if (strcmp(ptrNew->s, ptrLast->s) >= 0)
	{
		AddAtEnd(ptrNew);
	}
	else
	{
		ptrCurrent = ptrFirst;
		while(strcmp(ptrNew->s, ptrCurrent->ptrNext->s) >= 0)
		{
			ptrCurrent = ptrCurrent->ptrNext;
		}

		ptrNew->ptrNext = ptrCurrent->ptrNext;
		ptrCurrent->ptrNext = ptrNew;
		ptrNew->ptrNext->ptrPrevious = ptrNew;
		ptrNew->ptrPrevious = ptrCurrent;
	}
}

void InsertN(struct node* ptrNew)
{
	struct node* ptrCurrent = ptrFirst;

	if (ptrNew == NULL)
		return;

	if (isEmpty())
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}	
	else if (ptrNew->n <= ptrFirst->n)
	{
		AddAtBeginning(ptrNew);
	}
	else if (ptrNew->n >= ptrLast->n)
	{
		AddAtEnd(ptrNew);
	}
	else
	{
		ptrCurrent = ptrFirst;
		while(ptrNew->n >= ptrCurrent->ptrNext->n)
		{
			ptrCurrent = ptrCurrent->ptrNext;
		}

		ptrNew->ptrNext = ptrCurrent->ptrNext;
		ptrCurrent->ptrNext = ptrNew;
		ptrNew->ptrNext->ptrPrevious = ptrNew;
		ptrNew->ptrPrevious = ptrCurrent;
	}
}

void ClearList(struct node* ptrF)
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

void PrintList(struct node *ptrF)
{
	if (ptrF==NULL)
	{
		return;
	}
	else
	{
		printf("Node: %d %s.\n", ptrF->n, ptrF->s);
		PrintList(ptrF->ptrNext);
	}
}

void PrintListReverse(struct node* ptrF)
{
	if (ptrF==NULL)
	{
		return;
	}
	else
	{
		PrintList(ptrF->ptrNext);
		printf("Node: %d %s.\n", ptrF->n, ptrF->s);
	}
}

