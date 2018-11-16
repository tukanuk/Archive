import java.text.DecimalFormat;

public class DecimalSeparatorFormatter implements NumberFormatter
{
    public String format(int n)
    {
        // String pattern = "###.###";
        // DecimalFormat dF = new DecimalFormat("###,###");
        // // while (n > 0)
        // {
        //     pn = Integer.toString(n%10) + pn;
        //     if ( (pn.length() % 3) == 0)
        //     {
        //         pn = "," + pn;
        //     }
        //     n /= 10;
        // }
        // return dF.format(n);
        // or you could jus do it the simple way...
        return String.format("%,d", n);
    }
}