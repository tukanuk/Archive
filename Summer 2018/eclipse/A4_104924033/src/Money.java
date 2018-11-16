
public class Money {
	
	// private instance variables
	
	private String currency;
	private double amount;
	
	// constructor
	
	public Money (double amount, String curr)
	{
		this.amount = amount;
		this.currency = curr;
	}
	
	

	/**
	 * @return the currency
	 */
	public String getCurrency() {
		return currency;
	}

	/**
	 * @param currency the currency to set
	 */
	public void setCurrency(String currency) {
		this.currency = currency;
	}

	/**
	 * @return the amount
	 */
	public double getAmount() {
		return amount;
	}

	/**
	 * @param amount the amount to set
	 */
	public void setAmount(double amount) {
		this.amount = amount;
	}
	
}
