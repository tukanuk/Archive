import java.awt.Point;

public class quiz5
{
    public static void main (String[] args)
    {
        // create a new point object 
        // use empty construction (numbers would be ints)
        Point p = new Point();

        double x = 5.0;
        double y = 10.0;
        
        System.out.println("x: " + x + " y: " + y);
        
        // set the location of x and y using floating point numbers
        p.setLocation(x, y);

        // Display the original location
        System.out.println(p.getLocation());

        //swap locations 
        p.setLocation(p.getY(), p.getX());

        //double temp = p.getX();
        x = p.getX();
        y = p.getY();

        // Display the swapped locations
        System.out.println("x: " + x + " y: " + y);
    }
}