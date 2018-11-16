class Problem4
{
    public static void main(String[] args)
    {
        System.out.println("a: " + partA() );
        System.out.println("b: " + partB() );
        System.out.println("c: " + partC() );
        System.out.println("d: " + partD() );
        System.out.println("e: " + partE() );
        System.out.println("f: " + partF() );
        System.out.println("g: " + partG() );
        System.out.println("h: " + partH() );
    }

    private static double partA()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return  x - n / y + x + (n * y) ;
    }

    private static double partB()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return n / m + n % m ;
    }
    private static double partC()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return n % 2 + m % 3 ;
    }

    private static double partD()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return (m + n) / 3.0 ;
    }

    private static double partE()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return (n - m) / 3;
    }

    private static double partF()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return  (n - x) / 3;
    }

    private static double partG()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return 1 - (1 - (1 - n) );
    }

    private static double partH()
    {
        double x = -4.5; 
        double y = 1.6; 
        int n = 27; 
        int m = 11; 

        return m % 10 + (m - (n % 10) );
    }

}