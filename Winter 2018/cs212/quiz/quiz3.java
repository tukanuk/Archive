import java.util.Scanner;

public class quiz3
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);

    String word = in.nextLine();

    for (int a = word.length() ; a > 0 ; a--)
    {
      System.out.print(word.charAt(a-1));
    }
    System.out.println("");
  }
}
