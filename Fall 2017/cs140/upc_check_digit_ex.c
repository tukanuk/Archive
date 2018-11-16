/* upc_check_digit_ex.c		*/
/* time: Dec 5 4:53 - 5:08  */
/* no erros on compile!		*/

#include <stdio.h>

int main() {

	int s, f1, f2, f3, f4, f5, s1, s2, s3, s4, s5, c, check_digit;
	
	printf ("\nEnter the first (single) digit: ");
	scanf ("%d", &s);
	
	printf("Enter the frist group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &f1, &f2, &f3, &f4, &f5); 
	
	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &s1, &s2, &s3, &s4, &s5);
	
	printf("Enter the check digit: ");
	scanf("%1d", &c);
	
	check_digit = 9 - ((s + f2 + f4 + s1 + s3 + s5)* 3 + (f1 + f3 + f5 + s2 + s4) - 1) % 10;
	
	printf("You entered %d and the check digit calculated as %d\n", c, check_digit);
	
	return 0;
}
