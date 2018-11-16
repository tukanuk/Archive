#include <stdio.h>
#include <stdlib.h>

// struct def of node
struct node 
{
    int value;      // node content
    struct node* ptrNext; // self ref pointer
};

int isEmpty();
struct node* AddBeginning (struct node* ptrNew);
struct node* AddEnd (struct node* ptrNew);
struct node* PrintListRecursive(struct node* ptrCurrent);
struct node* ClearListRecursive(struct node* ptrCurrent);
struct node* Insert (struct node* ptrNew);
struct node* CreateNode (int value);
int SavetoFile(const char* filename);
int LoadtoFile(const char* filename);

// global list definition 
struct node* ptrFirst = NULL;
struct node* ptrLast = NULL;

int main()
{
    Insert(CreateNode(5));
    Insert(CreateNode(1));
    Insert(CreateNode(4));
    Insert(CreateNode(2));
    Insert(CreateNode(3));

    PrintListRecursive(ptrFirst);
    ClearListRecursive(ptrFirst);

    return 0;
}

struct node* CreateNode (int value)
{
    struct node* ptrNew = (struct node*) (malloc(sizeof(struct node)) );
    ptrNew->value = value;
    ptrNew->ptrNext = NULL;

    return ptrNew;
}
int isEmpty()
{
    return (ptrFirst == NULL);
}

struct node* AddBeginning (struct node* ptrNew)
{
    if (isEmpty() )
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrNew->ptrNext = ptrFirst;
        ptrFirst = ptrNew;
    }

    return ptrNew;
}

struct node* AddEnd (struct node* ptrNew)
{
    if (isEmpty() )
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrLast->ptrNext = ptrNew;
        ptrLast = ptrNew;
    }

    return ptrNew;
}

struct node* Insert (struct node* ptrNew)
{
    struct node* ptrPrevious = NULL;

      if (isEmpty() )
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else if (ptrNew->value <= ptrFirst->value)
    {
        AddBeginning(ptrNew);
    }
    else if (ptrNew->value >= ptrLast->value)
    {
        AddEnd(ptrNew);
    }
    else
    {
        ptrPrevious = ptrFirst;
        while ( ptrPrevious->ptrNext->value <= ptrNew->value)
        {
            ptrPrevious = ptrPrevious->ptrNext;
        }
        ptrNew->ptrNext = ptrPrevious->ptrNext;
        ptrPrevious->ptrNext = ptrNew;
    }
    return ptrNew;
}

struct node* PrintListRecursive(struct node* ptrCurrent)
{
    // base case
    if (ptrCurrent != NULL)
    {
        // recursive call
        printf("%d ", ptrCurrent->value); 
        PrintListRecursive(ptrCurrent->ptrNext); 
    }
    return ptrCurrent;
}

struct node* ClearListRecursive(struct node* ptrCurrent)
{
    // base case
    if (ptrCurrent != NULL)
    {
        // recursive call
        ClearListRecursive(ptrCurrent->ptrNext); 
        free(ptrCurrent);
    }
    
    ptrFirst = NULL;
    ptrLast =  NULL;

    return ptrCurrent;

}

int SavetoFile(const char* filename)
{
    FILE* ptrFile;
    struct node* ptrCurrent = ptrFirst;

    if (isEmpty() )
    {
        return 0;
    }

    
}