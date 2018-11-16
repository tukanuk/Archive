#include <stdio.h>
int main()
{
	int a = 7; // declare and initialize a in with the value 7
	int *aPtr; // aPtr is a pointer to the type int
	aPtr = &a; // aPtr is a pointer to int a
	printf("%p\n", &a);     // %p prints the memory location as a hexadecimal integer
 			        // &a reads the memory ocation of a
	printf("%p\n", aPtr);   // prints the location in memory that aPtr is pointing to
	printf("%p\n", &aPtr);  // prints the location in memory that aPtr is stored in
	printf("%p\n", a);      //  print sthe value of a in hexadecimal
	printf("%d\n", *aPtr);  // prints the value stored in the memory location aPtr 
			        // points to. 
	printf("%p\n", *&aPtr); // * and & are complements. 
				// Prints value of the memory location that aPtr points to
	printf("%p\n", &*aPtr); // "". Same as above.
	printf("%d\n", *&a);    // prints value (*) of the memory location &a.
				// (prints the momory location)
			        // * and & are right to left associative
	// printf("%d\n", &*a);   // attmepts to print the memory address that a points to.
							  // a is not a pointer so there is an error
	return 0;
}

