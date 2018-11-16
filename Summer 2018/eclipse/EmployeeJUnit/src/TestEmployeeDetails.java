import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TestEmployeeDetails {

	EmpBusinessLogic empBusinessLogic;
	EmployeeDetails employee;
	
	@Before
	public void setUp() throws Exception {
		empBusinessLogic = new EmpBusinessLogic();
		employee = new EmployeeDetails();
	}
	
	@Test
	public void testCalculateAppriasal() {
		employee.setName("Bob");
	    employee.setAge(25);
	    employee.setMonthlySalary(8000);
	    
	    double appraisal = empBusinessLogic.calculateAppraisal(employee);
	    assertEquals(500, appraisal, 0.0);
	}
	
	@Test
	public void testCalculateYearlySalary() {
		employee.setName("Alice");
		employee.setAge(25);
		employee.setMonthlySalary(8000);
	
		double salary = empBusinessLogic.calculateYearlySalary(employee);
		assertEquals(96000, salary, 0.0);
   }
}