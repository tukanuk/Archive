#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int secret_number_generator(void); //prototype
void read_guess(int secret_number); //prototype

int main (void)
{
	char command;
	int secret_number;
	
	srand(time(NULL));
	
	printf("\n*** Guess the secret number between 1 and %d ***\n", MAX_NUMBER);
	
	do 
	{
		secret_number = secret_number_generator();
	
		read_guess(secret_number);
	
		printf("Do you want to play again? (y/n): ");
		scanf(" %c", &command);
		printf("\n");
	} while (command == 'y' || command == 'Y');
	
	return 0;
}

int secret_number_generator ()
{
	printf("A new number has been chosen.\n");
	return (rand() % MAX_NUMBER + 1);
}

void read_guess(int sn)
{
	int guess = 0;
	int guessCount = 0;
	
	for(;;){	
		printf("Enter a guess: ");
		scanf("%d", &guess);		
		
		guessCount++;
	
		if (guess > sn){
			printf("You guess too high, try again\n");
		} else if (guess < sn){
			printf("You guessed too low, try again\n");
		} else {
			printf("You won in %d guesses!\n", guessCount);
			return;
		}
	}
}