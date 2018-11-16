/**
	This class generates all prime numbers.
*/

public class PrimeGenerator
{
	private int current;

	public PrimeGenerator()
	{
		current = 1;
	}

	/** 
		Calculates the next prime number.
		@return the next prime number
	*/
	public int nextPrime()
	{
		// complete this part

		return current++;
	}

	/** 
		Check if n is a prime number
		@param n to check whether it is prime or not
		@return true if n is prime
	*/
	public static boolean isPrime(int n)
	{
		// Complete this part
		if (n == 1)
		{
			return false;
		} 
		else if (n == 2)
		{
			return true;
		}

		/* loop to check to see if the number being tested
		   can be divided by i with 0 remainder */
		for (int i = 2 ; i < n ; i++)
		{
			if (n%i == 0) 
			{
				return false;
			}
		}
		
		return true;
	}
}
