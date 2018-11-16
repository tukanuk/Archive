#include <stdio.h>
#include <string.h>

#define LEN 80
/** prototypes **/
void ParseSentence (char *s);
void AlphabetizeArray(char *[100], int c);

int main (void)
{
    char sentence[LEN]; // for the input
    printf("Sentence please: ");
    scanf("%79[^\n]s", sentence); //printf("Parsing the string %s.\n", sentence);
    ParseSentence(sentence);

    return 0;
}
/**
 * ParseSentence tokenizes and alphabetizes the string
 * INPUT: a string
 * OUTPUT: the alphabetized contents of the string
 */
void ParseSentence (char *s)
{
    // I need to make a pointer array

    int counter = 0;

    char *words[100]; // can sort a sentance up to 100 words

    words[counter] = strtok(s, " ,;.");

    while (words[counter])
    {
        //printf("parse: %s\n", words[counter]);
        counter++;
        words[counter] = strtok(NULL, " ,;.");

    }

    char *temp;

    // Alphabetize the strings

    // control loop
    for (int i = 0 ; i < counter ; i++)
    {
        for (int j = 0 ; j < counter - 1 ; j++ )
        {
            if ( strcmp( words[j], words[j + 1] ) > 0 )
            {
                //swap
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    for (int i = 0 ; i < counter ; i++)
    {
        printf("%s\n", words[i]);
    }
}