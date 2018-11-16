public class Daily extends Appointment
{
    /* Private instance variables */
    int day;

    /* Constructor */
    public Daily (String description)
    {
        this.description = description;
    }

    /* Methods */
    
    public int occursOn(int day, int month, int year)
    {
        return 1;
    }

}