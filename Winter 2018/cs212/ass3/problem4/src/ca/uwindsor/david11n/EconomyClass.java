package ca.uwindsor.david11n;

import static ca.uwindsor.david11n.Airplane.WIDTH;

public class EconomyClass extends Seats
{
    /* private instance variable */

    /* Constructor */


    public EconomyClass(int r)
	{
		super(r);
	}

    /* methods */

    /**
     * sets up a economy class seating section
     */
    public void seatSetup()
    {
        for (int r = 0; r < super.getRows(); ++r)
        {
            for (int w = 0 ; w < WIDTH; ++w)
            {
                if (w == 0 || w == 6) super.setSeat(r, w, "w");
                if (w == 1 || w == 5) super.setSeat(r, w, "c");
                if (w == 2 || w == 4) super.setSeat(r, w, "a");
                if (w == 3) super.setSeat(r, w, " ");
            }

        }
    }
}
