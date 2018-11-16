import java.util.ArrayList;

public class Parse
{
    /**
     * Parses NumberFormatter values of the given object
     * @param object an a
     */
    public static String DisplayFormat(ArrayList<Integer> objects)
    {
        System.out.println("Default Format: ");
        for (Integer element : objects)
        {
            System.out.print(DefaultFormatter.format(5) );

        }
        return objects.format(12345);
    }
}