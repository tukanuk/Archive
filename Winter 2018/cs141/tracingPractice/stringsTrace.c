#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
  /* Strings */
  char *W1[] = {"tracing", "is", "easy"};
  char *W2[] = {"you", "just", "have", "to", "draw", "it!"};

  char sentence[100];
  strcpy(sentence, W2[1]);
  sentence[strlen(W2[1])] = ' ';
  sentence[strlen(W1[2]) + 1] = '\0';
  strcat(sentence, W2[strlen(W2[1])]);
  strcat(strcat(sentence, " "), W2[5]);
  sentence[0] = toupper(sentence[0]);
  printf("%s", sentence);
}

