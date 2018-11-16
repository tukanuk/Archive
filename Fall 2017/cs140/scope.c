/* Name: 	file.c	 				*/
/* Purpose: what it does		 	*/
/* Author: 	Ben Davidson 			*/
/* Date:   	date		        	*/

#include <stdio.h>

int b = 1, c = 2;

void f(void){
	int b=17, d;
	printf("\nf(): b: %d, c: %d, d: %d\n\n", b, c, d);
}

void g(int a){
	int c;
	{
		int a, d;
		printf("\nblock: b: %d, c: %d, d: %d, a: %d\n\n", b, c, d, a);
	}
	printf("\ng(): b: %d, c: %d, a: %d\n\n", b, c, a);
}
int main(void)  
{
    int c=4, d=6;

	printf("\nmain: b: %d, c: %d, d: %d, \n\n", b, c, d);

	f();
	g(1);

}
