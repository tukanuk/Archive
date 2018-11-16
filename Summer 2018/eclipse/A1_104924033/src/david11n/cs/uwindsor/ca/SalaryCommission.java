package david11n.cs.uwindsor.ca;

public class SalaryCommission extends Commission 
{
	// private instance variables
	
	private double baseSalary; 		// employee base salary
	private double bonusRate;		// multiplier for bonus
	
	// constructors
	
	public SalaryCommission(String first, String last, double rate, double base, double bRate) 
	{
		super(first, last, rate);
		setBaseSalary(base);
		setBonusRate(bRate);
	}

	// methods
	
	/**
	 * @return the baseSalary
	 */
	public double getBaseSalary() {
		return baseSalary;
	}


	/**
	 * @param baseSalary the baseSalary to set
	 */
	public void setBaseSalary(double baseSalary) {
		this.baseSalary = baseSalary;
	}

	/**
	 * @return the bonusRate
	 */
	public double getBonusRate() {
		return bonusRate;
	}

	/**
	 * @param bonusRate the bonusRate to set
	 */
	public void setBonusRate(double bonusRate) {
		this.bonusRate = bonusRate;
	}
	
	
	/**
	 * @param bonus the bonus to set
	 */
	public void setBonus() {
		super.bonus = baseSalary * bonusRate; // base salary * bonus rate
	}
	
	/**
     * @param 
     */
    public void setPay()
    {
		setBonus(); // applies the bonus
		super.pay = ( getBaseSalary() + ( super.getCommissionRate() * super.getSales() ) + getBonus() );
    }
	
	
	
	

}
