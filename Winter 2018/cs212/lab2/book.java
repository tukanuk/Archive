/**
    A book has a name, author, year published and a certain
    number of pages.
*/

public class book
{
    // private instance variables
    private String bookName;
    private String bookAuthor;
    private int yearPublication;
    private int numPages;

    // Constructors
    public book (String name)
    {
        bookName = name;
    }

    public book (String bookName, String author)
    {

    }

    // Methods

    /**
     * Get the name of the book
     * @param none
     * @return bookName
     */
    public String getName()
    {
        return bookName;
    }

    /**
     * Get the author of the book
     * @param none
     * @return author
     */
    public String getAuthor()
    {
        return bookAuthor;
    }

    /** 
     * Returns the year of publication
     * @param none
     * @return yearPublication
     */
    public int getYearPublication()
    {
        return yearPublication;
    }

    /**
     * Gets the number of pages
     * @param none
     * @return numPages
     */
    public int getNumPages()
    {
        return numPages;
    }

    /**
     * Set the name of the book
     * @param name allows the setting and changing of the name
     */
    public void setName(String name)
    {
        bookName = name;
    }

    /** 
     * Set the author of the book
     * @param author the author of the book
     */
    public void setAuthor(String author)
    {
        bookAuthor = author;
    }

    /**
     * Set the year of publication
     * @param year sets the year of publication
     * @return void
     */
    public void setYearPublication(int year)
    {
        yearPublication = year;
    }

    /**
     * Set the number of pages
     * @param numberPages
     * @return none
     */
    public void setPages(int pages)
    {
        numPages = pages;
    }
}
