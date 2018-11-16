import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TestCalculator {

	Calculator dm;
	@Before
	public void setUp() throws Exception {
		this.dm = new Calculator();
	}

	@Test
	public void testSubtract() {
		int outS1 = dm.subtract(500, 345);
		assertEquals(155, outS1);
		int outS2 = dm.subtract(500, 845);
		assertEquals(345, outS2);
	}

	@Test
	public void testAdd() {
		int outA = dm.add(349, 345);
		assertEquals(694, outA);
	}
}
