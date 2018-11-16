public class Monthly extends Appointment
{
    /* Private instance variables */
    int day;
    int month;

    /* Constructor */

    public Monthly(int day, String description)
    {
        this.day = day;
        this.description = description;
    }

	/* Methods */
    public int occursOn(int day, int month, int year)
    {
        if (this.day == day)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }   
}