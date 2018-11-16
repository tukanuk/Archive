#include <stdio.h>

void cpystr(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src++;
		//printf("%c ", *dest);
		*dest++;
	}
	*dest = '\0';

	printf("\n");
}

int main()
{
	char first[] = "Hello this is it";
	char second[25];

	cpystr(second, first);

	printf("%s\n", second);
	//char *result = cpystr(second, first);
	//printf("As a return: %s\n", result); //pystr(second, first));

	return 0;
}
