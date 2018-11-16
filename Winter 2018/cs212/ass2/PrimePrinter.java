import java.util.Scanner;

/**
	This class prints prime numbers
*/
public class PrimePrinter
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner(System.in); // creates in object 
		System.out.print("Enter upper limit: ");
		int limit = in.nextInt(); // waits for user input

		// Complete this part
		PrimeGenerator pg = new PrimeGenerator(); // creates a prime generator object

		// loop to move through int up to the limit
		for (int i = 1 ; i < limit ; i++)
		{
			// checks if the resulst from nextPrime is prime 
			if (pg.isPrime(pg.nextPrime()))
			{
				System.out.println(i);
			}
		}
	}
}
