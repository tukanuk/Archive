#include<string.h>
#include<stdio.h>
#include<ctype.h>

int ParseString(char *S, char WL[][51]);
void PrintWL(char WL[][51], int wc);

int main()
{
	char S[80];

	char WL[100][51];
	int wc;

	gets(S);
	wc = ParseString(S, WL);

	PrintWL(WL, wc);

	printf("\n%s\n", S);

	return 0;
}

/* parse words from a string into a 2D array
   I: a sentence, and an array to store the words
   O: stores the words in the WL, and returns the number of words stored
*/
int ParseString(char *S, char WL[][51])
{
	int wc = 0;
	char *strToken;
	char InputBuffer[80];
	strcpy(InputBuffer, S);

	if (strlen(S) == 0)
	{
		return 0;
	}
	

	strToken = strtok(S, " ,.:;'-+=*^%$!");

	while(strToken != NULL)
	{
		strcpy(&WL[wc][0], strToken);
		wc++;
		strToken = strtok(NULL, " ,.:;'-+=*^%$!");
	}


	strcpy(S, InputBuffer);

	return wc;
}

void PrintWL(char WL[][51], int wc)
{
	
	int i;

	for (i=0; i < wc; i++)
	{
		printf("%s\n", &WL[i][0]);
	}
}
