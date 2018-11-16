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
public class AppointmentDate
{
   private int year;
   private int month;
   private int day;
   private static final int[] DAYS = {31, 29, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};

   /**
    * Representation of a bad date.
    */
   public static final AppointmentDate BAD_DATE = new AppointmentDate("-1/-1/-1");
   
   /**
      Constructs an AppointmentDate object.
      @param d the date
   */
   public AppointmentDate(String d)
   {
      Scanner in = new Scanner(d);
      in.useDelimiter("/");
      try
      {
         year = in.nextInt();
         month = in.nextInt();
         day = in.nextInt();
         if (month < 1 || month > 12) { throw new RuntimeException(); }
         if (day < 1) { throw new RuntimeException(); }
         if (day > DAYS[month - 1]) { throw new RuntimeException(); }
         if (month == 2 && ! isLeapYear(year) && day > 28) { throw new RuntimeException(); }
      }
      catch (Exception e)
      {
         year = -1;
         month = -1;
         day = -1;
      }
   }

   /**
      Determines if dates are equal.
      @param the other date
      @return true if the dates are equal, false otherwise
   */
   public boolean equals(Object other)
   {
      if (other == null || ! (other instanceof AppointmentDate)) 
      { 
         return false;
      }
      AppointmentDate b = (AppointmentDate) other;
      return year == b.year && month == b.month && day == b.day;
   }

   /**
      Prints a string representation of the date.
      @return the date
   */
   public String toString()
   {
      return year + "/" + month + "/" + day;
   }
   
   // From "The Art and Science of Java" by Roberts.
   private static boolean isLeapYear(int year)
   {
      return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
   }
}
