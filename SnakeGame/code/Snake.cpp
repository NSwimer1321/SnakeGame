#include <graphics.h>
#include <cmath>
#include "Snake.h"
#include <iostream>

Snake::Snake(Map* map)
{
    this->map = map;
    x = map->getXAtIndex((map->getNumBoxes() / 2) - 1);
    y = map->getYAtIndex((map->getNumBoxes() / 2) - 1);
    numPieces = 3;
    curMoveDir = MOVE_UP;

    xArr = new int[map->getNumBoxes()];
    yArr = new int[map->getNumBoxes()];

    int squareLength = map->getXAtIndex(1) - map->getXAtIndex(0);
    for (int i = 0; i < map->getNumBoxes(); i++)
    {
        if (i < numPieces)
        {
            xArr[i] = map->getXAtIndex((map->getNumBoxes() / 2) - 1);
            yArr[i] = map->getYAtIndex((map->getNumBoxes() / 2) - 1) + (i * squareLength);
        }
        else
        {
            xArr[i] = map->getNumBoxes() * map->getNumBoxes();
            yArr[i] = map->getNumBoxes() * map->getNumBoxes();
        }
    }
}

int Snake::getX()
{
    return x;
}

int Snake::getY()
{
    return y;
}

int Snake::getLength()
{
    return numPieces;
}

void Snake::addToLength(int amount)
{
    numPieces += amount;
}

int* Snake::getXArr()
{
    return xArr;
}

int* Snake::getYArr()
{
    return yArr;
}

void Snake::setMoveDirection(int newDir)
{
    // Check if the player is trying to reverse directions
    if ((curMoveDir == MOVE_UP && newDir == MOVE_DOWN) ||
    (curMoveDir == MOVE_DOWN && newDir == MOVE_UP) ||
    (curMoveDir == MOVE_LEFT && newDir == MOVE_RIGHT) ||
    (curMoveDir == MOVE_RIGHT && newDir == MOVE_LEFT)) 
    {
        return; // Ignore invalid direction change
    }
    
    curMoveDir = newDir;
}

void Snake::moveSnake()
{
    int squareLength = map->getXAtIndex(1) - map->getXAtIndex(0);
    int prevX, prevY;
    int tempX, tempY;

    // Adjusts the x (or y) value of the head of the Snake based on the move direction
    // selected by the player
    switch (curMoveDir)
    {
        case MOVE_UP:
            y -= squareLength;
            break;
        case MOVE_DOWN:
            y += squareLength;
            break;
        case MOVE_LEFT:
            x -= squareLength;
            break;
        case MOVE_RIGHT:
            x += squareLength;
            break;
    }

    // Sets the prevX and prevY value to the current value of the head of the snake.
    // Then update the value of the head of the snake
    prevX = xArr[0];
    prevY = yArr[0];
    xArr[0] = x;
    yArr[0] = y;

    // Goes through each piece of the Snake and updates it's location to
    // the previous location of the piece in front of it
    for (int i = 1; i < numPieces; i++)
    {
        tempX = xArr[i];
        tempY = yArr[i];
        xArr[i] = prevX;
        yArr[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }
}

void Snake::drawSnake()
{
    int length = map->getMapSize() / sqrt(map->getNumBoxes());
    for (int i = 0; i < numPieces; i++)
    {
        setcolor(WHITE);
        circle(xArr[i], yArr[i], length / 2);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(xArr[i], yArr[i], WHITE);
    }
}