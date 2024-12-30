#include "Map.h"
#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>

Map::Map(int mapSize, int startX, int startY, int boxes)
{
    this->size   = mapSize;
    this->startX = startX;
    this->startY = startY;
    numBoxes     = boxes;
    xArr         = new int[numBoxes];
    yArr         = new int[numBoxes];

    setupMap();
}

int Map::getXAtIndex(int index)
{
    return xArr[index];
}

int Map::getYAtIndex(int index)
{
    return yArr[index];
}

int Map::getNumBoxes()
{
    return numBoxes;
}

int Map::getMapSize()
{
    return size;
}

void Map::setupMap()
{
    int pos = 0;
    int length = size / sqrt(numBoxes);
    for (int i = 0; i < sqrt(numBoxes); i++)
        for (int j = 0; j < sqrt(numBoxes); j++)
        {
            xArr[pos] = j * length + (length / 2);
            yArr[pos] = i * length + (length / 2);
            pos++;
        }
}

void Map::drawEmptyMap()
{
    setcolor(GREEN);
    line(startX, startY, startX + size, startY);
    line(startX, startY, startX, startY + size);
    line(startX + size, startY, startX + size, startY + size);
    line(startX, startY + size, startX + size, startY + size);

    for (int i = 1; i < size / (size / sqrt(numBoxes)); i++)
    {
        line(startX + ((size / sqrt(numBoxes)) * i), startY, startX + ((size / sqrt(numBoxes)) * i), startY + size);
        line(startX, startY + ((size / sqrt(numBoxes)) * i), startX + size, startY + ((size / sqrt(numBoxes)) * i));
    }
}