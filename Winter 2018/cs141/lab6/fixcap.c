/*
 * Name: fixcap.c
 * Purpose: Lab 6: Structures in C
 * Author: Ben Davidson
 *         104924033
 * CS141 Lab Section
 * Date: 0317-2018 11:18AM
 */

#include <stdio.h>
#include <ctype.h>

//Employee struct wiht typedef shortcut 
typedef struct {
    char firstname[40];
    char lastname[40];
    int id;
} Employee;

/* Prototypes */
int WordCap(char *);
void SaveEmployeeRecord(const Employee e[], FILE* FileName);


int main()
{
    FILE* empFile = fopen("employee.dat", "r+"); // open "employee.dat" in RW mode
    Employee EmployeeList[3]; // an array of 3 records, type employee

    fscanf(empFile, "%*[^\n]\n", NULL);

    for (int i = 0 ; i < 3; i++)
    {
        fscanf(empFile, "%d %s %s", &EmployeeList[i].id, EmployeeList[i].firstname, EmployeeList[i].lastname);
    }

    for (int i = 0 ; i < 3 ; i++)
    {
        WordCap(EmployeeList[i].firstname); // capitizes firstname
        WordCap(EmployeeList[i].lastname); // cipaitalizes lastname
    }

    rewind(empFile); // moves the file postion back to the beginning of the stream
    SaveEmployeeRecord(EmployeeList, empFile);

    fclose(empFile); // closes the file
    
    return 0;
}

/* WordCap: takes a string and returns a string with only the  first letter capitialized
 * INPUT: a string pointer 
 * OUTPUT: the modified string
 */
int WordCap(char *word)
{
    word[0] = toupper(word[0]); // converts the fist character to upper case.

    return 0;
}

/* Save the contents of the employee record list to the newly created text file specified by FileName 
 * INPUT: Employee struct, file name
 * OUTPUT: a saved file containing hte employee data
 */
void SaveEmployeeRecord(const Employee e[], FILE* FileName)
{
    fprintf(FileName, "ID FIRSTNAME LASTNAME\n");

    for (int i = 0 ; i < 3 ; i++)
    {
        fprintf(FileName, "%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
    }
}