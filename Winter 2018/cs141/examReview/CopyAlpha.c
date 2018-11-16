#include <stdio.h>
#include <ctype.h>

void CopyAlpha (char *dest, char *src);

int main()
{
	char first[] = "These are 12345 numbers";
	char second[50];
	CopyAlpha(second, first);
	printf("%s\n", second);

	return 0;
}

/** 
 * CopyAlpha: copies only the letters
 * INPUT: destination cahr array string and source char array stirng
 * OUTPUT: return altered dest char array
 */
void CopyAlpha (char *dest, char *src)
{
	while (*src){
	if (isalpha(*src) )
	{
		*dest++ = *src++;
	}
	else
	{
		//*dest++;
		*src++;
	}
	}
}


