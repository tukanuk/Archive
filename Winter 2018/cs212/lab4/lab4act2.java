import java.util.Scanner;

public class lab4act2 {
  public static void main(String[] args) {
    String[][] stars = new String[10][10];

    Scanner input = new Scanner(System.in);

    System.out.print("Input test: ");

    int n = input.nextInt();

    System.out.println(n);

    int row;
    int col;
    int largest = 0;

    //int numInputs = 1;

    // clears the array
    for (int r = 0 ; r < 10 ; r++)
    {
      for (int c = 0 ; c < 10 ; c++)
      {
        stars[r][c] = "";
      }
    }

    int i = 0;
    // sets the stars
    while (n != -1)
    {
      for (row = 10; row > (10 - n); row--)
      {
        for (col = 0; col < n; col++)
        {
          stars[row -1][i] = "*";
        }
      }

      if (n > largest)
      {
        largest = n;
      }
      i++;
      n = input.nextInt();
    }
    input.close();

    //print the array
    for (row = 10-largest ; row < 10 ; row++)
    {
      for (col = 0 ; col < 7 ; col++)
      {
        System.out.printf("%2s", stars[row][col]);
      }
      System.out.println("");
    }
    System.out.println("-DONE-");
  }
}
