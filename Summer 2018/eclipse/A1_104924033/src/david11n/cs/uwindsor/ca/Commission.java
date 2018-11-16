package david11n.cs.uwindsor.ca;

public class Commission extends Employee 
{
	// private instance variables
	
	private double sales;			// sales generate by employee
	private double commissionRate; 	// the percentage of sales for pay
	
	// constructors
	
	public Commission (String first, String last, double rate)
	{
		super(first, last);
		setCommissionRate(rate);
		setSales(0);
	}
	
	// methods

	/**
	 * @return the sales
	 */
	public double getSales() {
		return sales;
	}

	/**
	 * @param sales the sales to set
	 */
	public void setSales(double sales) {
		this.sales = sales;
	}

	/**
	 * @return the commissionRate
	 */
	public double getCommissionRate() {
		return commissionRate;
	}

	/**
	 * @param commissionRate the commissionRate to set
	 */
	public void setCommissionRate(double commissionRate) {
		this.commissionRate = commissionRate;
	}

	/**
     * @param 
     */
    public void setPay()
    {
        super.pay = getCommissionRate() * getSales(); 	// commission rate * sales
    }
}
