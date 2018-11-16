import java.awt.Graphics2D;
import javax.swing.JComponent;
import java.awt.Rectangle;
import java.awt.geom.Ellipse2D;
import java.awt.Color;
import java.awt.Graphics;

public class RectangleComponent extends JComponent
{
    public void paintComponent(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        Rectangle box = new Rectangle(5, 10, 20, 30);
        g2.draw(box);

        box.translate(15, 25);

        g2.draw(box);

        Ellipse2D.Double ellipse = new Ellipse2D.Double(100,100,100,100);

        g2.setColor(Color.RED);
        g2.fill(ellipse);

        g2.drawString("Tony the tiger", 50, 100);

    }
}
