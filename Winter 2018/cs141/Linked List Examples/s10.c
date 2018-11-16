#include<stdio.h>
#include<string.h>

struct employee
{
	char fname[20];
	char lname[20];
	int id;
};

typedef struct employee Employee;

int main()
{
	Employee e1;

	FILE *fp;

	// load using random access:
	fp = fopen("employee.dat", "r");

	if (fp == NULL)
	{
		printf("Error: can't open file.\n");
		return -1;
	}
	
	fseek(fp, (2-1) * sizeof(Employee), SEEK_SET);
	fread(&e1, sizeof(Employee), 1, fp);

	fclose(fp);

	// check by printing the records:

	printf("e1: %s %s %d\n", e1.fname, e1.lname, e1.id);

	strcpy(e1.lname, "McDonald");

	printf("e1 (after): %s %s %d\n", e1.fname, e1.lname, e1.id);


	// SAVE

	// load using random access:
	fp = fopen("employee.dat", "a");

	if (fp == NULL)
	{
		printf("Error: can't open file.\n");
		return -1;
	}
	
	fseek(fp, (2-1) * sizeof(Employee), SEEK_SET);
	fwrite(&e1, sizeof(Employee), 1, fp);

	fclose(fp);



}
