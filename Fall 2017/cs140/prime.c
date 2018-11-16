#include <stdio.h>

int main (void)
{
	FILE *fp;
	
	fp = fopen ("prime.csv", "w"); 
	
	int d, count = 0;
	
	for (int n = 2 ;  ; ++n)
	{
		for (d = 2 ; d < n && (n % d != 0); d++);
		
		//printf("d: %d ",d);
		
		if (n == d) {
			fprintf(fp, "%d\n", n);
			// count++;
			//printf("%d ", count);
		}
	}
	return 0;
}

printf("%d", d);


