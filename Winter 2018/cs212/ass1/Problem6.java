import java.awt.geom.*;


/**
 * Working with lines, ellipses and the API documentation
 * Solves 60-212 Assignment 1 Problem 6
 * @author Benjamin Davidson
 * @version 1.0 January 26, 2018
 */

public class Problem6
{
    public static void main(String[] args)
    {
        // Creating a line
        Line2D.Double newLine = new Line2D.Double(5, 10, 20, 35);

        newLine.setLine(5, 10, 10, 15);

        // Test output
        System.out.println("newLine");
        System.out.println("end point: (" + newLine.getX2() + ", " + newLine.getY2() + ") Expected: (10.0, 15.0)");

        // Creating an ellipse
        Ellipse2D.Double newEllipse = new Ellipse2D.Double(5, 15, 50, 30);
        
        // Test output
        System.out.println(""); //spacer
        System.out.println("newEllipse");
        System.out.println("Actual position of upper-left corner: " + newEllipse.getX() + ", " + newEllipse.getY()
            + " Expected: (5.0, 15.0)");
        System.out.println("Actual Width: " + newEllipse.getWidth() + " Height: " + newEllipse.getHeight()
            + " Expected: (50.0, 30.0)");





    }
}
