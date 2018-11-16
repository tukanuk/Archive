import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class CustomerTest {
	
	CustomerDetails c1, c2;

	@Before
	public void setUp() throws Exception {
		c1 = new CustomerDetails();
		c2 = new CustomerDetails("John", 'm');
	}

	@Test
	public void testGetName() {
		assertEquals(c1.getName(), "Unknown");
		assertEquals(c2.getName(), "John");
	}

	@Test
	public void testSetName() {
		c1.setName("Mary");
		c2.setName("Tom");
		assertEquals(c1.getName(), "Mary");
		assertEquals(c2.getName(), "Tom");
	}

	@Test
	public void testGetGender() {
		c2.setName("Tom");
		assertEquals(c1.getGender(), 'x');
		assertEquals(c2.getGender(), 'm');
	}

	@Test
	public void testSetGender() {
		c1.setName("Marry");
		c1.setGender('f');
		assertEquals(c1.getGender(), 'f');
	}

	@Test
	public void testToString() {
		assertEquals(c1.toString(), "Name and gender unknown");
		c1.setName("Mary");
		c1.setGender('f');
		assertEquals(c1.toString(), "Name Mary - female");
		assertEquals(c2.toString(), "Name John - male");
	}
}
