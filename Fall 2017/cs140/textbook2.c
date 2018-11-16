/* Name: textbook2.c */
/* Purpose: To follow along with the textbook. */
/* Author: Ben Davidson */
/* Date: 0927-2017 10:33  */

#include <stdio.h>

int main(void)  
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;  
	
	printf("Enter the first single digit: ");
	scanf("%1d,", &d);
	printf("Enter the first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
	printf("Enter the second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
	
	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 9-(((first_sum * 3 + second_sum) -1)%10);
    
    printf("Check digit: %d\n", total);
    
	return 0;
    
}
