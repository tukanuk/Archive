
public class Calculator implements Adder, Subtractor {

	@Override
	public int subtract(int op1, int op2) {
		if (op1 > op2)
			return op1-op2;
		else
			return op2-op1;
	}

	@Override
	public int add(int op1, int op2) {
		return op1+op2;
	}

}
