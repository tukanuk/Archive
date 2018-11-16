import javax.swing.JFrame;

public class HomeViewer
{
    public static void main (String[] args)
    {
        JFrame frame = new JFrame();
        frame.setSize(1200,500);
        frame.setTitle("Four little houses all in a row");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Home component = new Home();
        HomeComponent component = new HomeComponent();
        frame.add(component);
        
        frame.setVisible(true);
    }
}