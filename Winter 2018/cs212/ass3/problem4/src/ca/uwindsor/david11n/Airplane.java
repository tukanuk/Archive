package ca.uwindsor.david11n;

/**
 * Describes the seating arrangement on an airplane
 */
public class Airplane
{
    public final static int WIDTH = 7;

	private FirstClass firstPlane;
	private EconomyClass economyPlane;

    /* Constructors */

    public Airplane (FirstClass aSeat, EconomyClass bSeat)
    {
		firstPlane = aSeat;
		economyPlane = bSeat;

		firstPlane.seatSetup();
		economyPlane.seatSetup();
    }

    /* Methods */

	/**
	 * Formats the seating plan into a String
	 * @return the formatted seating plan
	 */
	public String format()
	{

		String seats = "";

		for (int r = 0 ; r < firstPlane.getRows() ; r++)
		{
			seats += "        |";

		    for (int w = 0 ; w < WIDTH; w++)
			{
				seats = seats + firstPlane.getSeat(r, w);

			}

			seats += "|\n";
		}

		for (int r = 0 ; r < economyPlane.getRows() ; r++)
		{
			seats += "        |";

		    for (int w = 0 ; w < WIDTH; w++)
			{
				seats = seats + economyPlane.getSeat(r, w);
			}

			seats += "|\n";
		}

		seats += "         -------";

		return seats;

	}

	/**
	 * Attempts to add passengers to the plane
	 * @param cChoice the chosen class
	 * @param tChoice the chosen number of passengers
	 * @param sChoice the seating preference
	 * @return true for add passenger, false for unable to add
	 */
	public boolean addPassenger(int cChoice, int tChoice, int sChoice)
	{
		String sc; // for comparing seating choices

		// sets seating choices and basic check for valid input
		if (sChoice == 1) sc = "w";
		else if (sChoice == 2) sc = "a";
		else if (sChoice == 3) sc = "c";
		else return false;

		// searching first class for empty seats that match the seat preference
		if (cChoice == 1)
		{
			for (int r = 0 ; r < firstPlane.getRows() ; ++r)
			{
				for (int w = 0 ; w < WIDTH ; ++w)
				{
					// if seat is found that matches the seating choice
					if ( (firstPlane.getSeat(r, w)).equals(sc))
					{
						// if one traveller
						if (tChoice == 1)
						{
							if (w == 0 || w == 6) 
							{
								firstPlane.setSeat(r, w, "W");
								return true;
							}
							if (w == 2 || w == 4) 
							{
								firstPlane.setSeat(r, w, "A");
								return true;
							}
						}
						// if two travellers. Checks for an open neighbouring seat in same side of aisle
						else if (tChoice == 2)
						{
							if (w == 0)
							{
								if ( (firstPlane.getSeat(r, w + 2)).equals("a"))
								{
									firstPlane.setSeat(r, w, "W");
									firstPlane.setSeat(r, w + 2, "A");
									return true;
								}
							}
							if (w == 2)
							{
								if ( (firstPlane.getSeat(r, w - 2)).equals("w") )
								{
									firstPlane.setSeat(r, w, "A");
									firstPlane.setSeat(r, w - 2, "W");
									return true;
								}
							}	
							if (w == 4)
							{
								if ( (firstPlane.getSeat(r, w + 2)).equals("w") )
								{
									firstPlane.setSeat(r, w, "A");
									firstPlane.setSeat(r, w + 2, "W");
									return true;
								}
							}
							if (w == 6)
							{
								if ( (firstPlane.getSeat(r, w - 2)).equals("a") )
								{
									firstPlane.setSeat(r, w, "W");
									firstPlane.setSeat(r, w - 2, "A");
									return true;
								}
							}
						}
						else
						{
							// if no match is found
							return false;
						}
					}
				}
			}
		}
		// economy class seat check
		else if (cChoice == 2)
		{
			for (int r = 0 ; r < economyPlane.getRows() ; ++r)
			{
				for (int w = 0 ; w < WIDTH ; ++w)
				{
					// searching economy class for empty seats that match the seat preference
					if ( (economyPlane.getSeat(r, w) ).equals(sc) )
					{
						// one passenger check
						if (tChoice == 1)
						{
							if (w == 0 || w == 6) 
							{
								economyPlane.setSeat(r, w, "W");
								return true;
							}
							if (w == 2 || w == 4) 
							{
								economyPlane.setSeat(r, w, "A");
								return true;
							}
						}
						// two passenger check checks for empty neighbouring seat on same side of aisle
						else if (tChoice == 2)
						{
							if (w == 0)
							{
								if ( (economyPlane.getSeat(r, w + 1)).equals("c") )
								{
									economyPlane.setSeat(r, w, "W");
									economyPlane.setSeat(r,w + 1, "C");
									return true;
								}
							}
							if (w == 1)
							{
								if ( (economyPlane.getSeat(r, w + 1)).equals("a") )
								{
									economyPlane.setSeat(r, w, "C");
									economyPlane.setSeat(r, w + 1, "A");
									return true;
								}
								else if ( (economyPlane.getSeat(r, w - 1)).equals("w") )
								{
									economyPlane.setSeat(r, w, "C");
									economyPlane.setSeat(r, w - 1, "W");
									return true;
								}
							}
							if (w == 2)
							{
								if ( (economyPlane.getSeat(r, w - 1) ).equals("c") )
								{
									economyPlane.setSeat(r, w, "A");
									economyPlane.setSeat(r, w - 2, "C");
									return true;
								}
							}	
							if (w == 4)
							{
								if ( (economyPlane.getSeat(r, w + 1) ).equals("c") )
								{
									economyPlane.setSeat(r, w, "A");
									economyPlane.setSeat(r, w + 1, "C");
									return true;
								}
							}
							if (w == 5)
							{
								if ( (economyPlane.getSeat(r, w - 1) ).equals("a") )
								{
									economyPlane.setSeat(r, w, "C");
									economyPlane.setSeat(r, w - 1, "A");
								}
								else if ( (economyPlane.getSeat(r, w + 1) ).equals("w") )
								{
									economyPlane.setSeat(r, w, "C");
									economyPlane.setSeat(r, w + 1, "W");
									return true;
								}
									
							}
							if (w == 6)
							{
								if ( (economyPlane.getSeat(r, w - 1) ).equals("c") )
								{
									economyPlane.setSeat(r, w, "W");
									economyPlane.setSeat(r, w - 1, "C");
									return true;
								}
							}
						}
						// three passenger check check checks for empty neighbouring seats on same side of aisle
						else if (tChoice == 3)
						{
							if (w == 0)
							{
								if ( (economyPlane.getSeat(r, w + 1) ).equals("c") &&
									 (economyPlane.getSeat(r, w + 2) ).equals("a") )
								{
									economyPlane.setSeat(r, w, "W");
									economyPlane.setSeat(r, w + 1, "C");
									economyPlane.setSeat(r, w + 2, "A");
									return true;
								}
							}
							if (w == 1)
							{
								if ( (economyPlane.getSeat(r, w + 1) ).equals("a") &&
									 (economyPlane.getSeat(r, w - 1) ).equals("w") )
								{
									economyPlane.setSeat(r, w, "C");
									economyPlane.setSeat(r, w + 1, "A");
									economyPlane.setSeat(r, w - 1, "W");
									return true;
								}
							}
							if (w == 2)
							{
								if ( (economyPlane.getSeat(r, w - 1) ).equals("c") &&
									 (economyPlane.getSeat(r, w - 2) ).equals("w") )
								{
									economyPlane.setSeat(r, w, "A");
									economyPlane.setSeat(r, w - 1, "C");
									economyPlane.setSeat(r, w - 2, "W");
									return true;
								}
							}	
							if (w == 4)
							{
								if ( (economyPlane.getSeat(r, w + 1) ).equals("c") &&
									 (economyPlane.getSeat(r, w + 2) ).equals("w") )
								{
									economyPlane.setSeat(r, w, "A");
									economyPlane.setSeat(r, w + 1, "C");
									economyPlane.setSeat(r, w + 2, "W");
									return true;
								}
							}
							if (w == 5)
							{
								if ( (economyPlane.getSeat(r, w - 1) ).equals("a") &&
									 (economyPlane.getSeat(r, w + 1) ).equals("w") )
								{
									economyPlane.setSeat(r, w, "C");
									economyPlane.setSeat(r, w - 1, "A");
									economyPlane.setSeat(r, w + 1, "W");
									return true;
								}
									
							}
							if (w == 6)
							{
								if ( (economyPlane.getSeat(r, w - 1) ).equals("c") &&
									 (economyPlane.getSeat(r, w - 2) ).equals("a") )
								{
									economyPlane.setSeat(r, w, "W");
									economyPlane.setSeat(r, w - 1, "C");
									economyPlane.setSeat(r, w - 2, "W");
									return true;
								}
							}

						}
						else
						{
							// if unable to find empty seats for travelling companions
							return false;
						}
					}
				}
			}
		}

		// if an invalid number of travellers was chosen
		return false;
	}
}
