package david11n.cs.uwindsor.ca;

public abstract class Employee 
{
	//	instance variables
	private String fName;		// first name of employee
	private String lName;		// last name of employee
	protected double pay;		// the weekly pay of the employee
	protected double bonus;		// the weekly bonus
	
	// constructors
	public Employee()
	{
		setfName("");
		setlName("");
		this.pay = 0;
		setBonus(0);
	}
	
	public Employee(String first, String last)
	{
		setfName(first);
		setlName(last);
		this.pay = 0;
		setBonus(0);

	}
	
	// methods

	/**
	 * @return first name
	 */
	public String getfName() {
		return fName;
	}

	/**
	 * @param fName first name
	 */
	public void setfName(String fName) {
		this.fName = fName;
	}

	/**
	 * @return last name
	 */
	public String getlName() {
		return lName;
	}

	/**
	 * @param lName set last name
	 */
	public void setlName(String lName) {
		this.lName = lName;
	}

	/**
	 * @return the pay
	 */
	public double getPay() {
		return pay;
	}

	/**
	 * @param pay the pay to set
	 */
	public void setPay() {
	}

	/**
	 * @return the bonus
	 */
	public double getBonus() {
		return bonus;
	}

	/**
	 * @param bonus the bonus to set
	 */
	public void setBonus(double bonus) {
		this.bonus = bonus;
	}
	
}
