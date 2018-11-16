public class Pair
{
   private Object first;
   private Object second;

   public Pair(Object firstElement, Object secondElement)
   {
      first = firstElement;
      second = secondElement;
   }

   public Object getFirst()
   {
      return first;
   }
   
   public Object getSecond()
   {
      return second;
   }

   public Pair swap() {
      Pair temp = new Pair(this.getSecond(),this.getFirst());
      return temp;
   }

   public static void main(String[] args)
   {
      Pair p = new Pair("Lucky Number", 13);
      Pair q = p.swap();

      String s1 = (String) p.getFirst();

      System.out.println(s1);

      String s2 = (String) q.getFirst();

      System.out.println(s2);
   }

}
