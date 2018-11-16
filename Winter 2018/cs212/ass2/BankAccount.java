/**
 * A simple bank account. takes deposits, withdrawls, tracks balance
 */

public class BankAccount
{
    //instance variable

    private double balance; // stores account balance
    private final static double TRANSFEE = 0.50; // transaction fee
    private final static int FREETRANS = 10; // number of free transactions
    private int transCounter; //number of monthly transactions

    //constuctors
    public BankAccount ()
    {
        balance = 0.0;
        transCounter = 0;
    }

    public BankAccount (double amount)
    {
        balance = amount;
        transCounter = 0;
    }

    //methods

    /**
     * adds a deposit to the bank account balance
     * @param amount the amount to be deposited
     */
    public void deposit(double amount)
    {
        balance += amount;
        transCounter++;
    }

    /** withdrawls money from the bank account
     * @param amount the amount to be withdrawn
     */
    public void withdrawl(double amount)
    {
        balance -= amount;
        transCounter++;
    }

    /**
     * return the bank acount balance
     * @return the bank acount balance
     */
    public double getBalance ()
    {
        return balance;
    }

    /**
     * deductes the monthly charge 
     * @param none
     * @return the monthly fee
     */
    public double deductMonthlyCharge()
    {
        double monthlyFee = 0;

        if (transCounter > 10)
        {
            monthlyFee = (transCounter - FREETRANS) * TRANSFEE;

            balance -= monthlyFee;
        }

        transCounter = 0;

        return monthlyFee;
    }

}