import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class sort
{
    public static void main (String[] args)
    {
        int[] a = {1, 7, 17, 8, 2, 5, 1, 123, -11, 245234};
        Arrays.sort(a);
        int sum=0;
        for (int i = 0; i <a.length ; i++)
        {
            sum += a[i];
            System.out.println(a[i] + " sum:" + sum +  " ");

        }

        ArrayList<String> names = new ArrayList<>();
        names.add("ben");
        names.add("adam");
        names.add("aaron");
        Collections.sort(names);
        System.out.println(names);

        int v = 6;
        String j = "ban";
        System.out.println(Arrays.binarySearch(a, v));
        System.out.println(Collections.binarySearch(names, j));
    }
}