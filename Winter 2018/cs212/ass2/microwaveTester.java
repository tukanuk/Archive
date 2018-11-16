import java.util.Scanner;

public class microwaveTester
{
    public static void main (String[] args)
    {
        // controls various statements to aid with debugging
        boolean DEBUG = false;
        
        // allows the microwave menu to be controlled
        Scanner input = new Scanner(System.in);

        // simple method to print a text menu
        menu();

        // waits for menu input
        int button = input.nextInt();

        // constructs a new microwave object called mw
        microwave mw = new microwave();

        // swtich statment to control menu input
        while (button > 0 && button < 6)
        {
            switch (button) 
            {
                case 1:
                    mw.tenSeconds();
                    break;
                
                case 2:
                    mw.powerLevel();
                    break;
                
                case 3:
                    mw.stop();
                    if (DEBUG) System.out.println("Status: " + mw.isRunning);
                    break;
                    
                case 4:
                    mw.reset();
                    break;
                
                case 5:
                    mw.start();
                    if (DEBUG)  System.out.println("Status: " + mw.isRunning);
                    break;
            
                default:
                    break;
            }

            button = input.nextInt();
        }

        input.close();
    }

    /**
     * Displays a microwave menu on screen
     * @return displays microwave menu on screen
     */
    private static void menu()
    {
        System.out.println("1. +10SEC");
        System.out.println("2. POWER");
        System.out.println("3. STOP");
        System.out.println("4. RESET");
        System.out.println("5. START");
        System.out.println("6. QUIT");
    }
}