/**
   Calculating the balance of an account
   Uses three variables (balance, interest and years) to calculate interest.
   Solves 60-212 Ass #1 problem #1
   @author Ben Davidson
   @version 1.0 2018-01-12
*/


public class Problem1
{
    public static void main(String[] args)
	{
        double balance = 1000.00; // initial account balance
        double interest = 0.05;    // annual interest rate
        int years = 0; // year counter

        /**
         loop to calculate the interest for three years
         and output a result at the end of each year
        */
        for (years = 1; years <= 3 ; years++)
        {
            balance += balance * interest;

            System.out.printf("After %d year(s), the balance will be: $%.2f\n", years, balance);
        }
	}
}
