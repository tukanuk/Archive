/**
  * Implementing a credit card validator
  * Solves 60-212 Assignment 2 Problem 3
  * @author Ben Davidson
  * @version 1.0 2018-02-10
 */

 public class CreditCardValidator
 {
	// private instance variables
	private String  creditCard = ""; // store the cc number String
	private final boolean DEBUG = false; // toggles debug output in code

	// constructors
	public CreditCardValidator(String ccNum)
	{
		creditCard = ccNum;
	}


	// methods

	/**
	 * getCC gets the credit card number being checked
	 * @return the credit card number
	 */
	public String getCC()
	{
		return creditCard;
	}

	/**
	 * ccParser Parses the input to remove spaces and "-" and perform
	 * 			length check to form a credit card-like string.
	 * @param toParse the string to convert to a credit card like format
	 * @return sets creditCard and returns true if it is credit card like.
	 */
	public boolean ccParser(String toParse)
	{
		// Remove space and - from the credit card numbers
		toParse = toParse.replaceAll("\\s", "");
		toParse = toParse.replaceAll("-", "");

		// Check for proper length of credit card number
		if (toParse.length() != 16)
		{
			return false;
		}

		creditCard = toParse;

		if (DEBUG) System.out.println("Parse check: ***" + creditCard + "***");

		return true;
	}

	/**
	 * ccValidator Checks if the input had the proper format for a credit card.
	 * @param 
	 * @return ture if the format is proper
	 */
	public boolean ccValidator()
	{
		// local variables
		int ccSum = 0; // sum of the digits
		long ccNumLong = 0;

		if (ccParser(creditCard) != true)
		{
			if (DEBUG) System.out.println("Failed ccParser.");
			return false;
		}
		
		/* test if the string is all integers returns false if not 
		   int-like. .parseLong methods throw expection if it cannot
		   parse. 'Try..catch' handles the exception. */
		try 
		{
			ccNumLong = Long.parseLong(creditCard);
		} 
		catch (NumberFormatException e)
		{
			if (DEBUG) System.out.println("Failed conversion to long.");
			return false;
		}

		// sums the digits of the int-like string
		ccSum = digitSums();
		if (DEBUG) System.out.println("digit sum: " + ccSum);

		// add every second digit to ccSum
		ccSum += secondAdder();

		if (DEBUG) System.out.println("2nd sum: " + ccSum);

		// check if divisible by ten
		if (ccSum % 10 == 0)
		{
			return true;
		} else
		{		
			return false;
		}
	}

	/**
	 * digitSums sums the digits of the int-like string
	 * @return ccSum the sum of the digits
	 */
	private int digitSums ()
	{
		int sum = 0;
		
		// sums the digits of the int-like string
		for (int i = 0 ; i < creditCard.length() ; i++)
		{
			sum += Integer.parseInt(creditCard.substring(i, i+1));
		}

		return sum;
	}

	/**
	 * secondAdder adds every second digit to ccSum
	 * @param sum the digit to be added to
	 * @return the result of the calculation
	 */
	private int secondAdder()
	{
		int sum = 0; // the sum of step two 
		int counter = 0; // the number of digits greater then four

		for (int i = 0 ; i < creditCard.length() ; i += 2)
		{
			//create an int from a single digit substring
			int oneDigit = Integer.parseInt(creditCard.substring(i, i+1));

			sum += oneDigit;

			if (oneDigit > 4)
			{
				counter++;
			}

		}
		// adds the number of digits great then four to the total
		sum += counter;

		return sum;
	}
		
}
