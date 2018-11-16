import java.util.Scanner;
/**
   Write a program to design an appointment calendar.
   An appointment includes the date, starting time,
   ending time, and a description; for example,

      Dentist 2016/10/1 17:30 18:30
      CS1 class 2016/10/2 08:30 10:00

   Part I - complete only the AppointmentDate and
   AppointmentTime classes. Use the format -1/-1/-1 for
   a bad date and -1:-1 for a bad time.
*/
public class AppointmentTime
{
   private int hours;
   private int minutes;

   public static final AppointmentTime BAD_TIME = new AppointmentTime("-1:-1");

   /**
      Constructs an AppointmentTime object
      @param t the time
   */
   public AppointmentTime(String t)
   {
      Scanner in = new Scanner(t);
      in.useDelimiter(":");
      try
      {
         hours = in.nextInt();
         minutes = in.nextInt();
         if (hours < 0 || hours > 23) { throw new RuntimeException(); }
         if (minutes < 0 || minutes > 59) { throw new RuntimeException(); }
      }
      catch (RuntimeException e)
      {
         hours = minutes = -1;
      }
   }

   /**
      Determines if the appointment times are equal.
      @param other the other time
      @return true if the appointment times are equal,
           false otherwise
   */
   public boolean equals(Object other)
   {
      if (other == null || ! (other instanceof AppointmentTime))
      {
         return false;
      }
      AppointmentTime b = (AppointmentTime) other;
      return hours == b.hours && minutes == b.minutes;
   }

   /**
      Prints a string representation of the time.
      @return the time
   */
   public String toString()
   {
      return String.format("%02d:%02d", hours, minutes);
   }
}
