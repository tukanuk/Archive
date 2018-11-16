public class lab2act2
{
   public static void main (String[] args)
   {
       book nBook = new book("Tomorrow");

       nBook.setPages(200);

       System.out.println("the book is called: " + nBook.getName());

       System.out.println(nBook.getNumPages());

   }

}
