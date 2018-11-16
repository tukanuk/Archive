package ca.uwindsor.david11n;

import static ca.uwindsor.david11n.Airplane.WIDTH;

/**
 * Describes the seats available on the airplane
 */
public class Seats
{
    /* Instance Variable */

   	private String[][] seats;
	private int row;


	/* Constructors */
	
	public Seats(int r)
	{
		seats = new String[r][WIDTH];
		row = r;
	}



	/* Methods */

	/**
	 * Gets the number of rows of the section
	 * @return int the number of rows
     */
	public int getRows()
	{
		return row;
	}

	/**
	 * Sets a seat
	 * @param row the row of the seat
	 * @param col the column of the seat
	 * @param set the status of the seat
	*/
	public void setSeat(int row, int col, String set)
	{
		seats[row][col] = set;
	}

	/**
	 * Gets a seat status
	 * @param row the seat row
	 * @param col the seat col
	 * @return the seat status
	 */
	public String getSeat(int row, int col)
	{
		return seats[row][col];
	}
}
