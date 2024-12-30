#ifndef PICKUPCLASS
#define PICKUPCLASS

#include "Map.h"

/**
 * The Pickup class denotes any object that when a Snake object collides with it
 * a certain amount is added to the total length of the Snake.
 */
class Pickup
{
    public:
        // Methods
        /**
         * Creates a new Pickup object
         * @param x The x coordinate of the Pickup object
         * @param y The y coordinate of the Pickup object
         * @param color The color of the Pickup object
         * @param growth The amount that the snake grows upon collision
         */
        Pickup(int x, int y, int color, int growth, Map* map);

        /**
         * Creates an empty Pickup object where the color is Black and the x, y, and color
         * variables are set to 0
         */
        Pickup();

        /**
         * Retrieves and returns the growthSize variable
         */
        int getGrowthSize();

        /**
         * Retrieves and returns the x coordinate of the Pickup object
         */
        int getX();

        /**
         * Retrieves and returns the y coordinate of the Pickup object
         */
        int getY();

        // Drawing
        /**
         * Draws the Pickup object onto the screen
         */
        void drawPickup();

    private:
        // Fields
        Map* map; // A reference to the Map this object will be on
        int x; // The x coordinate of the Pickup object
        int y; // The y coordinate of the Pickup object
        int growthSize; // The amount that gets added to the Snake length
        int color; // The color of the Pickup object
};

#endif