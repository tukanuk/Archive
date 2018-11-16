package david11n.cs.uwindsor.ca;

public class SalariedEmployee extends Employee{
	
	private double weeklySalary;
	
	public void setWeeklySalary(double weeklySalary) {
		this.weeklySalary = weeklySalary;
	}
	
	public double getWeeklySalary() {
		return weeklySalary;
	}

	public double salariedEmployeeEarnings() {
		return getWeeklySalary();
	}
}