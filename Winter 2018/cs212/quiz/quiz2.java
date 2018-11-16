import java.util.Scanner;

public class quiz2
{
  public static void main(String[] args)
  {
    int x = 3;

  do {

    x--;

    if (x%2 == 1) {

      System.out.println("odd");

    }

    else {

      System.out.println("even");

    }

  } while (x <  0);
  }
}
