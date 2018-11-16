import java.io.PrintWriter;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class Quiz9 {
    public static void main (String [] args) throws FileNotFoundException 
    { 
        File inputFile = new File("input.txt");
        Scanner in = new Scanner (inputFile);

        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        while (in.hasNextInt() )
        {
            out.println(in.nextInt() + in.nextInt() );
        }
        
        in.close();
        out.close();

    }
}