import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;



/**
 * This program demonstrates the implementation of NumberFormatter in 
 * DefaultFormatter, FormatTester, DecimalsSeperatorFormatter and AccountingFormatter
 * classes
 */
public class FormatTester
{
    public static void main(String[] args) throws FileNotFoundException
    {
        int[] num = new int[4];
        int i = 0;

        // Prepare to read the input file
		File inputFile = new File("Numbers.txt");
        Scanner in = new Scanner(inputFile);

        while(in.hasNextInt() )
        {
            num[i++] = in.nextInt();
        }

        for (int element : num)
        {
            System.out.println(element);
        }
        in.close();

        // Output File
        File outputFile = new File("FormattedNumbers.txt");
        PrintWriter out = new PrintWriter(outputFile);
    
        // Default Formatter 
        NumberFormatter dF = new DefaultFormatter();
        System.out.printf("             Default Format: ");
        for (int element : num)
        {
            System.out.print(dF.format(element) + " ");
        }
        System.out.println("");

        // DecimalSeparatorFormatter
        NumberFormatter dsF = new DecimalSeparatorFormatter();
        System.out.print("Decimal Separator Formatter: ");
        out.printf("Decimal Separator Formatter: ");
        for (int element : num)
        {
            // String test = dsF.format(element);
            System.out.print(dsF.format(element) + " ");
            out.printf(dsF.format(element) + " ");
        }
        System.out.println("");
        out.printf("\n");

        // Accounting Format
        NumberFormatter aF = new AccountingFormatter();
        System.out.print("          Accounting Format: ");
        out.printf("          Accounting Format: ");
        for (int element : num)
        {
            // String test = dsF.format(element);
            System.out.print(aF.format(element) + " ");
            out.printf(aF.format(element) + " ");
        }
        System.out.println("");
        out.printf("\n");

          // Base n Format
          int base = 2;
          NumberFormatter bF = new BaseFormatter(base);
          System.out.print("              Base " + base + " Format: ");
          out.printf("              Base " + base + " Format: ");
          for (int element : num)
          {
              System.out.print(bF.format(element) + " ");
              out.printf(bF.format(element) + " ");
          }
          System.out.println("");
          out.printf("\n");
          
          // Base n Format
          base = 8;
          bF = new BaseFormatter(base);
          System.out.print("              Base " + base + " Format: ");
          out.printf("              Base " + base + " Format: ");
          for (int element : num)
          {
              System.out.print(bF.format(element) + " ");
              out.printf(bF.format(element) + " ");
          }
          System.out.println("");
          out.printf("\n");
          
          // Base n Format
          base = 16;
          bF = new BaseFormatter(base);
          System.out.print("             Base " + base + " Format: ");
          out.printf("             Base " + base + " Format: ");
          for (int element : num)
          {
              System.out.print(bF.format(element) + " ");
              out.printf(bF.format(element) + " ");
          }
          System.out.println("");        
          out.printf("\n");     
          
          out.close();
    }
}