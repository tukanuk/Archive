#include <stdio.h>

void cpystr(char * dest, char * src)
{
	while (*src)
	{
		*dest++ = *src++;
	{
{

int main()
{
	char * first = "Hello this is it";
	char * second;

	cpystr(second, first);

	printf("%s", second);

	return 0;
}
