//package ca.uwindsor.david11n;

public class Main {

    public static void main(String[] args)
    {
        // Create a map with the no parameter constructor. Defaults to a 4x4 map.
        TerrainMap map = new TerrainMap();

        // Generate a terrain map using no parameter method. Defaults to random generation.
        System.out.println("\nRandom Terrain Map\n");
        map.createTerrainMap();
        map.printMap();
        map.floodMap(5);

        System.out.println(map.lowPoint() + " is the height of the lowest point on the map");
        System.out.println(map.highPoint() + " is the height of the highest point on the map");
        System.out.println("");

        // Create a map with user defined size
        System.out.println("\nUser Defined Size and Height Terrain Map\n");
        TerrainMap userMap = new TerrainMap(5,5);

        // An 1D array of user data for terrain height. Shown as 2D for ease of input.
        int[] userTerrain = {1,  2,  3,  4,  5,
                             6,  7, -8,  9, 10,
                            11, 15, 14, 11,  8,
                             7,  6,  4,  4,  4,
                             3,  6,  4,  4,  4};

        // Generate a terrain map with user supplied data.
        userMap.createTerrainMap(userTerrain);
        userMap.printMap();
        userMap.floodMap(4);

        System.out.println(userMap.lowPoint() + " is the height of the lowest point on the map");
        System.out.println(userMap.highPoint() + " is the height of the highest point on the map");
        System.out.println("");


    }
}
