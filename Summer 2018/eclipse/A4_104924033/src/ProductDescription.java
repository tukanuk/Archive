
public class ProductDescription 
{
	private int itemID;
	private String description;
	private Money price;
	/**
	 * @return the itemID
	 */
	public int getItemID() {
		return itemID;
	}
	/**
	 * @param itemID the itemID to set
	 */
	public void setItemID(int itemID) {
		this.itemID = itemID;
	}
	/**
	 * @return the description
	 */
	public String getDescription() {
		return description;
	}
	/**
	 * @param description the description to set
	 */
	public void setDescription(String description) {
		this.description = description;
	}
	/**
	 * @return the price
	 */
	public Money getPrice() {
		return price;
	}
	/**
	 * @param price the price to set
	 */
	public void setPrice(Money price) {
		this.price = price;
	}
}
