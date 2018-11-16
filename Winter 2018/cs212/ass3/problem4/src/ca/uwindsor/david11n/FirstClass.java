package ca.uwindsor.david11n;

import static ca.uwindsor.david11n.Airplane.WIDTH;

/**
 * Describes a first class seating section
 */
public class FirstClass extends Seats
{
    /* Private instance variables */

    /* Constructor */

    public FirstClass(int r)
    {
		super(r);       
    }

	/* Methods */

    /**
     * Sets up a first class seating section.
     */
	public void seatSetup()
    {
        for (int r = 0 ; r < super.getRows(); ++r)
        {
            for (int w = 0; w < WIDTH; ++w)
            {
                if (w == 0 || w == 6) super.setSeat(r, w, "w");
                if (w == 1 || w == 5 || w == 3) super.setSeat(r, w, " ");
                if (w == 2 || w == 4) super.setSeat(r, w, "a");
            }
  
		}
        for (int w = 0 ; w < WIDTH; ++w)
       	{
           	if (w == 3)  super.setSeat(super.getRows() - 1 , w, " ");
           	else  super.setSeat(super.getRows() - 1, w, "-");
		}
	}
}
