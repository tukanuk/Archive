/* letter_grade_ex.c 		*/
/* date: Dec 6, 5:22 - 5:51 */

#include <stdio.h>

int main () {

	int aGrade = 0, bGrade = 0, cGrade = 0, dGrade = 0, fGrade = 0;

	puts("\nEnter a letter grade: ");
	puts("Enter the z Character to end input");
	
	int grade = 0;
	
	while ((grade = getchar()) != EOF){
	
		switch (grade) {	
			case 'a':
			case 'A': ++aGrade;
						break;
				
			case 'b':
			case 'B': bGrade++;
						break;
				
			case 'c':
			case 'C': cGrade++;
						break;
				
			case 'd':
			case 'D': dGrade++;
						break;
				
			case 'f':
			case 'F': fGrade++;
						break;
						
			case '\t':
			case '\n':
			case ' ': break;
	
			default:    puts("Invalid grade! Try again");
						break;
		}
	
	}
	
	puts("\nTotals:");
	printf("A: %d\n", aGrade);
	printf("B: %d\n", bGrade);
	printf("C: %d\n", cGrade);
	printf("D: %d\n", dGrade);
	printf("F: %d\n", fGrade);
	
	return 0;
	
}   
	
}