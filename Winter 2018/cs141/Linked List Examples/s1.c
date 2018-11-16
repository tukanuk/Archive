#include <stdio.h>
#include <string.h>

struct point
{
	int x;
	int y;
	char label[10];
};


int main()
{

	struct point p1, p2;

	p1.x=1;
	p1.y=2;
	strcpy(p1.label, "p1");

	p2.x=3;
	p2.y=4;
	strcpy(p2.label, "p2");


	printf("before:\n");
	printf("%d %d %s\n", p1.x, p1.y, p1.label);
	printf("%d %d %s\n", p2.x, p2.y, p2.label);

	p1 = p2;

	p2.x = 5;

	printf("\nafter:\n");
	printf("%d %d %s\n", p1.x, p1.y, p1.label);
	printf("%d %d %s\n", p2.x, p2.y, p2.label);


	return 0;
}
