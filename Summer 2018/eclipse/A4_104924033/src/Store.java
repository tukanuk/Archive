/**
 * 
 */

/**
 * @author benjamin
 *
 */
public class Store 
{
	private String name;
	private String address;
	private ProductList theList = new ProductList();
	/**
	 * @return the name
	 */
	public String getName() {
		return name;
	}
	/**
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}
	/**
	 * @return the address
	 */
	public String getAddress() {
		return address;
	}
	/**
	 * @param address the address to set
	 */
	public void setAddress(String address) {
		this.address = address;
	}
	/**
	 * @return the theList
	 */
	public ProductList getTheList() {
		return theList;
	}
	/**
	 * @param theList the theList to set
	 */
	public void setTheList(ProductList theList) {
		this.theList = theList;
	}
}
