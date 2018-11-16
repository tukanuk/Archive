#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// structrue def of word type - self ref struct for linked list
struct word
{
	char value[MAX];	// hold the actual word
	struct word* ptrNext; //self-ref pointer
};

// prototypes
struct word* CreateWord(char *s);
struct word* InsertNode(struct word* ptrNew);
void PrintList();
void ClearList(struct word* ptrD);
struct word* DeleteWord(char *s);
int SaveFile(char *filename);
int LoadFile(char *filename);

// global variables
struct word* ptrFirst = NULL;
struct word* ptrLast = NULL;

int main()
{
	//InsertNode(CreateWord("tim"));
	//InsertNode(CreateWord("jim"));
	//InsertNode(CreateWord("kim"));
	//InsertNode(CreateWord("slim"));
	
	//PrintList();
	//DeleteWord("kim");
	//PrintList();

	//SaveFile("wordlist.txt");
	LoadFile("wordlist.txt");
	PrintList();
	ClearList(ptrFirst);

	return 0;
}

// create a word sturcture dunmaically from a string
// reutrn a pointer to a new structure
struct word* CreateWord(char *s)
{
	struct word *ptrNew;	// point ot the new node
	ptrNew =(struct word*)(malloc(sizeof(struct word)));
	strcpy(ptrNew->value, s);
	ptrNew->ptrNext = NULL;

	return ptrNew;
};

// insert node to the list so it is sorted alphbeticall by value
struct word* InsertNode(struct word* ptrNew)
{
	struct word* ptrPrevious = ptrFirst;

	// empty lsit
	if (ptrFirst == NULL)
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}
	else if (strcmp(ptrNew->value, ptrFirst->value) < 0)	// first spot
	{
		ptrNew->ptrNext = ptrFirst;
		ptrFirst = ptrNew;
	}
	else if (strcmp(ptrNew->value, ptrLast->value) > 0) // add to end
	{
		ptrLast->ptrNext = ptrNew;
		ptrLast = ptrNew;
	}
	else  // add to middle
	{
		ptrPrevious = ptrFirst;
		while(strcmp(ptrPrevious->ptrNext->value, ptrNew->value) < 0)
		{
			ptrPrevious = ptrPrevious->ptrNext;
		}
		ptrNew->ptrNext = ptrPrevious->ptrNext;
		ptrPrevious->ptrNext = ptrNew;
	}

	return ptrNew;
}

// print the whole lsit
void PrintList()
{
	struct word* ptrCurrent = ptrFirst;

	while(ptrCurrent != NULL)
	{
		printf("  %s\n", ptrCurrent->value);
		ptrCurrent = ptrCurrent->ptrNext;
	}
}

// clear the lsit
void ClearList(struct word *ptrD)
{
	// base case: empty list
	if (ptrD == NULL)
	{
		return;
	}
	else	// recursive call
	{
		return ClearList(ptrD->ptrNext);
		free(ptrD);
	}

	ptrFirst = NULL;
	ptrLast = NULL;
}

// search for word indicated in teh param and ears that node
struct word* DeleteWord(char *s)
{
	struct word* ptrDelete = NULL;		// node to delete
	struct word* ptrPrevious = NULL;	// previous node
	
	// empty list
	if (ptrFirst == NULL)
	{
		return NULL;
	}
	else
	{
		// search for the node to delete
		ptrDelete = ptrFirst;
		while ( ptrDelete != NULL && 
			    strcmp(ptrDelete->value, s) != 0)
		{
			ptrDelete = ptrDelete->ptrNext;
		}
		if (ptrDelete != NULL)
		{
			// Delete
			// 3 cases: F, L or middle
			if (ptrDelete == ptrFirst)
			{
				ptrFirst = ptrFirst->ptrNext;
				free(ptrDelete);
				if (ptrFirst == NULL)		// check for last node
				{
					ptrLast = NULL;
				}
			}
			else if (ptrDelete == ptrLast)
			{
				ptrPrevious = ptrFirst;
				while (ptrPrevious->ptrNext != ptrLast)
				{
					ptrPrevious = ptrPrevious->ptrNext;
				}
	
				ptrLast = ptrPrevious;
				ptrPrevious->ptrNext = NULL;
				free(ptrDelete);
			}
			else 
			{
				ptrPrevious = ptrFirst;
				while (ptrPrevious->ptrNext != ptrDelete)
				{
					ptrPrevious = ptrPrevious->ptrNext;
				}
				ptrPrevious->ptrNext = ptrDelete->ptrNext;
				free(ptrDelete);
			}
		}

	}

	return NULL;
}
// over the contents of the file with the contents of the lsit
int LoadFile(char *filename)
{
	FILE* ptrFile;
	int records = 0;
	char value[MAX];

	ClearList(ptrFirst);

	ptrFile = fopen(filename, "r");
	if (ptrFile == NULL)
	{
		return -1;
	}

	while(!feof(ptrFile))
	{
		fscanf(ptrFile, "%s", value);
		records++;
		InsertNode(CreateWord(value));
	}
		
		//ptrCurrent =ptrCurrent->ptrNext;
	
	fclose(ptrFile);
	return records;
}

// over the contents of the file with the contents of the lsit
int SaveFile(char *filename)
{
	FILE *ptrFile;
	int records = 0;
	struct word* ptrCurrent = ptrFirst;

	ptrFile = fopen(filename, "w");
	if (ptrFile == NULL)
	{
		return -1;
	}

	while(ptrCurrent !=NULL)
	{
		if (records == 0)
		{
			fprintf(ptrFile, "%s", ptrCurrent->value);
		}
		else
		{
			fprintf(ptrFile, "\n%s", ptrCurrent->value);
		}
		records++;
		ptrCurrent = ptrCurrent->ptrNext;
	}

	fclose(ptrFile);
	return records;
}

