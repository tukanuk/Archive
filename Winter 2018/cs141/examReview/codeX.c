#include <stdio.h>
#include <stdlib.h>

char * codeX(char *str, int start, int end)
{
	if (end < start || end > sizeof(*str))
	{
		printf("sizeof str: %lu\n", sizeof(*str));
		printf("sizeof str: %lu\n", sizeof(end-start));
		int *test;
		printf("sizeof str all pointers: %lu\n", sizeof(test));

		return str;

	}


	char * output = (char*)malloc(sizeof(end-start));

	for (int i = 0 ; i < sizeof(output); i++)
	{
		*(output+i) = *(str + (start+i));
	}
	return output;
}

int main()
{
	char text[] = "This_is_the_CS_141_Final_Exam_adsfjkldklsfjadklsfjadklsf adsklfjads fl;ads fadklsf adkls;fj adklsfadkls;fj adsklf adsklf adklsfj adklsfjaklsf adklsf adkls;f adkls adklsf adklsf adkls;fadklsfjadkls;f as adskl;fj asdkl;f adkls; adklsf dls sadfadsf adsfjadsklfadklsfaklsfjaklsf ksdffjioewrieowireopwir asklvmX>fmXZ>m,c.mvadslgepwopfdfklsghadsjkdglqwdhadlsgk;itopewujksfvhaldsgjkadsklfjadskl";
	char * ptr;

	ptr = codeX(text, 0, 9);
	printf("codeX = %s\n", ptr);
}

