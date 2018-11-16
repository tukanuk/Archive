import java.util.ArrayList;
import java.util.Scanner;

public class AppointmentTester 
{
    public static void main(String[] args)
    {
        ArrayList<Appointment> appointmentList = new ArrayList<>();
        
        appointmentList.add(new Daily("Go to work") );
        appointmentList.add(new Daily("Brush teeth") );
        appointmentList.add(new Daily("Have a shower") );
        appointmentList.add(new OneTime(1, 1, 2018, "Go the doctors") );
        appointmentList.add(new OneTime(1, 1, 2020, "Go to space") );
        appointmentList.add(new OneTime(1, 3, 2018, "Get oil change") );
        appointmentList.add(new Monthly(1,"Perform month end") );
        appointmentList.add(new Monthly(23, "Go to dinner") );
        appointmentList.add(new Monthly(4, "Visit friend") );
        appointmentList.add(new Monthly(3, "Brush teeth") );
        appointmentList.add(new Monthly(5, "Get an oil change"));

        System.out.print("Date (d/m/y): ");
        Scanner in = new Scanner(System.in);
        String date = in.next();
        Scanner parse = new Scanner(date).useDelimiter("/");

        int day = parse.nextInt();
        int month = parse.nextInt();
        int year = parse.nextInt();

        in.close();
        parse.close();

        

        System.out.println("\n***Here's your schedule for " + day + "/" + month + "/" + year + "***");
        
        for (Appointment element : appointmentList)
        {
            //System.out.println("Enhanced: " + element.da);
            // System.out.println("EN: Does " + element +  " occur on " + day + " " + month + " " + year + "?: " + element.occursOn(day, month, year) );    
            // System.out.println();

            if (element.occursOn(day, month, year) == 1 )
            {
                System.out.println("   -> " + element.description);
            }

        }

        // System.out.println();
        // System.out.println("Tests:");

        // System.out.println("[YES] Does " + app1.description + " occur on " + day + " " + month + " " + year + "?: " + app1.occursOn(day, month, year) );
        // System.out.println("[YES] Does " + app2.description + " occur on " + day + " " + month + " " + year + "?: " + app2.occursOn(day, month, year) );
        // System.out.println("[YES] Does " + app3.description + " occur on " + day + " " + month + " " + year + "?: " + app3.occursOn(day, month, year) );       
        // System.out.println("[NO] Does " + app4.description + " occur on " + day + " " + month + " " + year + "?: " + app4.occursOn(day, month, year) );       
        // System.out.println("[NO] Does  " + app5.description + " occur on " + day + " " + month + " " + year + "?: " + app5.occursOn(day, month, year) );       
        // System.out.println("[YES] Does " + app6.description + " occur on " + day + " " + month + " " + year + "?: " + app6.occursOn(day, month, year) );       
    }
}