/**
  * A tester program for BankAccount  
  * Solves 60-212 Assignment 2 Problem 4
  * @author Ben Davidson
  * @version 1.0 2018-02-11
 */


import java.util.Scanner;

public class BankAccountTester
{
    public static void main (String[] args)
    {
        BankAccount ba = new BankAccount(); // creates bank account object

        Scanner in = new Scanner(System.in); // input object

        System.out.println("Welcome to your bank account");
        simpleMenu(); // prints a simple text menu
        System.out.print("Choice: ");
        int choice = in.nextInt(); // waits for user input
        
        while (choice != 5)
        {
            
            // switch stament to direct user input
            switch (choice)
            {       
                case 1:
                System.out.print("Enter deposit amount: ");
                ba.deposit(in.nextDouble());
                break;
                
                case 2:
                System.out.print("Enter withdrawl amount: ");
                ba.withdrawl(in.nextDouble());
                break;
                
                case 3:
                System.out.printf("Balance: $%.2f", ba.getBalance());
                break;
                
                case 4:
                System.out.println("Monthly fee: " + ba.deductMonthlyCharge());
                System.out.printf("Balance: $%.2f\n", ba.getBalance());
                break;
                
                case 5:
                break;
                
                default:
                break;
            }
            
            System.out.print("\nChoice: ");
            choice = in.nextInt();
        }    

        in.close();
    }

    /**
     * Displays a simple menu
     * @param none
     * @return simple menu output 
     */
    private static void simpleMenu()
    {
        System.out.println("1. Deposit");
        System.out.println("2. Withdrawl");
        System.out.println("3. Get Balance");
        System.out.println("4. Month End");
        System.out.println("5. Quit");



    }
}