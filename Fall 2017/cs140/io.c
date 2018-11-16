#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
		
	if (argc != 2){
		printf("error. one file name as an argument please\n");
		exit(EXIT_FAILURE);
	}
	
	FILE *fp;
	
	fp = fopen(argv[1], "r+");
	
	if (fp == NULL){
		printf("file %s can't be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	char ch = getc(fp);
	
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fp);		
	}
	
	time_t ts = time(NULL);
	
	fprintf(fp, "\n%sAdding some special text.\n", asctime(localtime(&ts)));

	fclose(fp);
	
	return 0;
}