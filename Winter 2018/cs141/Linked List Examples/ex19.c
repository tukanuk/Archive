#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 10


// book record definition
struct book
{
	char title[51];		// book title
	char author[31];	// Author (last, first name)
	int pages;		// >0
	int bookid;		// unique auto-increment > 0
};

// maintain the next number to be used for the book id; used by AddBook to maintain unique numbering system
int NextBookID = 0;



void PrintBook(struct book b);
void PrintBook(struct book b)
{
	printf("Title:\t%s\nAuthor:\t%s\nPages:\t%d, (ID: %d)\n", b.title, b.author, b.pages, b.bookid);
}


void PrintBookList(struct book blist[], int size);
void PrintBookList(struct book blist[], int size)
{
	int i;
	for (i=0; i < size; i++)
	{
		PrintBook(blist[i]);
		printf("-------------------------------\n");
	}
}


// add a new book record to the list; auto-increment the id - makes use of NextBookID (auto-incremented global counter)
// return the index of where the new book was added (-1 if list size exceeded)
int AddBook(struct book blist[], struct book newb);
int AddBook(struct book blist[], struct book newb)
{
	// check list capacity first
	if (NextBookID >= MAX) return -1;

	// enforce the id rule
	newb.bookid = NextBookID;

	// add
	blist[NextBookID++] = newb;
	return NextBookID-1;
}

// save the n records in blist into filename using binary format to be used for random access 
// return the number of records saved or -1 if unsuccessful
int SaveBookList(struct book blist[], char * filename, int n);
int SaveBookList(struct book blist[], char * filename, int n)
{
	int i;
	FILE *fp;

	// save using random access:
	fp = fopen(filename, "w");

	if (fp == NULL)
	{
		return -1;
	}
	
	for (i=0; i < n; i++)
	{
		fwrite(&blist[i], sizeof(struct book), 1, fp);
	}

	fclose(fp);

	return n;

}

// retrieve the record identified by bookid into b from the filename specified (using random access method)
// returns the bookid if successful or -1 otherwise
int LoadRecord(int bookid, char *filename, struct book *b);
int LoadRecord(int bookid, char *filename, struct book *b)
{
	FILE *fp;

	// load using random access:
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		return -1;
	}
	
	fseek(fp, bookid * sizeof(struct book), SEEK_SET);
	fread(b, sizeof(struct book), 1, fp);

	fclose(fp);

	return bookid;
}



int main()
{
	struct book b1 = {"C how to program", "Deitel, Deitel", 700, 1};
	struct book b2 = b1;

	int done=0;

	// struct book BookList[MAX] = {b1, b2};
	
	struct book BookList[MAX];
/*
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
	if (AddBook(BookList, b1) > -1) printf("added new record...\n"); else printf("Failed...\n");
*/	
//	PrintBookList(BookList, MAX);


//	printf("The size of one record is: %d\n", sizeof(struct book));

//	SaveBookList(BookList, "blist.dat", MAX);


	// Load a specific record and display it based on the user's request

	do
	{
		printf("What record do you want (-1=quit)? ");
		scanf("%d", &done);
		if (done != -1)
		{
			LoadRecord(done, "blist.dat", &b1);
			PrintBook(b1);
		}
	}while(done != -1);

	return 0;
}

