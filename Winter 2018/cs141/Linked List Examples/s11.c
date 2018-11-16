#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define _QUIT_ 0

// structure definition
struct point
{
	int x;			// x-coord, +ve
	int y;			// y-coord, -ve
	char label[20];		// 19 chars + \0
	struct point *ptrNext;	// Self-referential pointer
};

typedef struct point Point;

/* Specifics for the interactive/dynamic menu */
const char *MENU[] = {  
			"Add new record",
                  	"Display records"};
const int MENU_COUNT = 2;


int GetInput(const char* msg, int min, int max);
int GetMenuItem(const char *menu_title);

int main()
{
	int done = 0;		// 0= not done, 1= done
	
	do
	{
	  done = GetMenuItem("Main Menu");

	  switch(done)
	  {

		case 1://add
			Add(

	} while (done);

	return 0;
}

/* Prompts the user and retrieves a valid input
   INPUT: the user supplies the valid prompt and range (min and max)
   OUTPUT: returns a valid user selection
*/
int GetInput(const char* msg, int min, int max)
{
   int n = 0;
   do
      {
      printf(msg);
      scanf("%d", &n);

      if(n >= min && n <= max)
         return n;
      else
         printf("*Invalid Input* ");

   }while(1);

//   return -1;
}

/* Interactive/Dynamic menu that displays the menu and retrieves a selection
   INPUT: requires MENU[], MENU_COUNT and _QUIT_ to be defined, uses int GetInput(const char* msg, int 
min, int max)
   OUTPUT: a valid menu item
*/
int GetMenuItem(const char *menu_title)
{
   int i;

   printf("\n%s\n", menu_title);
   for (i=0; i<strlen(menu_title); i++)
   {
      printf("-");
   }
   printf("\n");

   for (i=0; i<MENU_COUNT; i++)
   {
      printf("%3d - %s\n", i+1, MENU[i]);
   }
   printf("%3d - QUIT\n", _QUIT_);

   return GetInput("Please enter a selection: ", 0, MENU_COUNT);
}


