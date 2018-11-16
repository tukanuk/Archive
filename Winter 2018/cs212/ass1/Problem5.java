import java.awt.Rectangle;

/**
 * Create and manipulate two rectangles
 * Solves 60-212 Assigment 1 Problem 5
 * @author Benjamin Davidson
 * @version 1.0 January 26, 2018
 */

 public class Problem5
 {
     public static void main(String[] args)
     {
        // Create two rectangles
        Rectangle rectangle1 = new Rectangle(20, 50, 15, 20);
        Rectangle rectangle2 = new Rectangle(60, 30, 30, 20);

        // Move rectangle1
        rectangle1.translate(-10, -5);

        // Test the move of the rectangle1
        System.out.println("rectangle1:");
        System.out.printf("x: %f  Expected: 10.0\n", rectangle1.getX());
        System.out.println("y: " + rectangle1.getY() + " Expected: 45.0");

        // Scale rectangle2
        rectangle2.setSize((int)rectangle2.getWidth()/2, (int)rectangle2.getHeight()*(int)2);

        // Test the scale of the rectangle2
        System.out.println("rectangle2:");
        System.out.println("width: " + rectangle2.getWidth()+ " Expected: 15.0");
        System.out.println("height: " + rectangle2.getHeight() + " Expected: 40.0");

     }
 }
