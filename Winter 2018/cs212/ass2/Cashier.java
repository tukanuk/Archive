/**
  * Directs a cashier on what change should be provided
  * Solves 60-212 Assignment 2 Problem 5
  * @author Ben Davidson
  * @version 1.0 2018-02-11
 */

public class Cashier
{
    // private instance variables
    private static final int PENNIES = 1;
    private static final int NICKLE = 5;
    private static final int DIME = 10;
    private static final int QUARTER = 25;
    private static final int LOONIE = 100;
    private static final int TOONIE = 200;

    private int change; // the change due to the customer

    private int pCounter; // counts pennies 
    private int nCounter; // counts nickles
    private int dCounter; // counts dimes
    private int qCounter; // counts quarters
    private int lCounter; // counts loonies
    private int tCounter; // counts toonies

    // constructors
    public Cashier()
    {
        change = 0;
        pCounter = 0;
        nCounter = 0;
        dCounter = 0;
        qCounter = 0;
        lCounter = 0;
        tCounter = 0;
    }

    // methods

    /**
     * Calculates the correct change
     * @param amountDue the total of the bill
     * @param amountReceived the amount from the customer
     * @return true for valid inputs, false otherwise
     */
    public boolean calculateChange (int amountDue, int amountReceived)
    {
        // checks for valid input
        if (amountDue >= amountReceived)
        {
            System.out.println("Not enough money! Try again");
            return false;
        }
        
        // change is theb bill minus the customer payment
        change = amountReceived - amountDue;

        
        /* starting from the largest coin to the smallest loops to fit as many
           of a coin in as possible */
        while (change >= TOONIE)
        {
            change -= TOONIE;
            tCounter++;
        } 
        
        while (change >= LOONIE)
        {
            change -= LOONIE;
            lCounter++;
        }

        while (change >= QUARTER)
        {
            change -= QUARTER;
            qCounter++;
        }
        
        while (change >= DIME)
        {
            change -= DIME;
            dCounter++;
        }
        while (change >= NICKLE)
        {
            change -= NICKLE;
            nCounter++;
        }
        while (change >= PENNIES)
        {
            change -= PENNIES;
            pCounter++;
        }       
        
        return true;
    }

    /**
     * Prints the change
     * @param none
     * @return an output of the correct change
     */
    public void printChange()
    {
        System.out.printf("Change\n");
        System.out.printf("%d toonies, %d loonies, %d quarters, %d dimes, %d nickles, %d pennies\n", tCounter, lCounter, qCounter, dCounter, nCounter, pCounter);

    }
}
