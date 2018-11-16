public class lab2
{
  public static void main(String[] args)
  {

    String str = "benjamin davidson";

    System.out.println(str);
    System.out.println(str.length());

    String firstName = str.substring(0, 9);
    String lastname = str.substring(9);

    String str2 = lastname + ", " + firstName;

    System.out.println(firstName.indexOf(lastname.charAt(lastname.length()-1)));

    System.out.println("last occ of 1st char: " + firstName.lastIndexOf(lastname.charAt(0)));

    String initial = firstName.substring(0,1);
    firstName = initial.toUpperCase() + firstName.substring(1, firstName.length()-1);

    System.out.println(firstName.substring(0, 1)); // .replace(firstName.toUpperCase()));
    System.out.println("With a capital: "+ firstName);

    System.out.println(str2);


  }
}
