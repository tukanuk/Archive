/**
  * A tester program for CashierTester
  * Solves 60-212 Assignment 2 Problem 5
  * @author Ben Davidson
  * @version 1.0 2018-02-11
 */

import java.util.Scanner;

public class CashierTester
{
    public static void main (String[] args)
    {
        Cashier cashy = new Cashier(); // creates a cashier object
        Scanner input = new Scanner(System.in); // creates a scanner object
        String again = "y"; 

        while (again.contentEquals("y"))
        {
            System.out.println("Change Calculator");
            
            // Gets bill total
            System.out.print("Amount due (in pennies): ");
            int due = input.nextInt();
            
            // Gets customer payment
            System.out.print("Amount received (in pennies): ");
            int received = input.nextInt();

            // calcualtes change and prints change if the transaction was valid
            boolean valid = cashy.calculateChange(due, received);
            if (valid)
            {
                cashy.printChange();
            }

            System.out.print("Again? (y/n): ");
            again = input.next();
            // again = input.nextLine();
        }
        
        input.close();
    }
}