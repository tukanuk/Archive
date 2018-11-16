#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	FILE *fp;
	
	fp = fopen("test.txt", "r");
	
	char ch = getc(fp);
	
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fp);
	}
	
	fclose(fp);
	
	return 0;	
}