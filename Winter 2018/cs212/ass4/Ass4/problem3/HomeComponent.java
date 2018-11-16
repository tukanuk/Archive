import java.awt.Graphics2D;
import java.awt.Graphics;
import javax.swing.JComponent;

import javafx.scene.paint.Color;

/**
 * Draws four homes in a row
 */
public class HomeComponent extends JComponent
{
    public void paintComponent(Graphics g)
    {
        
        // Recover Graphics2D
        Graphics2D g2 = (Graphics2D) g;

        Home home1 = new Home(0, 120); //left
        Home home2 = new Home(300, 120); // left middle
        Home home3 = new Home(600, 120); // right middle
        Home home4 = new Home(900, 120); // right

        home1.draw(g2);
        home2.draw(g2);
        home3.draw(g2);
        home4.draw(g2);
    }
}