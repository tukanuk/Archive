#include <stdio.h>
#include <string.h>

#define MAX 10

// structure definition
struct student
{
	char fname[20];
	char lname[20];
	int id;
};

typedef struct student Student;

int SaveList(Student SList[], char *filename, int scount);
int LoadList(Student SList[], char *filename);

int main()
{
	Student SList[MAX]; 
	//  = { {"jim", "smith", 10}, {"bob", "big", 20} };
	int scount = 0;

	// SaveList(SList, "student.txt", scount);
	scount = LoadList(SList, "student.txt");
	

	return 0;
}

int SaveList(Student SList[], char *filename, int scount)
{
	FILE *fp;
	int i;

	fp = fopen (filename, "w");

	if (fp == NULL)
	{	
		return -1;
	}

	for (i=0; i < scount; i++)
	{
		if (i==0)
			fprintf(fp, "%s %s %d", SList[i].fname, SList[i].lname, SList[i].id);
		else
			fprintf(fp, "\n%s %s %d", SList[i].fname, SList[i].lname, SList[i].id);
	}
	
	fclose(fp);

	return i;
}


int LoadList(Student SList[], char *filename)
{
	FILE *fp;
	int i=0;

	fp = fopen (filename, "r");

	if (fp == NULL)
	{	
		return 0;
	}

	while(!feof(fp))
	{
		fscanf(fp, "%s%s%d", SList[i].fname, SList[i].lname, &SList[i].id);
		printf("\n%s %s %d", SList[i].fname, SList[i].lname, SList[i].id);
		
		i++;
	}
	
	fclose(fp);

	return i;
}

