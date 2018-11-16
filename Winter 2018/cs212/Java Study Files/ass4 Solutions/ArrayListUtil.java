import java.util.ArrayList;
/**
   Provide a static method that reverses all the elements of a
   generic arraylist.
*/
public class ArrayListUtil
{
   public static <T> void reverse(ArrayList<T> a)
   {
      // This is certainly the easiest, but I'll assume
      // that this isn't what what the question intended.
      // Collections.reverse(a)

      // This method doesn't require any shifting
      int len = a.size(); // go half way through
      for (int i = 0; i < len / 2; i++)
      {
         T temp = a.get(i);
         a.set(i, a.get(len - 1 - i));
         a.set(len - 1 - i, temp);
      }
   }
}
