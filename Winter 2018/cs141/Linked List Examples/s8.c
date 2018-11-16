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
	Employee e1 = { "john", "doe", 10};
	Employee e2 = { "bob", "smith", 20};

	FILE *fp;

	printf("%d", sizeof(Employee));

	// save using random access:
	fp = fopen("employee.dat", "w");

	if (fp == NULL)
	{
		printf("Error: can't open file.\n");
		return -1;
	}
	
	fwrite(&e1, sizeof(Employee), 1, fp);
	fwrite(&e2, sizeof(Employee), 1, fp);

	fclose(fp);

}
