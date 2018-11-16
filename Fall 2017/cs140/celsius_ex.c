/* celsius_ex.c             */
/* time: Dec 5, 4:45 - 4:50 */

#include <stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(){

	float fahrenheit, celsius;
	
	printf("\n\nEnter temperature in fahrenheit: ");
	scanf("%f", &fahrenheit);
	
	celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR; // wrote FREEZING_PT wrong
	
	printf("The temperature in fahrenheit is %.1f.\n", celsius); // missed %.1 to reduce the decimal place. 
		
	return (0);
}