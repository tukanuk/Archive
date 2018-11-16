#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 0

// DOCUMENT!!!!!!
struct point
{
        int x;
        int y;
        char label[21];
        struct point *ptrNext; // self referential pointer
};

/*** Prototypes ***/
int isEmptyList(struct point **ptrF);
void PrintList(struct point **ptrF);
void ResetList(struct point **ptrF, struct point **ptrL);
void AddToBeginning(struct point **ptrF, struct point **ptrL);
void AddToEnd(struct point **ptrF, struct point **ptrL);
void InputRecord(struct point *ptrNew); // used by Add to interactively get the values from the user

int ReallyBasicMenu(struct point **ptrF, struct point **ptrL, struct point *ptrN);

int savePoint(struct point **ptrF, struct point **ptrL);
int nStrip(char *strStrip);
int loadPoints(struct point **ptrF, struct point **ptrL);

/*** NOTES ***/
// TODO: The C Book - http://publications.gbdirect.co.uk/c_book/
// TODO: pointers should always be pointing to something valid or NULL. Otherwise, a DANGLING pointer ensuses.
// TODO: When you add a linked list item, hoot it up to the list first, then move the pointer to the list
// TODO: REDO this whole things to take advantage of the global variables
// Expecting diagrams on the exam
// There will be a question to trace linked lists on the exam

// Glovbal pointers to maintain the linked list
struct point *ptrFirst = NULL; // keep track of the start of list
struct point *ptrLast = NULL;  // keep track of last node in list

int main()
{
        struct point *ptrPointNew; // keep track of new node
        ptrPointNew = (struct point *)malloc(sizeof(struct point));
        if (ptrPointNew == NULL)
        {
                printf("Error allocatiing memory\n");
                return 1;
        }

        int closeCheck = 0;
        do
        {
                closeCheck = ReallyBasicMenu(&ptrFirst, &ptrLast, ptrPointNew);
        } while (closeCheck != -1);

        return 0;
}

/*
 *	ReallyBasicMenu: A quick menu to select funcitons
 *		INPUT: None
 *		OUTPUT: the chosen function
*/
int ReallyBasicMenu(struct point **ptrF, struct point **ptrL, struct point *ptrN)
{
        printf("\n**** Lab #7: Dynamic Memory Allocation ****\n");
        printf("1. Add a point at the END of the list\n");
        printf("2. Add a point at the BEGINNING of the list.\n");
        printf("3. Is the list empty?\n");
        printf("4. Erase all points from the list (reset).\n");
        printf("5. Display the list.\n");
        printf("6. Save the list to a sequential file.\n");
        printf("7. Read the list back from a sequential file.\n");
        printf("8. Exit.\n");

        int keyValue;
        scanf("%d", &keyValue);
        system("clear");

        switch (keyValue)
        {
        case 1:
                // Add a point at the END of the list
                AddToEnd(ptrF, ptrL);
                break;
        case 2:
                // Add a point at the END of the list
                AddToBeginning(ptrF, ptrL);
                break;
        case 3:
                // Is the list empty?
                isEmptyList(ptrF);
                break;
        case 4:
                // Erase all points from the list (reset)
                ResetList(ptrF, ptrL);
                break;
        case 5:
                // Display the list
                PrintList(ptrF);
                break;
        case 6:
                // Save the list to a sequential file
                savePoint(ptrF, ptrL);
                break;
        case 7:
                // Read the list back from a sequential file
                loadPoints(ptrF, ptrL);
                break;
        case 8:
                // Exits the program
                return -1;
                break;
        }

        return 1;
}

// checks for an empty list
int isEmptyList(struct point **ptrF)
{
        if (*ptrF == NULL)
        {
                printf("Empty\n");
        }
        else
        {
                printf("nope.\n");
        }
        return 0;
}

void PrintList(struct point **ptrF)
{
        //printf("Here?\n");
        struct point *ptrCurrent = *ptrF;
        //ptrCurrent = (struct point *)malloc(sizeof(struct point));
        //ptrCurrent = *ptrF;
        int counter = 1;
        while (ptrCurrent != NULL)
        {
                //printf("print here.\n");
                printf("Entry #%d:\n", counter++);
                printf("       x: %d\n", (ptrCurrent)->x);
                printf("       y: %d\n", (ptrCurrent)->y);
                printf("   label: %s\n\n", (ptrCurrent)->label);

                ptrCurrent = (ptrCurrent)->ptrNext;
        }
        // while ( ptrCurrent != NULL )
        // {
        //         printf("x: %d\n", ptrCurrent->x);
        //         printf("y: %d\n", ptrCurrent->y);
        //         printf("label: %s\n\n", ptrCurrent->label);

        //         ptrCurrent = ptrCurrent->ptrNext;
        // }
}

//clear the list
void ResetList(struct point **ptrF, struct point **ptrL)
{
        struct point *ptrDelete;

        if (*ptrF == NULL)
        {
                free(*ptrF);
                free(*ptrL);
        }

        while (*ptrF != NULL)
        {
                ptrDelete = (*ptrF)->ptrNext;
                free(*ptrF);
                free(*ptrL);
                *ptrF = ptrDelete;
                free(ptrDelete);
        }

        *ptrF = NULL;
        *ptrL = NULL;
}

// adds a linked list item to the beginning of the list
void AddToBeginning(struct point **ptrF, struct point **ptrL)
{
        struct point *ptrPointNew; // keep track of new node
        ptrPointNew = (struct point *)malloc(sizeof(struct point));
        if (ptrPointNew == NULL)
        {
                printf("Error allocating memory\n");
                return;
        }

        InputRecord(ptrPointNew);

        if (ptrPointNew != NULL)
        {
                ptrPointNew->ptrNext = *ptrF;
                *ptrF = ptrPointNew;
        }
}

// adds a node to the end of a linked list
void AddToEnd(struct point **ptrF, struct point **ptrL)
{
        struct point *ptrPointNew; // keep track of new node
        ptrPointNew = (struct point *)malloc(sizeof(struct point));
        if (ptrPointNew == NULL)
        {
                printf("Error allocatiing memory\n");
                return;
        }

        InputRecord(ptrPointNew);

        // if there is no second node add after the first
        if ((*ptrF) == NULL)
        {
                (*ptrF) = ptrPointNew;
        }
        else
        {
                struct point *current = (*ptrF);
                while (1)
                {
                        if (current->ptrNext == NULL)
                        {
                                current->ptrNext = ptrPointNew;
                                printf("TO END.\n");
                                break;
                        }
                        current = current->ptrNext;
                }
        }
}

void InputRecord(struct point *ptrNew)
{
        printf("Enter x: ");
        scanf("%d", &ptrNew->x);
        printf("Enter y: ");
        scanf("%d", &ptrNew->y);
        printf("Enter label: ");
        scanf("%s", ptrNew->label);
        printf("\n");
}

/*
 *	savePoint: to save all tweets to an output file
 *		INPUT: Tweet timeline, last tweet ID, user input for filename
 *		OUTPUT: a file containing all tweet data. if file cannot be craeted exit function
 */
int savePoint(struct point **ptrF, struct point **ptrL)
{
        char filename[255]; // stores filename
        printf("\n  Filename: ");
        char temp[50];
        fgets(temp, sizeof temp, stdin); // lazy clear of scanf data from the menu
        fgets(filename, sizeof filename, stdin);

        // removes '\n' from string
        nStrip(filename);

        // Opens the file and checks for success
        FILE *tweetFile = fopen(filename, "w");
        if (!tweetFile)
        {
                perror("File opening failed");
                return EXIT_FAILURE;
        }

        int counter = 0;

        struct point *ptrTemp;

        ptrTemp = *ptrF;

        // uses fprintf to print one item of struct data on each line, moving through entire struct
        while (ptrTemp != NULL)
        {
                fprintf(tweetFile, "%d\n", (*ptrTemp).x);
                fprintf(tweetFile, "%d\n", (*ptrTemp).y);
                fprintf(tweetFile, "%s\n", (*ptrTemp).label);
                // fprintf(tweetFile, "%s\n", *ptrTemp.);
                counter++;

                ptrTemp = (*ptrTemp).ptrNext;
        }

        // summary line
        printf("  %d records(s) saved in the file \"%s\"", counter, filename);

        // always close your file!
        fclose(tweetFile);

        return 0;
}

/*
 *	nStrip: removes '\n' from string
 *		INPUT:  ptr to the string that needs stripping
 *		OUTPUT:  removes '\n' if found and replaces it with '\0'
*/
int nStrip(char *strStrip)
{
        char *c;
        if ((c = strchr(strStrip, '\n')) != NULL)
        {
                *c = '\0';
        }

        return 0;
}

/*
 *	loadPoints: loads tweets from a text file
 *		INPUT: Tweet timeline, last tweet ID, user input filename   
 *		OUTPUT:  a list of tweets that were loaded, error messag if file not found  
*/
int loadPoints(struct point **ptrF, struct point **ptrL)
{
        char filename[255]; // filename
        printf("\n  Filename: ");
        char temp[50];
        fgets(temp, sizeof temp, stdin);         // lazy clear of scanf data from the menu
        fgets(filename, sizeof filename, stdin); // captures the line containing the filename

        // removes '\n' from string
        nStrip(filename);

        // opens the file and checks for errors
        FILE *tweetFile = fopen(filename, "r");
        if (!tweetFile)
        {
                perror("File opening failed");
                return EXIT_FAILURE;
        }

        // Temp variables for loading data
        int tmpID = 0;  // starts a new temp ID
        char buff[200]; // buffer to hold each line of the file as a string

        int counter;
        //ptrPointNew = (struct point *)malloc(sizeof(struct point));

        struct point *ptrPointNew; 
        ptrPointNew = (struct point *)malloc(sizeof(struct point));
        
        // *ptrTemp = *ptrF;

        // goes through the file one line at a time until NULL
        //fgets(buff, sizeof buff, tweetFile);
        while (fgets(buff, sizeof buff, tweetFile) != NULL)
        {
                if (DEBUG) printf("  x: %s\n", buff);
                nStrip(buff);
                ptrPointNew->x = atoi(buff); // converts the first line to an int and stores as id
                if (DEBUG) printf("  ptrx: %d\n", ptrPointNew->x);

                fgets(buff, sizeof buff, tweetFile);
                nStrip(buff);
                if (DEBUG) printf("  y: %s\n", buff);
                ptrPointNew->y = atoi(buff); // converts the first line to an int and stores as id

                fgets(buff, sizeof buff, tweetFile);
                nStrip(buff);
                if (DEBUG) printf("  label: %s\n", buff);
                strncpy(ptrPointNew->label, buff, 20); // copies second line to created_at (only the first 51 char)
                if (DEBUG) printf("%s\n", buff);

                counter++;

                if ((*ptrF) == NULL)
                {
                        (*ptrF) = ptrPointNew;
                        ptrPointNew->ptrNext = NULL;
                }
                else
                {
                        struct point *current = (*ptrF);
                        
                        current->ptrNext = ptrPointNew;
                        current = current->ptrNext;
                
                
                        // while (1)
                        // {
                        //         if (current->ptrNext == NULL)
                        //         {
                        //                 current->ptrNext = ptrPointNew;
                        //                 //printf("TO END.\n");
                        //                 break;
                        //         }
                        //         current = current->ptrNext;
                        // }
                }

                
        }

        // sumnmary line
        printf("   %d point(s) were sucessfully loaded!", counter);

        fclose(tweetFile); // close the file

        return 0;
}