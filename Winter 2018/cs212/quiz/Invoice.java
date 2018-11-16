import java.util.ArrayList;

/**

   Describes an invoice for a set of purchased products.

*/

public class Invoice {  

   private Address billingAddress;

   private ArrayList<LineItem> items;

   /**

      Constructs an invoice.

      @param anAddress the billing address

   */

   public Invoice(Address anAddress) {  

      items = new ArrayList<LineItem>();

      billingAddress = anAddress;

   }

   /**

      Adds a charge for a product to this invoice.

      @param aProduct the product that the customer ordered

      @param quantity the quantity of the product

   */

   public void add(Product aProduct, int quantity) {  

      LineItem anItem = new LineItem(aProduct, quantity);

      items.add(anItem);

   }

   /**

      Formats the invoice.

      @return the formatted invoice

   */

   public String format() {  

      .....

 }

   /**

      Computes the total amount due.

      @return the amount due

   */

   private double getAmountDue() {  

      // Complete the implementation of this method
      double totalDue;

      for (double element : items)
      {
        totalDue += LineItem.getPrice() * LineItem.quantity;
      }

      return totalDue;
      
   }

}