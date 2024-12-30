#include "Pickup.h"
#include <graphics.h>
#include <iostream>
#include <math.h>

Pickup::Pickup(int x, int y, int color, int growth, Map* map)
{
    this->map   = map;
    this->color = color;
    this->x     = x;
    this->y     = y;
    growthSize  = growth;
}

Pickup::Pickup()
{
    color      = BLACK;
    x          = 0;
    y          = 0;
    growthSize = 0;
}

int Pickup::getX()
{
    return x;
}

int Pickup::getY()
{
    return y;
}

void Pickup::drawPickup()
{
    // Draws a circle of the specificed color at the specified location to denote a pickup object
    int length = map->getMapSize() / sqrt(map->getNumBoxes());
    setcolor(color);
    circle(x, y, length / 2); 
    setfillstyle(SOLID_FILL, color);
    floodfill(x, y, color);
}

int Pickup::getGrowthSize()
{
    return growthSize;
}