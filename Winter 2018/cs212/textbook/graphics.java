import javax.swing.JComponent;
import javax.swing.JFrame;

public class graphics
{
    public static void main (String[] args)
    {
        JFrame frame = new JFrame();

        frame.setSize(300, 400);
        frame.setTitle("An empty frame");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setLocation(500, 500);

    }
}

