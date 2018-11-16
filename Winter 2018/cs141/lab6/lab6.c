/*
 * Name: lab6.c
 * Purpose: Lab 6: Structures in C
 * Author: Ben Davidson
 *         104924033
 * CS141 Lab Section
 * Date: 0317-2018 11:18AM
 */

#include <stdio.h>

/* Prototypes */


struct employee
{
    char firstname[40];
    char lastname[40];
    int id;
};
typedef struct employee Employee;

/* Input the employee data interactively from the keyboard */
void InputEmployeeRecord(Employee *ptrEmp);

/* Display the contents of a given Employee record*/
void PrintEmployeeRecord(const Employee e[]);

/* Save the contents of the employee record list to the newly created text file specified by FileName */
void SaveEmployeeRecord(const Employee e[], const char *FileName);

int main()
{
    Employee e1[3]; // TODO: modify to input and save an array of 3 employee records 
    
   // Employee *ptrE1 = e1;

    InputEmployeeRecord(&e1);

    PrintEmployeeRecord(e1);

    SaveEmployeeRecord(e1, "employee.dat");

    return 0;
}

/* Input the employee data interactively from the keyboard 
 * INPUT: first name, last name and id of the employee
 * OUTPUT: creates a */
void InputEmployeeRecord(Employee *ptrEmp)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        printf("Employee #%d\n", i+1);
        printf("-------------\n");
        
        printf("First name: ");
        scanf("%s", ptrEmp[i].firstname);

        printf("Last name: ");
        scanf("%s", ptrEmp[i].lastname);

        printf("Employee number: ");
        scanf("%d", &ptrEmp[i].id);
    }
    
    printf("\n");
}


/* Display the contents of a given Employee record
 * INPUT: The employee object
 * OUTPUT: an output of the employee data 
 */
void PrintEmployeeRecord(const Employee e[])
{
    printf("ID FIRSTNAME LASTNAME\n");
    for (int i = 0 ; i < 3 ; i ++)
    {
        printf("%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
    }
}

/* Save the contents of the employee record list to the newly created text file specified by FileName 
 * INPUT: Employee struct, file name
 * OUTPUT: a saved file containing hte employee data
 */
void SaveEmployeeRecord(const Employee e[], const char *FileName)
{
    FILE* empFile = fopen(FileName, "w");

    fprintf(empFile, "ID FIRSTNAME LASTNAME\n");

    for (int i = 0 ; i < 3 ; i++)
    {
        fprintf(empFile, "%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
    }

    fclose(empFile);
}
