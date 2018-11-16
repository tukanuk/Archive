package ca.uwindsor.david11n;

public class ComboLock
{
    /* Private instance variables */

    private final int lockNum1;
    private final int lockNum2;
    private final int lockNum3;
    private final int MAXNUM = 39;

    private boolean lockNum1Unlock;
    private boolean lockNum2Unlock;
    private boolean lockNum3Unlock;

    private int dial;

    /* Constructor */

    public ComboLock(int secret1, int secret2, int secret3)
    {
        lockNum1 = secret1;
        lockNum2 = secret2;
        lockNum3 = secret3;

        lockNum1Unlock = false;
        lockNum2Unlock = false;
        lockNum3Unlock = false;

        dial = 0;
    }

    /* Methods */

    /**
     * reset Resets the combination lock. Spins the dial back to zero and sets all unlock variables to false
     */
    public void reset()
    {
        dial = 0;
        lockNum1Unlock = false;
        lockNum2Unlock = false;
        lockNum3Unlock = false;
    }

    /**
     * turnLeft
     * @param ticks the int value of the ticks to the left
     */
    public void turnLeft(int ticks)
    {
        dial -= ticks;

        // logic to correct for turning past 0
        if (dial < 0)
        {
            dial += MAXNUM;
        }

        // check for correct combination
        if (dial == lockNum2)
        {
            lockNum2Unlock = true;
        }

    }

    /**
     * turnRight
     * @param ticks the int value of the ticks to the right
     */
    public void turnRight(int ticks)
    {
        dial += ticks;

        // logic to correct for turning past 0
        if (dial > MAXNUM)
        {
            dial -= MAXNUM;
        }

        // check for correct combination
        if (dial == lockNum1)
        {
            lockNum1Unlock = true;
        }

        // check for correct combination.
        if (dial == lockNum3 && lockNum1Unlock)
        {
            lockNum3Unlock = true;
        }
    }

    public boolean open()
    {
        // if all three are unlocked, the lock will open
        if (lockNum1Unlock && lockNum2Unlock && lockNum3Unlock)
        {
            reset();
            return true;
        }

        reset();
        return false;
    }
}
