/*
 * Name: twitter.c
 * Purpose: Assigment 3: Simple Tweet
 * Author: Ben Davidson
 *         104924033
 * CS141 
 * Date: 0317-2018 16:11 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TWEETS 200
#define DEBUG 0

/*** Global colours ***/
const char *PINK = "\033[38;5;197;4m";
const char *NORM = "\033[0m";

// the Tweet struct
typedef struct
{

    int id;              // unique id for tweet
    char created_at[51]; // UTC time and date
    char text[141];      // the body of the tweet
    char user[21];       // the user name

} Tweet;

/* Prototype */
int tweet(char *username, int *ID, Tweet *ptrTimeline);
int searchTweets(Tweet *ptrTimeline, int *ID);
int displayTweets(Tweet *ptrTimeline, int *ID);
int saveTweets(Tweet *ptrTimeline, int *ID);
int loadTweets(Tweet *ptrTimeline, int *ID);

int basicMenu(char *name, int *ID, Tweet *ptrTimeline);
int getTime(char *ts);
int displayTweet(Tweet *ptrTweet, int tempID);
int nStrip(char *strStrip);

int main()
{
    system("clear");                // clears the terminal window

    Tweet timeline[MAX_TWEETS];   // creates an array of tweet structs 

    char username[21];             // the username of the user
    char buffer[80];               // in buffer to hold input 
    
    int tweetID = 1;               // sets base tweet ID
    int *ptrTweetID = &tweetID;   // ptr for tweet ID

    printf("  Welcome to Simple Twitter\n");
    printf("  Please enter your user name: ");

    fgets(buffer, sizeof buffer, stdin);    // captures line of input for username

    if (strlen(buffer) > 20)                // checks for length, ask for name again if too long
    {
        printf("  Your username was %lu characters long.\n", strlen(buffer) );
        printf("  20 characters max please: ");
        fgets(buffer, sizeof buffer, stdin);

    }

    // searches for spaces in user name and replaces them with underscores (for a typical user name format)
    char *search = buffer; 
    while ( (search = strchr(search, ' ') ) != NULL )
    {
        *search = '_';
        ++search;
    }
    
    sscanf(buffer, "%20s", username); // takes 

    // interactive menu in loop
    int exitCheck = 0;                // var for exit program  
    do
    {
        exitCheck = basicMenu(username, ptrTweetID, timeline);
    } while (exitCheck != -1);

    printf("  \033[38;5;197mHappy trails!%s\n", NORM);

    return 0;
}

/*
 *	tweet: to write a tweet with metadata
 *		INPUT: username and the the Tweet timeline
 *		OUTPUT: a tweet in the timeline array with an id, date/time, and user id
*/
int tweet(char *username, int *ptrID, Tweet *ptrTimeline)
{
    char buff[285];                    // buffer to hold input
    char tweet[141];                  // temp storage for tweet text
    char timeStamp[51];              // temp store for date/time
    char *ptrTimeStamp = timeStamp; // ptr ti timestamp
    

    printf("  What's happening? ");
    fgets(buff, sizeof buff, stdin); // tweet text

    // checks for tweet text length
    while (strlen(buff) > 140)
    {
        printf("  %lu characters too long.\n  140 characters max. Try again: ", strlen(buff) - 140 );
        fgets(buff, sizeof buff, stdin);
    }

    // copies buff to temp tweet text
    strncpy(tweet, buff, 140);

    // creates time stamp
    getTime(ptrTimeStamp);

    // removes '\n' from string
    nStrip(tweet);

    int tempID = *ptrID - 1;  // adjustment to position tweets properly in array

    // copy tweet data into struc
    ptrTimeline[tempID].id = (*ptrID)++;                // stores id in struc, increments ID
    strcpy(ptrTimeline[tempID].created_at, timeStamp);
    strcpy(ptrTimeline[tempID].text, tweet);
    strcpy(ptrTimeline[tempID].user, username);
    
    // displays the tweet as entered
    displayTweet(ptrTimeline, tempID); 

    return 0;
}

/*
 *	displayTweet: displays a single tweet
 *		INPUT: ptr to the Tweet array, the current ID
 *		OUTPUT: dispalys the tweek to stdout and returns 0 on success.
*/
int displayTweet(Tweet *ptrTweet, int tempID)
{

    // temp file for a formatted tweet display. idea from fgets man page
    FILE* tmpF = tmpfile();                 // <stdio.h> function that creates a temp file, opens and deletes it
    fputs(ptrTweet[tempID].text, tmpF);    // puts the text of the tweet in the temp file
    rewind(tmpF);                           // move to beginning of stream (tmpF)
    char buff[37];                          // set the width for tweet text output
    

    // formatting for display
    printf("\n\n");
    printf("  \u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
    printf("  \u2503  \033[38;5;197;4m@%-36s\033[0m  \u2503\n", ptrTweet[tempID].user);

    // works thorugh tmp file, printing 37 characters at a time with formatting
    while (fgets(buff, sizeof buff, tmpF) != NULL)
    {
        printf("  \u2503  %-37s  \u2503\n", buff);
    }
    
    // user id and timestamp
    printf("  \u2503  \033[38;5;213m#%-3d %32s  \033[0m\u2503\n", ptrTweet[tempID].id, ptrTweet[tempID].created_at);
    printf("  \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");

    return 0;
}

/*
 *	getTime: gets the current time in UTC
 *		INPUT: ptr to the current timestamp
 *		OUTPUT: a formamted timestamp in UTC time
*/
int getTime(char *ptrTs)
{
    char buff[150];         // input buffer
    time_t currTime;       // for the unformatted current time
    struct tm *utc_time;   // for the formatted UTC time

    currTime = time(NULL); // gets the current time (time since Epoch in seconds)

    utc_time = gmtime(&currTime); // converts Epoch time to UTC time

    strftime(ptrTs, 51, "%c UTC", utc_time); // writes formatted UTC time to ptrTs 

    return 0;
}

/*
 *	searchTweets: to search the text of all the tweets for user inputted text
 *		INPUT: Tweet timeliens, current ID (last tweet)
 *		OUTPUT: a list of tweets containing matches (if any) and a summary of the number of matches
*/
int searchTweets(Tweet *ptrTimeline, int *ID)
{
    int counter = 0;                    // counts the matches
    char buff[255];                     // input buffer
    printf("\n  Enter search text: ");
    fgets(buff, sizeof buff, stdin);    // captures the line of search text
    nStrip(buff);                       // removes the '\n'

    // searches all tweet text sequentially, displays the tweet and increments a counter for each match
    for ( int i = 0 ; i < *ID - 1 ; i++)
    {
        if ( strstr(ptrTimeline[i].text, buff) != NULL)
        {
            displayTweet(ptrTimeline, i);
            counter++;
        }
    }

    // search summary
    printf("\n  %s%s%s was found %d time(s).\n", PINK, buff, NORM, counter);

    return 0;
}

/*
 *	displayTweets: displays a formatted list of all the tweets
 *		INPUT: Tweet timeline and last tweet ID
 *		OUTPUT: a formatted list of tweets
*/
int displayTweets(Tweet *ptrTimeline, int *ID)
{
    printf("\n  Displaying \033[38;5;197m%d\033[0m tweets: ", *ID - 1);
    
    // users displayTweet to sequentially display all tweets
    for (int i = 0 ; i < *ID - 1 ; i++)
    {
        displayTweet(ptrTimeline, i);
    }

    return 0;
}

/*
 *	saveTweets: to save all tweets to an output file
 *		INPUT: Tweet timeline, last tweet ID, user input for filename
 *		OUTPUT: a file containing all tweet data. if file cannot be craeted exit function
*/
int saveTweets(Tweet *ptrTimeline, int *ID)
{
    char filename[255];                         // stores filename
    printf("\n  Filename: ");
    fgets(filename, sizeof filename, stdin);

    // removes '\n' from string
    nStrip(filename);
    
    // Opens the file and checks for success
    FILE* tweetFile = fopen(filename, "w");
    if(!tweetFile) 
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    // uses fprintf to print one item of struct data on each line, moving through entire struct
    for (int i = 0 ; i < *ID - 1 ; i++)
    {
        fprintf(tweetFile, "%d\n", ptrTimeline[i].id);
        fprintf(tweetFile, "%s\n", ptrTimeline[i].created_at);
        fprintf(tweetFile, "%s\n", ptrTimeline[i].user);
        fprintf(tweetFile, "%s\n", ptrTimeline[i].text);
    }

    // summary line
    printf("  %d tweet(s) saved in the file \"%s\"", *ID - 1, filename);
    
    // always close your file!
    fclose(tweetFile);

    return 0;
}

/*
 *	loadTweets: loads tweets from a text file
 *		INPUT: Tweet timeline, last tweet ID, user input filename   
 *		OUTPUT:  a list of tweets that were loaded, error messag if file not found  
*/
int loadTweets(Tweet *ptrTimeline, int *ID)
{
    char filename[255];                         // filename
    printf("\n  Filename: ");
    fgets(filename, sizeof filename, stdin);   // captures the line containing the filename

    // removes '\n' from string
    nStrip(filename);
    
    
    // opens the file and checks for errors
    FILE* tweetFile = fopen(filename, "r");
    if(!tweetFile) 
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    // Temp variables for loading data
    int tmpID = 0; // starts a new temp ID
    char buff[200]; // buffer to hold each line of the file as a string

    // goes through the file one line at a time until NULL
    while (fgets(buff, sizeof buff, tweetFile)!= NULL)
    {
        nStrip(buff);
        ptrTimeline[tmpID].id = atoi(buff); // converts the first line to an int and stores as id
        if (DEBUG) printf("%s\n", buff);

        fgets(buff, sizeof buff, tweetFile);
        nStrip(buff);
        strncpy(ptrTimeline[tmpID].created_at, buff, 51); // copies second line to created_at (only the first 51 char)
        if (DEBUG) printf("%s\n", buff);

        fgets(buff, sizeof buff, tweetFile);
        nStrip(buff);
        strncpy(ptrTimeline[tmpID].user, buff, 21); // copies third line to user (only the first 21 char)
        if (DEBUG) printf("%s\n", buff);

        fgets(buff, sizeof buff, tweetFile);
        nStrip(buff);
        strncpy(ptrTimeline[tmpID].text, buff, 141); // copies fourth line to text (only the first 141 char)
        if (DEBUG) printf("%s\n", buff);

        displayTweet(ptrTimeline, tmpID); // displays the tweet as it is loaded
        
        tmpID++; // increments the max ID
    }

    
    *ID = tmpID; // sets the main ID to match the number of loaded tweets
    
    // sumnmary line
    printf("   %s%d%s tweet(s) were sucessfully loaded!", PINK, tmpID, NORM);

    (*ID)++; // increments the ID one more time 

    fclose(tweetFile); // close the file

    return 0;
}

/* basicMenu: A basic menu to select a function 
   INPUT: Tweet timeline, user name, tweet ID
   OUTPUT: returns 0 to keep the program going, returns -1 to exit the program
*/
int basicMenu(char *name, int *ID, Tweet *ptrTimeline)
{
    //system("clear");

    int choice = 0; // choose a function
    int c; // used with getchar to consume \n

    printf("\n\n");
    printf("  \u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
    printf("  \u2503             Hey \033[38;5;197m%-21s%s   \u2503 \n", name, NORM);
    printf("  \u2503             Welcome to                  \u2503 \n");
    printf("  \u2503             Simple Twitter              \u2503 \n");
    printf("  \u2503                                         \u2503 \n");
    printf("  \u2503 \u2460 Tweet              \u2461 Search           \u2503 \n");
    printf("  \u2503 \u2462 Display tweets     \u2463 Save tweets      \u2503 \n");
    printf("  \u2503 \u2464 Load tweets        \u2465 Quit             \u2503 \n");
    printf("  \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");

    printf("                  >> ");

    scanf("%d", &choice); //first menu choice
    while ( (c = getchar()) != '\n' && c != EOF); // consumes the '\n'    

    switch (choice)
    {
    case 1:
        tweet(name, ID, ptrTimeline);
        break;
    case 2:
        searchTweets(ptrTimeline, ID);
        break;
    case 3:
        displayTweets(ptrTimeline, ID);
        break;
    case 4:
        saveTweets(ptrTimeline, ID);
        break;
    case 5:
        loadTweets(ptrTimeline, ID);
        break;
    case 6:
        // exit the program
        return -1;
        break;
    default:
        break;
    }

    return 0;
}

/*
 *	nStrip: removes '\n' from string
 *		INPUT:  ptr to the string that needs stripping
 *		OUTPUT:  removes '\n' if found and replaces it with '\0'
*/
int nStrip(char *strStrip)
{
    char *c; 
    if ( (c = strchr(strStrip, '\n')) != NULL)
    {
        *c = '\0';
    }

    return 0;
}