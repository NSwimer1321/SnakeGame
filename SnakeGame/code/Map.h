#ifndef MAPCLASS
#define MAPCLASS

#include <stdio.h>
#include <list>
using std::list;

/**
 * The Map class denotes each of the possible boxes that the player can
 * traverse and occupy and each of the possible boxes that a Pickup object can occupy
 */
class Map
{
    public:
        // Methods
        /**
         * Creates a new map using the given map size (denotes one side of the map), the given
         * starting x and y (the point where the map begins), as well as the number of boxes 
         * that will appear on screen
         * @param mapSize the size of one side of the map
         * @param x the starting x coordinate of the map
         * @param y the starting y coordinate of the map
         * @param boxes the number of boxes that will appear on screen
         */
        Map(int mapSize, int x, int y, int boxes);

        /**
         * Retrieves and returns the x coordinate of the box at the desired index
         * @param index the desired index
         */
        int getXAtIndex(int index);

        /**
         * Retrieves and returns the y coordinate of the box at the desired index
         * @param index the desired index
         */
        int getYAtIndex(int index);

        /** 
         * Retrieves and returns the number of boxes on screen 
         */
        int getNumBoxes();
        
        // Drawing
        /**
         * Draws the borders of the Map as well as each of the boxes on screen
         */
        void drawEmptyMap();

        int getMapSize();

    private:
        // Fields
        int size; // The size of one side of the board (the length and width of the board are the same)
        int startX; // The lowest possible (valid) position on the board
        int startY; // The lowest possible (valid) position on the board
        int numBoxes; // The number of boxes on screen
        int* xArr; // The x position of the center of each box on screen
        int* yArr; // The y position of the center of each box on screen (xArr[i] and yArr[i] refer to the same box)

        //Helper methods
        /**
         * Sets each value in the xArr and yArr to the x and y position respectively of each
         * box that appears on screen.
         */
        void setupMap();
        
};

#endif