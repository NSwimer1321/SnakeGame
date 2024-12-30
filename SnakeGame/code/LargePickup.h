#ifndef LARGEPICKUP
#define LARGEPICKUP

#include "Pickup.h"
#include "Map.h"

/**
 * The LargePickup class is a pickup object that provides 3 to the total
 * length of the snake
 */
class LargePickup : public Pickup
{
    public:
        /**
         * Creates a LargePickup object (which just creates a new Pickup Object)
         * @param x the x coordinate of the pickup object
         * @param y the y coordinate of the pickup object
         * @param color the color of the pickup object
         * @param map a reference to a map object
         */
        LargePickup(int x, int y, int color, Map* map);
};

#endif