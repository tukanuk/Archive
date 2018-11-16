/**
   Calculating the longevity of a college fund
   Solves 60-212 lab #1 activity #1
   @author Ben Davidson
   @version 1.0 2018-01-15
*/

public class Lab1Act1
{
  public static void main(String[] args)
	{
        double balance = 10000.00; // initial account balance
        double interest = 0.06;    // annual interest rate
        double monthCount = 0;     // counts the month wih available funds

        while (balance > 0)
        {
            balance += balance * (interest / 12);
            balance -= 500;
            monthCount++;
        }

        System.out.println("The account will be depleated after " + monthCount / 12 + " years.");

	}
}
