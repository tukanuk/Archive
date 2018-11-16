/*
 * lab4.c answer to lab 4
 * 60-141
 * Ben Davidson
 * 104924033
 */
#include <stdio.h>
#include <string.h>

/** Prototype **/

void Reverse(char *array);
void RecursiveReverse(char *ptrArray, int i, int l);

int main(void)
{
    
    /** Part I: Storing a string **/
	
	char Buffer1[] = { 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 
    'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '\0' };
    
    char Buffer2[] = "this is the second buffer";

    char Buffer3[80];

    printf("\nPART I\n");
    printf("Enter some text: ");
    //scanf("%79s", Buffer3); // allows input up to 79 characters or a space/new line
							  // stops at space.
	

    scanf("%79[^\n]s", Buffer3); // allows input up to 79 characters or a space/new line
								 // used an inverted scanset to stop at \n
    
	printf("Buffer 1: %s\n", Buffer1); 
    printf("Buffer 2: %s\n", Buffer2);
    printf("Buffer 3: %s\n", Buffer3);
   
    /** Part II: Using a pointer to access the array **/

    printf("\nPART II\n");
    printf("pBuffer: ");

    char *pBuffer = Buffer3; // char pointer to Buffer3

    while (*pBuffer != '\0')
    {
        printf("%c", *pBuffer++);
    }

	/** Part III: String Manipulation **/

    printf("\n\nPART III\n");
    printf("Reverse Function\n");
	printf("Original string: %s\n", Buffer3);
    Reverse(Buffer3);
    printf("The reverse is:  %s\n", Buffer3);

 	
    printf("\nRecursive Reverse Function\n");
	printf("Original string: %s\n", Buffer3);
    RecursiveReverse(Buffer3, 0, (strlen(Buffer3) - 1) );
    printf("The reverse is:  %s\n\n", Buffer3);

    return 1;
}

/**
 * Reverse: reverses the string in memory
 * INPUT: char array 
 * RETURN: void 
 */
//void Reverse(char *array)
//{
//    char temp[80];
//    char *ptrTemp = temp;
//
//    unsigned long length = strlen(array);
//
//    for (int i = 0 ; (ptrTemp[i] = array[i]) != '\0' ; ++i)
//    {
//        ;
//    }
//    
//    // printf("ptrTemp: %s\n", ptrTemp);
//    // printf("length: %lu\n", length);
//    // printf("ptrTemp at end: %c\n", ptrTemp[length-1]);
//
//    for (int i = 0 ; ptrTemp[i] != '\0' ; ++i)
//    {
//        array[i] = ptrTemp[length - 1 - i];
//    }
//
//    // printf("array: %s\n", array);
//}


/**
 * Reverse: reverses the string in memory
 * INPUT: char array 
 * RETURN: void 
 */
void Reverse(char *array)
{
    char temp[80];
    char *ptrTemp = temp;

    unsigned long length = strlen(array);

    for (int i = 0 ; (*(ptrTemp + i) = *(array + i)) != '\0' ; ++i)
    {
        ;
    }

    //printf("ptrTemp: %s\n", ptrTemp);

    for (int i = 0 ; *(ptrTemp + i) != '\0' ; ++i)
    {
        *(array + i) = *(ptrTemp + length - 1 - i);
    }

    // printf("array: %s\n", array);
}

/*
 * RecursiveReverse: reverses the string in memory receursviely
 * INPUT: a char array, index and length of array
 * OUTPUT: reverses the array in memory
 */
void RecursiveReverse(char *ptrArray, int i, int l )
{

	// sets up a temp variable for the char that will be swapped
	char temp;
	temp = *(ptrArray + i);

	// printf ("\n%c\n", temp);

	*(ptrArray + i ) = *(ptrArray + l - i ); // puts the last char in teh first postion 
											 // moving in each time
	*(ptrArray + l - i ) = temp; // puts the temp (first) char in the last position

	if (i == ( l / 2 ) ) // if halfway through the string stop. 
						 // will swap an odd middle character unnecessarily 
	{
		return;
	}

    RecursiveReverse(ptrArray, i + 1, l); // recursive step
    
}
