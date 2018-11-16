#include <stdio.h>

int recN(int n);
int recRN(int n);
void recRev(char i);

int main()
{
	printf("\n\n");
	
	recN(10);
	printf("\n\n");
	
	recRN(10);
	printf("\n\n");

	return 0;
}


void recRev(char i)
{
	
}

int recN(int n)
{
	printf("%d ", n);

	if (n == 0) return 1;
	else recN(n-1);

	return 0;

}


int recRN(int n)
{

	//printf("%d ", n);
	
	if (n != 0) 
	{
		recRN(n-1);
	}

	printf("%d ", n);
	
	return 0;
}
