public class AccountingFormatter implements NumberFormatter
{
    public String format(int n)
    {
        if (n < 0)
        {
            n = n * -1;
            return "(" + Integer.toString(n) + ")"; //pn;
        }
        else
        {
            //String pn = Integer.toString(n);
            return Integer.toString(n);
        }
    }
}