/**
   Solving Problem 2. Displying a dialogue box.
   Solves 60-212 Ass #1 problem #2
   @author Ben Davidson
   @version 1.0 2018-01-22
*/

import java.net.URL;
import javax.swing.JOptionPane;
import javax.swing.ImageIcon;

public class Test
{
    public static void main(String[] args) throws Exception 
    {
        URL imageLocation = new URL("https://d13yacurqjgara.cloudfront.net/users/713952/screenshots/1935255/zelda-icons_0216_dribbble.gif");
        String message = "Assignment One : A Link to the Past";
        String title = "-- P R O B L E M 2 --";
        JOptionPane.showMessageDialog(null, message, title, JOptionPane.PLAIN_MESSAGE, new ImageIcon(imageLocation));
    }
}
