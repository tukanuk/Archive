/**
  * A tester program for CreditCardValidator  
  * Solves 60-212 Assignment 2 Problem 3
  * @author Ben Davidson
  * @version 1.0 2018-02-10
 */

import java.util.Scanner;

public class CreditCardValidatorTester
{
	public static void main (String[] args)
	{
		final boolean DEBUG = false;

		Scanner input = new Scanner(System.in); //create a new scanner for input
		String ccInput = "";

		// Input a credit card number. If debug is on text prompt is removed.
		if (DEBUG != true) System.out.println("\nEnter credit card number to validate. (0 to quit): ");
		ccInput = input.nextLine();
		

		// Loops prompt while waitin for a 0 to quit
		while (ccInput.equalsIgnoreCase("0") == false)
		{
			// creates a credit card validating object called ccNum
			CreditCardValidator ccNum = new CreditCardValidator(ccInput);
			
			// run the validitor method. Return true if the number is valid.
			boolean pass = ccNum.ccValidator();
			
			// outputs the result
			if (pass)
			{
				System.out.printf("%s is in the corrrect credit card number format.\n", ccNum.getCC());
			} else
			{
				System.out.printf("%s is NOT in the corrrect credit card number format.\n", ccNum.getCC());
			}
		
			// Test credit card number parsing. Only active if debig is on.
			if (DEBUG)
			{
				System.out.println("Original input: "+ ccInput);
				System.out.println("cc like?: " + ccNum.ccParser(ccInput));
				System.out.println("passed validator?: " + pass);
				System.out.println("Time to quit? " + ccInput.equalsIgnoreCase("0"));
				System.out.println("");
			}

			if (DEBUG != true) System.out.print("\nEnter credit card number to validate. (0 to quit): ");
			ccInput = input.nextLine();	

		} 

		input.close();
	}
}
