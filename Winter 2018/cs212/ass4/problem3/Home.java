import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.geom.Line2D;
import javax.swing.JComponent;


/**
 * Draws a single house that can be put anywhere on screen
 */
public class Home
{
    // Instance variables
    private int xLeft;
    private int yTop;

    // Constructor

    /**
     * Constructs a house with given top left corner
     * @param x the x coordiante of the top left corner
     * @param y the y coordinate of the top left corner
     */
    public Home (int x, int y)
    {
        xLeft = x;
        yTop = y;
    }

    /**
     * Draws the house
     * @param g2 the graphics context
     */
    public void draw(Graphics2D g2)
    
    {
        // // recover Graphics2D
        // Graphics2D g2 = (Graphics2D) g;

        // Main house structure
        g2.setColor(Color.RED);
        g2.fillRect(xLeft + 50, yTop + 180, 200, 150);

        // Chimmney
        g2.setColor(Color.DARK_GRAY);
        g2.fillRect(xLeft + 70, yTop + 80, 50, 100);

        // Roof
        int[] xPoints = {xLeft + 50, xLeft + 150, xLeft + 250};
        int[] yPoints = {yTop + 180, yTop + 80, yTop + 180};
        int nPoints = 3;
        g2.setColor(Color.YELLOW);
        g2.fillPolygon(xPoints, yPoints, nPoints);

        // Dormer window
        g2.setColor(Color.BLUE);
        g2.fillOval(xLeft + 125, yTop + 115, 50, 50);

        // Front door
        g2.setColor(Color.ORANGE);
        g2.fillRect(xLeft + 125, yTop + 255, 50, 75);

        // Left Window
        g2.setColor(Color.CYAN);
        g2.fillRoundRect(xLeft + 70, yTop + 200, 50, 50, 10, 10);
        
        // Right Window
        g2.setColor(Color.CYAN);
        g2.fillRoundRect(xLeft + 180, yTop + 200, 50, 50, 10, 10);

        //Shrubs
        Color colour = new Color(0, 200, 50, 255);
        g2.setColor(colour);
        g2.fillOval(xLeft + 30, yTop + 300, 50, 50);
        g2.fillOval(xLeft + 50, yTop + 290, 50, 50);
        g2.fillOval(xLeft + 70, yTop + 300, 50, 50);

        // Eve
        g2.setColor(Color.GRAY);
        g2.fillRect(xLeft + 25, yTop + 180, 250, 10);
        
        // Ground
        g2.setColor(Color.GREEN);
        g2.fillRect(xLeft, yTop + 330, 300, 30);

        // Grass
        for (int i = xLeft ; i < (xLeft + 300) ; i += 3)
        {
            g2.fillRect(i, yTop + 325, 2, 5);
        }
    }
}