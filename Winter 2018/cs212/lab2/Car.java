import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

/**
A car shape that can be positioned anywhere on the screen.
*/
public class Car 
{
    private int xLeft;
    private int yTop;

    /**
    Constructs a car with a given top left corner.
    @param x the x coordinate of the top left corner
    @param y the y coordinate of the top left corner
    */
    public Car(int x, int y)
    {
       xLeft = x;
        yTop = y;
    }

    /**
    Draws the car.
    @param g2 the graphics context
    */
    public void draw(Graphics2D g2)
    {
        Rectangle body = new Rectangle(xLeft, yTop + 10, 60, 10);
        Ellipse2D.Double frontTire
           = new Ellipse2D.Double(xLeft + 10, yTop + 20, 10, 10);
        Ellipse2D.Double rearTire
            = new Ellipse2D.Double(xLeft + 30, yTop + 20, 10, 10);
    }
}