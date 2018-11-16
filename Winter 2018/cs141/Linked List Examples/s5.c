#include<string.h>
#include<stdio.h>
#include<ctype.h>

// Define a word structure
struct word
{
	char value[51];	// stores a string of 50 chars
};

// Alias:
typedef struct word Word;

// void getWord(Word w);

// printWord(w);

void modify(Word *wptr);

int main()
{
	Word w;

	gets(w.value);

	printf("BEFORE: %s\n", w.value);
	modify(&w);
	printf("AFTER: %s\n", w.value);
	


//	getWord(w);
//	printWord(w);

	return 0;
}


void modify(Word *wptr)
{

	wptr->value[0] = toupper(wptr->value[0]);

}
