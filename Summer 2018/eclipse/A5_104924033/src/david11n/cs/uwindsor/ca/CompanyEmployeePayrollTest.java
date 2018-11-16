package david11n.cs.uwindsor.ca;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class CompanyEmployeePayrollTest {

	BaseSalariedCommissionEmployee t1, t2;
	CommissionEmployee c1, c2;
	Employee e1, e2;
	HourlyEmployee h1, h2;
	PieceWorkerEmployee p1, p2;
	SalariedEmployee s1, s2;

	@BeforeEach 
	public void setup() throws Exception {
		t1 = new BaseSalariedCommissionEmployee();
		t2 = new BaseSalariedCommissionEmployee();
		c1 = new CommissionEmployee();
		c2 = new CommissionEmployee();
		e1 = new Employee();
		e2 = new Employee();
		h1 = new HourlyEmployee();
		h2 = new HourlyEmployee();
		p1 = new PieceWorkerEmployee();
		p2 = new PieceWorkerEmployee();
		s1 = new SalariedEmployee();
		s2 = new SalariedEmployee();
	}
	

	@Test
	void testSetWeeklySalary() {
		s1.setWeeklySalary(1000);
		s2.setWeeklySalary(58.05);
		assertEquals(s1.getWeeklySalary(), 1000,0.001);
		assertEquals(s2.getWeeklySalary(), 58.05, 0.001);
	}

	@Test
	void testGetWeeklySalary() {
		s1.setWeeklySalary(1000);
		s2.setWeeklySalary(58.05);
		assertEquals(s1.getWeeklySalary(), 1000,0.001);
		assertEquals(s2.getWeeklySalary(), 58.05, 0.001);
	}

	@Test
	void testSalariedEmployeeEarnings() {
		s1.setWeeklySalary(1000);
		s2.setWeeklySalary(45.67);
		assertEquals(s1.salariedEmployeeEarnings(), 1000, 0.001);
		assertEquals(s2.salariedEmployeeEarnings(), 45.67, 0.001);
	}
	

	@Test
	void testSetWagePerPieces() {
		p1.setWagePerPieces(0.10);
		p2.setWagePerPieces(0.25);
		assertEquals(p1.getWagePerPieces(), 0.10, 0.001);
		assertEquals(p2.getWagePerPieces(), 0.25, 0.001);
	}

	@Test
	void testGetWagePerPieces() {
		p1.setWagePerPieces(0.10);
		p2.setWagePerPieces(0.25);
		assertEquals(p1.getWagePerPieces(), 0.10, 0.001);
		assertEquals(p2.getWagePerPieces(), 0.25, 0.001);		
	}

	@Test
	void testSetNumberOfPiecesOfMerchandise() {
		p1.setNumberOfPiecesOfMerchandise(1000);
		p2.setNumberOfPiecesOfMerchandise(500);
		assertEquals(p1.getNumberOfPiecesOfMerchandise(), 1000);
		assertEquals(p2.getNumberOfPiecesOfMerchandise(), 500);
	}

	@Test
	void testGetNumberOfPiecesOfMerchandise() {
		p1.setNumberOfPiecesOfMerchandise(1000);
		p2.setNumberOfPiecesOfMerchandise(500);
		assertEquals(p1.getNumberOfPiecesOfMerchandise(), 1000);
		assertEquals(p2.getNumberOfPiecesOfMerchandise(), 500);
	}

	@Test
	void testPieceWorkerEmployeeEarnings() {
		p1.setWagePerPieces(0.01);
		p1.setNumberOfPiecesOfMerchandise(1000);
		p2.setWagePerPieces(0.1);
		p2.setNumberOfPiecesOfMerchandise(100);
		assertEquals(p1.pieceWorkerEmployeeEarnings(), 10.10, 0.001);
		assertEquals(p2.pieceWorkerEmployeeEarnings(), 10.10, 0.001);
	}

	@Test
	void testSetWage() {
		h1.setWage(23);
		h2.setWage(55);
		assertEquals(h1.getWage(), 23, 0.001);
		assertEquals(h2.getWage(), 55, 0.001);
	}

	@Test
	void testGetWage() {
		h1.setWage(100);
		h2.setWage(2000);
		assertEquals(h1.getWage(), 100, 0.001);
		assertEquals(h2.getWage(), 2000, 0.001);
	}

	@Test
	void testSetHours() {
		h1.setHours(44.5);
		h2.setHours(38.2);
		assertEquals(h1.getHours(), 44.5, 0.001);
		assertEquals(h2.getHours(), 38.2, 0.001);
	}

	@Test
	void testGetHours() {
		h1.setHours(33);
		h2.setHours(1);
		assertEquals(h1.getHours(), 33, 0.001);
		assertEquals(h2.getHours(), 1, 0.001);
	}

	@Test
	void testHourlyEmployeeEarnings() {
		h1.setHours(47.5);
		h2.setHours(33);
		h1.setWage(10);
		h2.setWage(20);
		assertEquals(h1.hourlyEmployeeEarnings(), 512.50, 0.001);
		assertEquals(h2.hourlyEmployeeEarnings(), 660, 0.001);
	}

	@Test
	void testGetName() {
		e1.setName("Harry");
		e2.setName("John");
		assertEquals(e1.getName(), "Harry");
		assertEquals(e2.getName(), "John");
	}

	@Test
	void testSetName() {
		e1.setName("Ben");
		e2.setName("Michelle");
		assertEquals(e1.getName(), "Ben");
		assertEquals(e2.getName(), "Michelle");
		
	}

	@Test
	void testGetAddress() {
		e1.setAddress("2320 Sam Street");
		e2.setAddress("234564 1st Street");
		assertEquals(e1.getAddress(), "2320 Sam Street");
		assertEquals(e2.getAddress(), "234564 1st Street");
	}

	@Test
	void testSetAddress() {
		e1.setAddress("123 Main St.");
		e2.setAddress("45 3rd St.");
		assertEquals(e1.getAddress(), "123 Main St.");
		assertEquals(e2.getAddress(), "45 3rd St.");
	}

	@Test
	void testGetSIN() {
		e1.setSIN("123456789");
		e2.setSIN("965125478");
		assertEquals(e1.getSIN(), "123456789");
		assertEquals(e2.getSIN(), "965125478");
	}

	@Test
	void testSetSIN() {
		e1.setSIN("965125478");
		e2.setSIN("123456789");
		assertEquals(e1.getSIN(), "965125478");
		assertEquals(e2.getSIN(), "123456789");
	}
	
	@Test
	void testGetBaseSalary() {
		assertEquals(t1.getBaseSalary(), 0);
		assertEquals(t2.getBaseSalary(), 0);
	}
	
	@Test
	void testSetBaseSalary() {
		t1.setBaseSalary(5000);
		t2.setBaseSalary(10000);
		assertEquals(t1.getBaseSalary(), 5000, 1);
		assertEquals(t2.getBaseSalary(), 10000, 1);
	}

	@Test
	void testBaseSalariedCommissionEmployeeEarnings() {
		t1.setCommissionRate(0.10);
		t1.setGrossSales(10000);
		t1.setBaseSalary(100);
		t2.setCommissionRate(0.20);
		t2.setGrossSales(5000);
		t2.setBaseSalary(3000);
		assertEquals(t1.baseSalariedCommissionEmployeeEarnings(), 1100, 1);
		assertEquals(t2.baseSalariedCommissionEmployeeEarnings(), 4000, 1);
	}
	

	@Test
	void testGetCommissionRate() {
		c1.setCommissionRate(0.50);
		c2.setCommissionRate(0.22);
		assertEquals(c1.getCommissionRate(), 0.50, 0.001);
		assertEquals(c2.getCommissionRate(), 0.22, 0.001);
	}

	@Test
	void testSetCommissionRate() {
		c1.setCommissionRate(.55);
		c2.setCommissionRate(.66);
		assertEquals(c1.getCommissionRate(), 0.55, 0.001);
		assertEquals(c2.getCommissionRate(), 0.66, 0.001);
	}

	@Test
	void testGetGrossSales() {
		c1.setGrossSales(1000);
		c2.setGrossSales(2000);
		assertEquals(c1.getGrossSales(), 1000, 0.001);
		assertEquals(c2.getGrossSales(), 2000, 0.001);
	}

	@Test
	void testSetGrossSales() {
		c1.setGrossSales(5);
		c2.setGrossSales(9999);
		assertEquals(c1.getGrossSales(), 5, 0.001);
		assertEquals(c2.getGrossSales(), 9999, 0.001);
	}

	@Test
	void testCommissionEmployeeEarnings() {
		c1.setCommissionRate(0.1);
		c2.setCommissionRate(0.5);
		c1.setGrossSales(10);
		c2.setGrossSales(6000);
		assertEquals(c1.commissionEmployeeEarnings(), 1, 0.001);
		assertEquals(c2.commissionEmployeeEarnings(), 3000, 0.001);
	}
}
