/*
 Name:		lab8_tree.c
 Purpose:	Lab 8
            CS254
 Author:  	Ben Davidson
            104924033
 Date:    	0713-2018 2:25
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "../sharedFunctions.h"

#define LOWER   -100
#define UPPER   100
#define SIZE    10
#define DEBUG   0

typedef struct node Node ;

struct node {
    int key;
    Node *left;
    Node *right;

};

/** Global **/
int numberOfFullNodes       = 0;
int numberOfLeaves          = 0;
int numberOfOneChildNodes   = 0;
int counter = 0;
// other global counters

/** Prototypes **/
Node *CreateNode(void);
Node *InputNode(Node *ptrNew, int);
Node *addTree(Node *ptrNew, int);
void postOrderCount(Node *);
void preOrderCount(Node *);
void destroyTree(Node *);
void print_inOrder(Node *);

int main (int argc, char * argv[])
{
    if (argv[1] == NULL) 
    {
        printf("usage: lab8 size_of_array\nSpecify the size of the array as a command line argument.\n");
        return 0;
    }

    /** Setup the header and the random array **/
    header("Lab 8 Question 2", "July 9, 2018");
    char * finish;
    int arraySize = strtol(argv[1], &finish, 10);
    int ra[arraySize];
    RandomArray(ra, arraySize, LOWER, UPPER); 
    
    // test arrays
    // int ra[10] = {21, 20, 53, 61, 38, 16, 18, 72, 3, 65};
    // int ra[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    // int ra[10] = {0,   14,   77,   45,   89,   84,   96,   39,   82,   85};
    // int ra[10] = {99, 20, 53, 61, 38, 16, 18, 72, 3, 65};
    
    /* Print the values to be added to the tree */
    printf("A[]: ");
    printArray(ra, arraySize);

    /* Create the binary tree */
    Node *binaryTree;
    binaryTree = NULL;
    

    /* Build the binary tree */
    for (int i = 0 ; i < arraySize ; i++)
    {
        binaryTree = addTree(binaryTree, ra[i] );
    }

    /* Output the inorder arrray and node data */
    printf(" io: ");
    print_inOrder(binaryTree);
    printf("\n\nLeaves:       %d\n", numberOfLeaves);
    printf("One Child:    %d\n", numberOfOneChildNodes);
    printf("Two children: %d\n", numberOfFullNodes);

    /* Cleanup the mess */
    destroyTree(binaryTree);

    return 0;
}

/* CreateNode: Creates a struct Node
 * INPUT:
 * OUTPUT: a Node
 */
Node *CreateNode(void)
{
    /* Cast to stuct Node, allocate memory of size Node */
    return (Node *) malloc(sizeof(Node));
}
/* addTree: adds a node to a binary tree
 * INPUT:   a pointer to the binary tree and a key to be added
 * OUPTUT:  returns a the binary tree
 */
Node *addTree(Node *ptrNew, int newKey)
{
    Node *temp = NULL;           // a temp struct * node to work with 

    if (ptrNew == NULL)         // if node being examined is NULL create a new node 
    {
        temp = CreateNode();    // allocate memory to the temp node 
        temp->key = newKey;     // set the key
        temp->left = NULL;      // set the left pointer to NULL
        temp->right = NULL;     // set the right pointer to NULL
        ptrNew = temp;
        
    }
    else if (ptrNew->key > newKey)                      // the key is smaller, move down the left side
    {
        ptrNew->left = addTree(ptrNew->left, newKey);
    }
    else if (ptrNew->key < newKey)                      // the key is larger, move down teh right side
    {
        ptrNew->right = addTree(ptrNew->right, newKey);
    }
    else return ptrNew;                                 // the key is a duplicate, skip it

    return ptrNew;
}


/* destroyTree: recusively destroy a binary tree
 *       INPUT: the tree to be destroyed
 *       OUPUT: 
 */
void destroyTree(Node * delNode)
{
    if (delNode)                     // if there is a node
    {
        destroyTree(delNode->left); // work down to the left
        destroyTree(delNode->right);// work to the right    
        free(delNode);              // free the node and the bottom
    }
}

/* inOrder: traverse the tree in order
 *   INPUT: a tree
 *  OUTPUT: increments counter date for nodes and outputs the nodes in orders
 */
void print_inOrder(Node * tree)
{
    /* This will recursively work all the way to the smallest value and build up incrementally by key */
    if (tree)
    {
        print_inOrder(tree->left); // work down the left side

        if  (tree->left == NULL && tree->right == NULL) numberOfLeaves++; // if no children
        if ((tree->left == NULL && tree->right != NULL) ||                  
            (tree->left != NULL && tree->right == NULL) ) numberOfOneChildNodes++; // if one child
        if  (tree->left != NULL && tree->right != NULL) numberOfFullNodes++; // if if two children
        printf("%5d", tree->key); // print the key
        
        print_inOrder(tree->right); // work down the right side
    }
}