import java.util.ArrayList;
/**
   Write a program to design an appointment calendar.
   An appointment includes the date, starting time,
   ending time, and a description; for example,

      Dentist 2016/10/1 17:30 18:30
      CS1 class 2016/10/2 08:30 10:00

   Part III - complete only the AppointmentCalendar class.
   Use the AppointmentDate and AppointmentTime classes from
   Part I and the Appointment class from Part II
*/
public class AppointmentCalendar
{
   private ArrayList<Appointment> appointments;

   /**
      Constructs an AppointmentCalendar object.
   */
   public AppointmentCalendar()
   {
      appointments = new ArrayList<>();
   }

   /**
      Adds an appointment to the calendar.
      @param a the appointment to add
   */
   public void add(Appointment a)
   {
      appointments.add(a);
   }

   /**
      Cancels (removes) an appointment from the calendar.
      @param a the appointment to cancel
   */
   public void cancel(Appointment a)
   {
      for (int i = 0; i < appointments.size(); i++)
      {
         Appointment appt = appointments.get(i);
         if (appt.equals(a))
         {
            appointments.remove(i);
            return;
         }
      }
   }

   /**
      Gets all appointment for a certain date.
      @param d the date
      @return the appointments for that day
   */
   public ArrayList<Appointment> getAppointmentsForDay(AppointmentDate d)
   {
      ArrayList<Appointment> r = new ArrayList<>();
      for (Appointment appt : appointments)
      {
         if (appt.fallsOn(d))
         {
            r.add(appt);
         }
      }
      return r;
   }
}
