package ca.uwindsor.david11n;

import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        FirstClass first = new FirstClass(6);
		EconomyClass economy = new EconomyClass(15);
		Airplane plane = new Airplane(first, economy);
        //plane.seatSetup();

        Scanner in = new Scanner(System.in);
        int choice;

        menu(plane);
        //System.out.print("\n  Enter choice: ");

        do
        {
            System.out.print("Enter choice: ");
            choice = in.nextInt();

            if (choice == 1 || choice == 2 || choice == 3)
            {
                switch (choice)
                {
                    case 1: String status = addpass(plane);
                            menu(plane);
                            if (status.equals("invalid") )  System.out.print("\n  Invalid input on add attempt.\n  Try again\n  ");
                            else if (status.equals("valid") )
                            {
                                System.out.print("\n  Passenger(s) added successfully!\n  ");
                            }
                            else if (status.equals("unable") )
                            {
                                System.out.print("\n  Unable to add passenger(s)\n  Try again with a different combination\n  ");
                            }
							break;

                    case 2: screenOutput(plane.format() );
                            menu(plane);
							break;
                    case 3: break;
                }

            }
            else
            {
                menu(plane);
                System.out.println("\n  Invalid input, Try again");
            }

            //System.out.print("  Enter choice: ");

        } while (choice != 3);


    }

    /**
     * displays a simple menu
     * @param plane takes an Airplane object used to display seating plan
     */
    private static void menu(Airplane plane) {
        clearScreen();
        screenOutput(plane.format());
        System.out.println("\n  " + ConsoleColors.BLUE_UNDERLINED + "Airline Seating Plan" + ConsoleColors.RESET);
        System.out.println("  1. Add passengers");
        System.out.println("  2. Show seating");
        System.out.print("  3. Quit\n  ");
        //System.out.print("\n  Enter choice: ");
    }

    /**
     * A submenu for the adding of passengers
     * @param plane takes an Airplane object to add the passengers to
     */
	private static String addpass(Airplane plane)
	{
		Scanner in = new Scanner(System.in);
		int tc; // number Travelling choice
		int sc; // Seating choice
        int cc; // Class choice

	    System.out.print("\n  1. First Class\n  2. Economy\n  ");
		cc = in.nextInt();
		if (cc == 1) {
            System.out.print("\n  Number travelling (1 or 2)?\n  ");
            tc = in.nextInt();
            System.out.print("\n  Seating preference?\n  1. Window\n  2. Aisle\n  ");
            sc = in.nextInt();
        }
		else if (cc == 2)
		{
			System.out.print("  Number travelling (1 to 3)?\n  ");
			tc = in.nextInt();
			System.out.print("\n  Seating preference?\n  1. Window\n  2. Aisle\n  3. Centre\n  ");
			sc = in.nextInt();
		}
		else
        {
            //System.out.println("Invalid input. Try again");
            return "invalid";
        }

		boolean addStatus = plane.addPassenger(cc, tc, sc); // the result of the adding of passengers

		if (addStatus)
        {
            //System.out.println("Passenger(s) added successfully!");
            return "valid";
        }
		else
        {
            //System.out.println("Unable to add passenger(s)\nTry again with a different combination");
            return "unable";
        }
	}

    /**
     * Outputs the seating plan to the screen
     * @param soPlane an Airplane object to display the output of
     */
	private static void screenOutput(String soPlane)
    {

        //  basic formatting for screen output
        soPlane = "\n         Seating\n        ---------\n\n           /\\\n          /  \\\n         /    \\\n        /      \\\n" + soPlane;
        soPlane = soPlane.replaceAll("W", ConsoleColors.RED + "W" + ConsoleColors.RESET);
        soPlane = soPlane.replaceAll("A", ConsoleColors.RED + "A" + ConsoleColors.RESET);
        soPlane = soPlane.replaceAll("C", ConsoleColors.RED + "C" + ConsoleColors.RESET);
        soPlane = soPlane.replaceAll("Seating", ConsoleColors.BLUE + "Seating" + ConsoleColors.RESET);

        // Displays the seating plan on screen
        System.out.println(soPlane);

    }

    /**
     * Clears the console window. Will not work for Windows command prompt.
     */
    private static void clearScreen()
    {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

}
