public class OneTime extends Appointment
{
    /* Private instance variables */
    int day;
    int month;
    int year;

    /* Constructor */
    public OneTime(int day, int month, int year, String description)
    {
        this.day = day;
        this.month = month;
        this.year = year;
        this.description = description;
    }

    /* Methods */
    public int occursOn(int day, int month, int year)
    {
        if (this.day == day && this.month == month && this.year == year)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}