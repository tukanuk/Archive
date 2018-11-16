
public class Calc2 implements Multiplication, Division{

	@Override
	public int multiplication(int op1, int op2) {
		return op1*op2;
	}

	@Override
	public int division(int op1, int op2) {
		return op1/op2;
	}

}
