//package ca.uwindsor.david11n;

import java.util.Random;

public class TerrainMap
{
    /** private instance variables **/
    private final int WIDTH;
    private final int LENGTH;
    private final int MINHEIGHT = 0;
    private final int MAXHEIGHT = 10;

    private int[][] terrain;
    private int lowestPoint;
    private int highestPoint;

    private Random generator;

    /* constructors */

    public TerrainMap()
    {
        WIDTH = 4;
        LENGTH = 4;

        terrain = new int[WIDTH][LENGTH];

        lowestPoint = 0;
        highestPoint = 0;
        generator = new Random();
    }

    public TerrainMap(int width, int length)
    {
        WIDTH = width;
        LENGTH = length;

        terrain = new int[WIDTH][LENGTH];

        lowestPoint = 0;
        highestPoint = 0;
        generator = new Random();
    }

    /* Methods */

    /** createTerrainMap creates random terrain map with values between MINHEIGHT and MAXHEIGHT
     *
     */
    public void createTerrainMap()
    {
        for (int w = 0 ; w < WIDTH ; ++w)
        {
            for (int l = 0 ; l < LENGTH ; ++l)
            {
                terrain[w][l] = MINHEIGHT + generator.nextInt(MAXHEIGHT + 1);
            }
        }
    }

    /** createTerrainMap creates random terrain map with values between MINHEIGHT and MAXHEIGHT
     * @param map an array of values that are used to populate the terrain map
     */

    public void createTerrainMap(int[] map)
    {
        int c = 0; //counter for the map array input

        for (int w = 0 ; w < WIDTH ; ++w)
        {
            for (int l = 0; l < LENGTH ; ++l)
            {
                terrain[w][l] = map[c];
                c++;
            }
        }
    }

    /**
     * lowPoint finds the lowest point on the terrain map
     * @Return the int value of lowest point
     */
    public int lowPoint()
    {
        // to keep the lowest point from getting stuck on 0
        lowestPoint = highPoint();

        for (int w = 0 ; w < WIDTH ; ++w)
        {
            for (int l = 0 ; l < LENGTH ; ++l)
            {
                if (terrain[w][l] < lowestPoint )
                {
                    lowestPoint = terrain[w][l];
                }
            }
        }

        return lowestPoint;
    }

    /**
     * highPoint find the highest point on the terrain map
     * @Return the int value of the highest point
     */
    public int highPoint()
    {
        for (int w = 0 ; w < WIDTH ; ++w)
        {
            for (int l = 0 ; l < LENGTH ; ++l)
            {
                if (terrain[w][l] > highestPoint )
                {
                    highestPoint = terrain[w][l];
                }
            }
        }

        return highestPoint;
    }

    /**
     * floodMap displays a flood map marking the flooded areas with * and marking non flooded areas with -
     * @param level the int level to which the water has risen
     */
    public void floodMap(int level)
    {
        System.out.println("Flood map for water level of " + level);
        for (int w = 0 ; w < WIDTH ; ++w)
        {
            for (int l = 0 ; l < LENGTH ; ++l)
            {
                if (terrain[w][l] <= level)
                {
                    System.out.printf("  *");
                }
                else
                {
                    System.out.print("  -");
                }
            }

            System.out.println("");

        }

        System.out.println("");
    }

    /**
     * printMap displays the terrain map
     */
    public void printMap()
    {
        for (int w = 0 ; w < WIDTH ; ++w)
        {
            for (int l = 0 ; l < LENGTH ; ++l)
            {
                System.out.printf("%3d", terrain[w][l]);
            }

            System.out.println("");

        }

        System.out.println("");
    }


}