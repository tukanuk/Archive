import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Reads a CVS File
 */
public class CSVReader //throws FileNotFoundException
{
    /* Instance Variables */
    private String filename;
    private ArrayList<List<String>> csvList = new ArrayList<List<String>>();

    /* Constructors */
    
    /**
     * Reads a file with the given filename
     * @param filename the name of the file to be opened
     */
    public CSVReader (String filename) //throws FileNotFoundException
    {
        this.filename = filename;
        try
        {
            parseFile();
        }
        catch (FileNotFoundException exception)
        {
            System.out.println("Error parsing file. Check file name and type");
            exception.printStackTrace();
        }
    }
    

    /* Methods */

    private void parseFile() throws FileNotFoundException
    {
        Scanner in = new Scanner(new File(filename));
        while (in.hasNext())
        {
            List<String> newLine = parseLine(in.nextLine());
            csvList.add(newLine);
        }

        in.close();
        // System.out.println(csvList);
    }

    /**
     * Parse a line of a CSV file
     * @param csvLine a line of a CSV file
     */
    public static List<String> parseLine(String csvLine)
    {
        List<String> parsedLine = new ArrayList<>();

        // if line is empty return and empty array list
        if (csvLine == null && csvLine.isEmpty())
        {
            return parsedLine;
        }

        StringBuffer cValue = new StringBuffer();
        
        // boolean flags to deterimine the format of the CSV lin
        boolean inQuotes = false;
        boolean doubleQuotePresent = false;
        // boolean tripleQuotePresent = false;

        char[] charLine = csvLine.toCharArray();

        for (char ch : charLine)
        {
            if (inQuotes)
            {
                // firstQuotePresent = true;

                if (ch == '\"')
                {
                    inQuotes = false;
                    doubleQuotePresent = true;
                }

                else
                {
                    cValue.append(ch);
                }
            }

            else
            {
                if (ch == '\"')
                {
                    inQuotes = true;
                    if (doubleQuotePresent)
                    {
                        doubleQuotePresent = false;
                        cValue.append(ch);
                    }
                }

                else if (ch == ',')
                {
                    parsedLine.add(cValue.toString());
                    cValue = new StringBuffer();
                    doubleQuotePresent = false;

                }

                else if (ch == '\n') // end of record
                {
                    break;
                }
                else
                {
                    cValue.append(ch);
                }

            }

        }

        parsedLine.add(cValue.toString());
        return parsedLine;
    }

    /**
     * Returns the number of lines in the CSV file
     */
    int numberOfRows()
    {
        int rowCount = csvList.size();
        return rowCount;
    }

    /**
     * Returns the number of fields in a particular row
     */
    int numberOfFields(int row)
    {
        int fieldCount = csvList.get(row).size();

        return fieldCount;
    }

    /**
     * Returns the field in a particualr row and column
     */
    String field(int row, int col)
    {
        String field = csvList.get(row).get(col);

        return field;
    }
}