import java.util.Date;

public class Sale {
	private boolean isComplete;
	private Date dateTime = new Date();
	
	// constructor
	public Sale(Date dateTime, ShoppingCart sc)
	{
		this.dateTime = dateTime;
	}
	
	// methods
	
	/**
	 * @return the isComplete
	 */
	public boolean isComplete() {
		return isComplete;
	}
	/**
	 * @param isComplete the isComplete to set
	 */
	public void setComplete(boolean isComplete) {
		this.isComplete = isComplete;
	}
	/**
	 * @return the dateTime
	 */
	public Date getDateTime() {
		return dateTime;
	}
	/**
	 * @param dateTime the dateTime to set
	 */
	public void setDateTime(Date dateTime) {
		this.dateTime = dateTime;
	}
	
	// move to shopping cart
	public double getTotal()
	{
		return 0.0;
	}
	
	public void processOrder()
	{
		OrderProcessor op = new OrderProcessor();
	}
	
	
}
