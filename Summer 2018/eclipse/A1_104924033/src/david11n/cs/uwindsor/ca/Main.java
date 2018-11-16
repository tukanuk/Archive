package david11n.cs.uwindsor.ca;

public class Main {

	public static void main(String[] args) 
	{
				
		// Create some sample employees
		Salary emp2 = new Salary("Catherine", "Davis", 300.00);
		Hourly emp3 = new Hourly("Alyssa", "Boxer", 20.00);
		Hourly emp7 = new Hourly("Katie", "Lenvinson", 20.00);
		Commission emp4 = new Commission("Edward", "Fish", 0.10);
		SalaryCommission emp5 = new SalaryCommission("George", "Harris", 0.01, 400, .1);
		Piece emp6 = new Piece("Iris", "Jupiter", 0.50, 0.01);

		// Calculate Pay - a series of pay runs. 
		// Each pay has two parts. 1. set method used to calculate pay (except staight salary). 2. Calculate the pay. 

		// Pay for a salaried employee. 
		calculatePay(emp2);
		System.out.println(emp2.getfName() + "'s salary is $" + emp2.getSalary() + " and their pay is $" + emp2.getPay() + " [$300.00 expected]");
		
		// Pay for a hourly worker 
		emp3.setHoursWorked(10);									// set to ten hours of work
		calculatePay(emp3);
		System.out.println(emp3.getfName() + " worked " + emp3.getHoursWorked() + " hours for $" + emp3.getHourlyRate() + " and their pay is $" + emp3.getPay() + " [$200.00 expected]");
		
		// Pay for a hourly worker with overtime
		emp7.setHoursWorked(50);									// set to fifty hours of work to test overtime
		calculatePay(emp7);
		System.out.println(emp7.getfName() + " worked " + emp7.getHoursWorked() + " hours. That's 40 hours at $" + emp7.getHourlyRate() + " and " + (emp7.getHoursWorked() - 40) + " hours at $" + emp7.getHourlyRate() * emp7.getOvertimeMultiplier() + ". Their pay is $" + emp7.getPay() + " [$1100.00 expected]");

		// Pay for a Commission based worker
		emp4.setSales(1000);										// $1000 of weekly sales
		calculatePay(emp4);
		System.out.println(emp4.getfName() + "'s sales were $" + emp4.getSales() + " at " + emp4.getCommissionRate() + "% commission. Their pay is $" + emp4.getPay() + " [$100.00 expected]");

		// Pay for a salary + commission worker
		emp5.setSales(1000);										// $1000 of weekly sales
		calculatePay(emp5);
		System.out.println(emp5.getfName() + "'s salary is $" + emp5.getBaseSalary() + " plus $" + emp5.getCommissionRate() * emp5.getSales() + " in commission. They also get a $" + emp5.bonus + " bonus. Their pay is $" + emp5.getPay() + " [$450.00 expected]");

		// Pay for a piece worker
		emp6.setPieceMerch(1000);									// 1000 items made
		calculatePay(emp6);
		System.out.printf("%s produced %d items and earned $%.2f for each item. They also earned a $%.2f bonus. Their pay is $%.2f. %s", emp6.getfName(), emp6.getPieceMerch(), emp6.getPieceRate(), emp6.getBonus(), emp6.getPay(), "[$505.00 expected]" );


	}

	/**
	 * @param emp The employee object 
	 */
	private static double calculatePay(Employee emp) // inheritance allows objects to typed as superclass
	{
		emp.setPay();								// each individual subclass overrides the superclass setPay method and implements it in an appropriate way
		return emp.getPay();
	}

}
