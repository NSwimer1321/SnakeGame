#ifndef NORMALPICKUP
#define NORMALPICKUP

#include "Pickup.h"
#include "Map.h"

/**
 * The NormalPickup class is a Pickup object that provides 1 to the total
 * length of the snake.
 */
class NormalPickup : public Pickup
{
    public:
        /**
         * Creates a new NormalPickup object (which just creates a new Pickup object)
         * @param x the x coordinate of the Pickup object
         * @param y the y coordinate of the Pickup object
         * @param color the color of the Pickup object
         * @param map a reference to a Map object
         */
        NormalPickup(int x, int y, int color, Map* map);
};

#endif