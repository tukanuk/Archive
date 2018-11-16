#include <string.h>
#include <ctype.h>
#include <stdio.h>


struct student
{
	char fn[10];
	char ln[10];

	int id;

};

void PrintRecord(struct student s);
void FormatRecord(struct student *ptrs);


void PrintRecord(struct student s)
{
	printf("%s %s %d\n", s.fn, s.ln, s.id);
}

void FormatRecord(struct student *ptrs)
{
	ptrs->fn[0] = toupper(ptrs->fn[0]);
	ptrs->ln[0] = toupper(ptrs->ln[0]);
}


int main()
{

	struct student s1 = {"john", "doe", 5};
 
	PrintRecord(s1);
	FormatRecord(&s1);
	PrintRecord(s1);


	return 0;
}
