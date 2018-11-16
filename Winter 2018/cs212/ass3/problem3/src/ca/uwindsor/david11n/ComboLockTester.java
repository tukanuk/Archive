package ca.uwindsor.david11n;

import java.util.Scanner;

public class ComboLockTester
{
    public static void main(String[] args)
    {
	 ComboLock lock = new ComboLock(12, 30, 7);
	 Scanner in = new Scanner(System.in);

	 // The three combination positions
	 int dial1;
	 int dial2;
	 int dial3;

	 // Setup
	 System.out.println("Combination Lock");
	 System.out.println("----------------");

	 System.out.println("Enter a three number combination");
	 System.out.println("From 0-39");
	 System.out.println("ie (12 12 12) (0 0 0) to quit");

     // Combination loop
	 do
     {
         System.out.print("How any clicks right?: ");
         dial1 = in.nextInt();
         lock.turnRight(dial1);

         System.out.print("How any clicks left?: ");
         dial2 = in.nextInt();
         lock.turnLeft(dial2);

         System.out.print("How any clicks right?: ");
         dial3 = in.nextInt();
         lock.turnRight(dial3);

         if (lock.open()) {
             System.out.println("The lock is open!\n");
         } else {
             System.out.println("Wrong combination.\n");

         }

     } while (( (dial1 + dial2 + dial3) != 0)); // if all three inputs are zero exit the loop

     System.out.println("Goodbye");

    }
}
