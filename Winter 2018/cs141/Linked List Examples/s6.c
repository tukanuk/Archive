#include<stdio.h>
#include<string.h>

struct employee
{
	char fname[20];
	char lname[20];
	int id;
};

void printEList(struct employee elist[], int c);
int saveEList(struct employee elist[], int c, char *filename);
int loadEList(struct employee elist[], char *filename);
void swap(struct employee *pe1, struct employee *pe2);

int main()
{       
	struct employee elist[3] = { {"john", "doe", 1}, {"big", "bob", 2} };
	int ecount = 0;

//	printEList(elist, 2);
	swap(&elist[0], &elist[1]);
//	printEList(elist, 2);
	saveEList(elist, 2, "myfile.dat");
	


	ecount = loadEList(elist, "myfile.dat");     
	printEList(elist, ecount);

        return 0;
}


void printEList(struct employee elist[], int c)
{
	int i;

	for (i = 0; i < c; i++)
	{
		printf("%s %s %d\n", elist[i].fname, elist[i].lname, elist[i].id);
	}
	
}

void swap(struct employee *pe1, struct employee *pe2)
{
	struct employee temp;
	
	temp = *pe1;
	*pe1 = *pe2;
	*pe2 = temp;

}

int saveEList(struct employee elist[], int c, char *filename)
{
	FILE *fp;
	int i;

	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		return -1;
	}


	for (i = 0; i < c; i++)
	{
		if( i==0)
			fprintf(fp, "%s %s %d", elist[i].fname, elist[i].lname, elist[i].id);
		else
			fprintf(fp, "\n%s %s %d", elist[i].fname, elist[i].lname, elist[i].id);
	}

	fclose(fp);

	return i;
}

int loadEList(struct employee elist[], char *filename)
{
	int ecount = 0;
	FILE *fp;

	fp = fopen(filename, "r");

	if(fp == NULL)
	{
		return 0;
	}

	while(!feof(fp))
	{
		fscanf(fp, "%s%s%d", elist[ecount].fname, elist[ecount].lname, &elist[ecount].id);
		ecount ++;
	}

	fclose(fp);

	return ecount;
}
