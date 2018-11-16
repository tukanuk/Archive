import java.util.Scanner;

public class scanner
{
  public static void main(String[] args)
  {
    Scanner in  = new Scanner(System.in);

    System.out.print("Input test: ");

    int n = in.nextInt();

    System.out.print(n);

    in.close();

  }
}
