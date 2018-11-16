import java.util.Scanner;

public class sample {

    public static void main(String[] args) {

        Scanner userInput = new Scanner(System.in);

        System.out.println(
                "Enter 1 for Default Formatting; 2 for Decimal Separator Formatting; 3 for Accounting Formatting; 4 for Base Formatting;Any others to Quit ");

        int decissionNumber = userInput.nextInt(); //getting user input for decission

        if (decissionNumber == 1) {

            System.out.println("Enter Number to Default Format: ");

            int number = userInput.nextInt(); //getting user input for number to format

            DefaultFormatter defaultFormatter = new DefaultFormatter();

            String formattedNumber = defaultFormatter.format(number);

            System.out.println("Number after Default Format: " + formattedNumber);

        } else if (decissionNumber == 2) {

            System.out.println("Enter Number to Decimal Separator Format: ");

            int number = userInput.nextInt(); //getting user input for number to format

            DecimalSeparatorFormatter decimalSeparatorFormatter = new DecimalSeparatorFormatter();

            String formattedNumber = decimalSeparatorFormatter.format(number);

            System.out.println("Number after Decimal Separator Format: " + formattedNumber);

        } else if (decissionNumber == 3) {

            System.out.println("Enter Number to Accounting Format: ");

            int number = userInput.nextInt(); //getting user input for number to format

            AccountingFormatter accountingFormatter = new AccountingFormatter();

            String formattedNumber = accountingFormatter.format(number);

            System.out.println("Number after Accounting Format: " + formattedNumber);

        } else if (decissionNumber == 4) {

            System.out.println("Enter Number to Base Bormat: ");

            int number = userInput.nextInt(); //getting user input for number to format

            System.out.println("Enter Base (2 to 36): ");

            int base = userInput.nextInt(); //getting user input for Base to format

            BaseFormatter baseFormatter = new BaseFormatter(base);

            String formattedNumber = baseFormatter.format(number);

            System.out.println("Number after Base Format: " + formattedNumber);

        } else {

            System.exit(0);

        }

        userInput.close();

    }

}