
public class Payment 
{
	// private instance variables
	
	private Money amount;
	
	// constructor
	
	public Payment (double amount, String currency)
	{
		this.setAmount(new Money(amount, currency));
		
	}

	/**
	 * @return the amount
	 */
	public Money getAmount() {
		return amount;
	}

	/**
	 * @param amount the amount to set
	 */
	public void setAmount(Money amount) {
		this.amount = amount;
	}
	
	
}
