public class BaseFormatter implements NumberFormatter
{
    // instance variable
    public int base;
    
    // constructor
    public BaseFormatter (int base)
    {
        this.base = base;
    }

    public String format(int n)
    {
        return Integer.toString(n, base);
    }
}