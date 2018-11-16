#include <stdio.h>

int main (void)
{
	int cmd;
	float balance = 0.0f, credit, debit;
	
	for (;;)
	{
		printf("\nWhat would you like to do?\n");
		printf("1) Credit 2) Debit 3) exit: ");
		scanf("%d", &cmd);
	
		switch (cmd)
		{
			case 1: printf("Enter credit: ");
					scanf("%f", &credit);
					balance += credit;
					printf("New balance: %.2f\n", balance);
					break;
		
			case 2: printf("Enter debit: ");
					scanf("%f", &debit);
					balance -= debit;
					printf("New balance: %.2f\n", balance);
					break;
		
			case 3: printf("\nYour final balance is %.2f\n", balance);
					return 0;
		}
	}	
	
}