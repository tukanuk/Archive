package david11n.cs.uwindsor.ca;

public class Salary extends Employee 
{
    // instance variables
    private double salary;      // weekly salary

    // constructors
    public Salary(String first, String last, double sal)
    {
        super(first, last);		// set the constructor of the superclass
        setSalary(sal);
    }

    // methods

	/**
	 * @return the salary
	 */
	public double getSalary() {
		return salary;
	}

	/**
	 * @param salary the salary to set
	 */
	public void setSalary(double salary) {
		this.salary = salary;
	}

    /**
     * @param 
     */
    public void setPay()
    {
        super.pay = getSalary();
    }
}
