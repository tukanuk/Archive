#include <stdio.h>
#include <string.h>

int strCount(char * str, char key)
{
	int len = strlen(str);
	int count=0;

	for (int i = 0 ; i < len ; i++)
	{
		if (str[i] == key)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	char * line = "Four Word Long Line";
	char k = 'o';
	printf("number of %c: %d\nExpected: 3\n", k, strCount(line, k) );

	return 0;
}
