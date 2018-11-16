/**
   Write a program to design an appointment calendar.
   An appointment includes the date, starting time,
   ending time, and a description; for example,

      Dentist 2016/10/1 17:30 18:30
      CS1 class 2016/10/2 08:30 10:00

   Part II - complete only the Appointment class.
*/
public class Appointment
{
   private String description;
   private AppointmentDate day;
   private AppointmentTime from;
   private AppointmentTime to;

   /**
      Constructs an Appointment object.
   */
   public Appointment(String s)
   {
      String[] tokens = s.split("\\s+");
      int descriptionCount = tokens.length - 3;
      description = tokens[0];
      for (int i = 1; i < descriptionCount; i++)
      {
         description += " " + tokens[i];
      }
      day = new AppointmentDate(tokens[tokens.length - 3]);
      from = new AppointmentTime(tokens[tokens.length - 2]);
      to = new AppointmentTime(tokens[tokens.length - 1]);
   }

   /**
      Determines if this appointment is the same as another appointment.
      @param other the other appointment
      @return true if the appointments are equal, false otherwise
   */
   public boolean equals(Object other)
   {
      if (other == null || ! (other instanceof Appointment))
      {
         return false;
      }
      Appointment b = (Appointment) other;

      return description.equals(b.description) &&
         day.equals(b.day) &&
         from.equals(b.from) &&
         to.equals(b.to);
   }

   /**
      Determines if an appointment falls on a certain day.
      @param d the appointment date
      @return true if the appointment date falls on a
          certain day false, otherwise
   */
   public boolean fallsOn(AppointmentDate d)
   {
      return day.equals(d);
   }

   /**
      Return a string representation
   */
   public String toString()
   {
      return description + " " + day + " " + from + " " + to;
   }
}
