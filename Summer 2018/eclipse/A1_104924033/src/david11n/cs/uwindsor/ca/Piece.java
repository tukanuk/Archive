package david11n.cs.uwindsor.ca;

public class Piece extends Employee
{
	// private instance variables
	private double pieceRate;		// pay per piece 
	private int pieceMerch; 		// the number of pieces of merchandise produced
	private double bonusRate;		// multiplier for bonus
	
	// constructors
	
	public Piece (String first, String last, double pRate, double bRate)
	{
		super(first, last);
		setPieceRate(pRate);
		setBonusRate(bRate);
		
	}
	
	// methods

	/**
	 * @return the pieceRate
	 */
	public double getPieceRate() {
		return pieceRate;
	}

	/**
	 * @param pieceRate the pieceRate to set
	 */
	public void setPieceRate(double pieceRate) {
		this.pieceRate = pieceRate;
	}

	/**
	 * @return the pieceMerch
	 */
	public int getPieceMerch() {
		return pieceMerch;
	}

	/**
	 * @param pieceMerch the pieceMerch to set
	 */
	public void setPieceMerch(int pieceMerch) {
		this.pieceMerch = pieceMerch;
	}

	/**
	 * @return the bonusRate
	 */
	public double getBonusRate() {
		return bonusRate;
	}

	/**
	 * @param bonusRate the bonusRate to set
	 */
	public void setBonusRate(double bonusRate) {
		this.bonusRate = bonusRate;
	}
	
	/**
	 * @param bonus the bonus to set
	 */
	public void setBonus() {
		super.bonus = (pieceMerch * bonusRate * pieceRate);	// pieces made * piece rate * bonus rate
	}
	
	/**
     * @param 
     */
    public void setPay()
    {
		setBonus();
		super.pay = ( ( getPieceRate() * getPieceMerch() ) + getBonus() ); // adds bonus
    }
	
}
