/**
   Perfom two math problems
   Solves 60-212 Ass #1 problem #3
   @author Ben Davidson
   @version 1.0 2018-01-22
*/

class Problem3
{
    public static void main(String[] args)
    {
       System.out.println("s = " + formulaS());
       System.out.println("G = " + formulaG());
    }

    /**
     * Calcualtes the value of s according to the formula in Assigment 1 Problem 3.
     * @return the result of the formula
     */
    private static double formulaS()
    {
        double s = 0;
        double s0 = 2;
        double v0 = 2;
        double g = 2;
        double t = 2;

        s = s0 * v0 - 0.5 * g * Math.pow(t, 3);

        return s;
    }

    /**
     * Calculates the value of G according the formular in Assigment 1 Problem 3
     * @return the restult of the forumla
     */
    private static double formulaG()
    {
        double G = 50;
        double a = 10;
        double p = 5;
        double m1 = 7;
        double m2 = 4;

        G = ( (3.0/4) * Math.pow(Math.PI, 2) ) * (Math.pow(a, 3) / (Math.pow(p, 0.5)*(m1 - m2) ) );
        
        return G;
    }
}

