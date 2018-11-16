public class lab4act1
{
    public static void main(String[] args)
    {
        int[] arrayTest = {1, 4, 9, 16, 19};

        System.out.println("Original array: " + arrayTest[2]);

        System.out.println("Reversed array: ");

        int[] rarray = arrayReverse(arrayTest);

        int i;

        for (i = 0 ; i < arrayTest.length ; i++)
        {
            System.out.print(" " + rarray[i]);
        }

        System.out.println(" Done.");
    }

    public static int[] arrayReverse(int[] a)
    {
        int[] aReversed = new int[10];
        int c = 0;
        int i;

        System.out.printf("a length: %d ", a.length - c);

        for (i = 0 ; i < a.length; i++)
        {

            aReversed[i] = a[a.length - 1 - c];
            c++;
        }

        return aReversed;
    }
}
