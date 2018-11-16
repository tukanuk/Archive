package david11n.cs.uwindsor.ca;

public class Hourly extends Employee
{
	// private instance variables 
	private double hourlyRate;			 	// hourly wage for employee
	private double overtimeMultiplier;		// overtime multiplier
	private double overtimeStart;			// hour that overtime kicks in
    private double hoursWorked;       		// number of hours worked in a week


	// constructors
	public Hourly(String first, String last, double rate)
	{
        super(first, last);				// sets superclass consructor 
        setHourlyRate(rate);
        overtimeMultiplier = 1.50;
        overtimeStart = 40;
        hoursWorked = 0;
	}
	
	// methods

	/**
	 * @return the hourlyRate
	 */
	public double getHourlyRate() {
		return hourlyRate;
	}

	/**
	 * @param hourlyRate set the hourlyRate
	 */
	public void setHourlyRate(double hourlyRate) {
		this.hourlyRate = hourlyRate;
    }
	
	/**
	 * @return hours worked
	 */
	public double getHoursWorked() {
		return hoursWorked;
	}

	/**
	 * @param hoursWorked the number of hours worked
	 */
	public void setHoursWorked(double hoursWorked) {
		this.hoursWorked = hoursWorked;
	}
    
    /**
     * @param 
     */
    public void setPay()
    {
        double ot = getHoursWorked() - overtimeStart;		// checks for overtime
        if (ot > 0)
        {
            super.pay = ( getHourlyRate() * overtimeStart ) + ( getHourlyRate() * ot * overtimeMultiplier ); 
        }
        else super.pay = getHourlyRate() * getHoursWorked();
    }
	
    /**
     * @return the overtime multiplier
     */
	public double getOvertimeMultiplier() {
		return overtimeMultiplier;
	}
	
	/**
	 * @param overtimeMultiplier set the overtime multiplier
	 */
	public void setOvertimeMultiplier(double overtimeMultiplier) {
		this.overtimeMultiplier = overtimeMultiplier;
	}

}