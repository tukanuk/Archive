#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// maximum number of top score to be stored
#define MAX 3

// define a top score entry
struct topScore
{
	int rank;		// stores the rank of the player
	int score;		// numeric score
	char nickName[21];	// nick name of the player (up to 20 chars)
};


// type definition
typedef struct topScore TopScore;

void InputScore(TopScore ScoreList[], int MaxListSize, int *ptrActualListSize); 
void PrintScores(TopScore ScoreList[], int ActualListSize); 
int SaveScores(TopScore ScoreList[], int ActualListSize); 
int LoadScores(TopScore ScoreList[], int *ptrActualListSize); 

int main()
{

	// The list that stores the top scores
	TopScore ScoreList[MAX];

	// count of actual scores stored
	int ScoreListSize = 0;

	// go to the user and input a score, then add it to the list
	//InputScore(ScoreList, MAX, &ScoreListSize); 
	//InputScore(ScoreList, MAX, &ScoreListSize); 

	// test the load
	LoadScores(ScoreList, &ScoreListSize);

	// print the scores
	PrintScores(ScoreList, ScoreListSize);

	// save scores to file
	//SaveScores(ScoreList, ScoreListSize);	

	return 0;
}


void InputScore(TopScore ScoreList[], int MaxListSize, int *ptrActualListSize)
{

	if (*ptrActualListSize >= MaxListSize)
		return;

	printf("Please enter rank, score, nickname: ");
	scanf("%d%d%s", &ScoreList[*ptrActualListSize].rank,  
			&ScoreList[*ptrActualListSize].score,  
			ScoreList[*ptrActualListSize].nickName);  

	(*ptrActualListSize)++;
}

 
/* Print the scores one record per line
I: the list with the actual number of scores stored
o: display one record per line
*/
void PrintScores(TopScore ScoreList[], int ActualListSize)
{
	int i;	// index

	printf("Rank\tScore\tName\n");

	for (i = 0; i < ActualListSize; i++)
	{
		printf("%d\t%d\t%s\n", 	ScoreList[i].rank,
					ScoreList[i].score,
					ScoreList[i].nickName);

	}

}

/* Save the ScoreList to a file
I: The scorelist and its size
O: creates a file with the score list called scores.dat, return the number of records saved
*/

int SaveScores(TopScore ScoreList[], int ActualListSize)
{

	FILE *outFile;		// file handle
	int i;			// index

	// open the file
	outFile = fopen("scores.dat", "w");

	if (outFile == NULL)
		return 0;

	// start saving
	for (i = 0; i < ActualListSize; i++)
	{
		
		if (i == 0)
		{	
			fprintf(outFile, "%d\t%d\t%s", 	ScoreList[i].rank,
							ScoreList[i].score,
							ScoreList[i].nickName);
		}
		else
		{
			fprintf(outFile, "\n%d\t%d\t%s", 	ScoreList[i].rank,
								ScoreList[i].score,
								ScoreList[i].nickName);
		}
	}

	return i;
}

int LoadScores(TopScore ScoreList[], int *ptrActualListSize)
{
	FILE *inFile;		// file handle
	int i;			// index

	// open the file
	inFile = fopen("scores.dat", "r");

	if (inFile == NULL)
		return 0;

	// start loading

	i = 0;
	while (!feof(inFile))
	{	
		fscanf(inFile, "%d%d%s", &ScoreList[i].rank,
					&ScoreList[i].score,
					ScoreList[i].nickName);
		i++;
	}

	i--;
	*ptrActualListSize = i;

	printf("Total Records read: %d\n", i);
	
	return i;


}

