public class Pizza {

    private String size;

    private double baseCost;

    private int numTops;



    // Constructor

    public Pizza (String s, double c, int n){




    }



    // Get the value of size

    public String getSize(){

        return size;

    }



    // Get the value of baseCost

    public double getBaseCost(){

        return baseCost;

    }



    // Get the value of numTops

    public int getNumTops(){

      return numTops;

    }


double c
    // Modify the value of size

    public void setSize(String s){

      size = s;

    }



    // Modify the value of baseCost

    public void setBaseCost(double c){

      baseCost = c;

    }



    // Modify the value of numTops

    public void setNumTops(int n){

      numTops = n;

    }



    // Calculate and return the total cost of a pizza.

    // The total cost is the base price,

    // plus $2.50 for each topping.

    public double getTotalCost(){

      return baseCost + (numTops * 2.5);

    }

}
