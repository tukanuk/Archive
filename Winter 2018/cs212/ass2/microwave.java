import java.util.Timer;
import java.util.TimerTask;

/**
 * Implementing a virtual microwave
 * Solves 60-212 Assignment 2 Problem 1
 * @author Ben Davidson
 * @version 1.0 2018-02-05
 */

public class microwave
{
    // private instance variable
    
    private int cookTime; // control the length of time left on the countdown
    private String powerLevel; // stores the power level
    private boolean isRunning; // stores the isRunning status

    
    // constructors

    public microwave ()
    {
        cookTime = 0;
        powerLevel = "low";
        isRunning = false;
    }

    // methods

    /**
     * Increase cookTime by 10 seconds
     * @param none
     * @return totalTime
     */
    public void tenSeconds()
    {
        cookTime += 10;
    }

    /**
     * Each call, increments low(1), medium(2), or high(3)
     * @param none
     * @return none
     */
    public void powerLevel()
    {
        // rotates through the avaiable status
        if (powerLevel ==  "")
        {
            powerLevel = "low";
        } 
        else if ( powerLevel == "low" )
        {
            powerLevel = "medium";
        }
        else if ( powerLevel == "medium" )
        {
            powerLevel = "high";
        } 
        else if ( powerLevel == "high")
        {
            powerLevel = "low";
        }

        // System.out.println(powerLevel);
    }

    /**
     * Stops the countdown and the microwave
     * @param none
     * @return none
     */
    public void stop()
    {
        isRunning = false;
        System.out.println("Cooking stopped.");
    }

    /**
     * Resets the countdown timer
     * @param none
     * @return none
     */
    public void reset()
    {
        cookTime = 0;
    }

    /**
     * Start the microwave
     * @param none
     * @return none
     */
    public void start()
    {
        
       isRunning = true; // changes the status to true

        // Outputs status message
        System.out.printf("Cooking for %d seconds at level %s\n", cookTime, powerLevel);
    }
}
