
public class Customer 
{
	// instance variables
	private String firstName;
	private String lastName;
	
	// constructor
	public Customer (String fName, String lName)
	{
		setFirstName(fName);
		setLastName(lName);
	}

	// methods
	
	/**
	 * @return the firstName
	 */
	public String getFirstName() {
		return firstName;
	}

	/**
	 * @param firstName the firstName to set
	 */
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	/**
	 * @return the lastName
	 */
	public String getLastName() {
		return lastName;
	}

	/**
	 * @param lastName the lastName to set
	 */
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	

	
}
