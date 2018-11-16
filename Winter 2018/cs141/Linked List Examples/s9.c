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
	Employee e2;

	FILE *fp;

	// load using random access:
	fp = fopen("employee.dat", "r");

	if (fp == NULL)
	{
		printf("Error: can't open file.\n");
		return -1;
	}
	
	fread(&e1, sizeof(Employee), 1, fp);
	fread(&e2, sizeof(Employee), 1, fp);

	fclose(fp);

	// check by printing the records:

	printf("e1: %s %s %d\n", e1.fname, e1.lname, e1.id);
	printf("e2: %s %s %d\n", e2.fname, e2.lname, e2.id);

}
