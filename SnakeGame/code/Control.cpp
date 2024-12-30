#include "Control.h"
#include <graphics.h>
#include <iostream>
#include <conio.h>

Control::Control(Snake* snake, Pickup* pickup)
{
    this->snake          = snake;
    curPickup            = pickup;
    score                = 0;
    hasDifficultyBeenSet = false;
}

int Control::getScore()
{
    return score;
}

void Control::addToScore(int amount)
{
    score += amount;
}

bool Control::seeIfDifficultyHasBeenSet()
{
    return hasDifficultyBeenSet;
}

int Control::getBoardSize()
{
    return curDifficulty.boardSize;
}

int Control::getGameSpeed()
{
    return curDifficulty.gameSpeed;
}

int Control::getNumBoxes()
{
    return curDifficulty.numBoxes;
}

void Control::setSnakeRef(Snake* newSnake)
{
    snake = newSnake;
}

void Control::setPickupRef(Pickup* newPickup)
{
    curPickup = newPickup;
}

void Control::setDifficulty(int boardSize, int numBoxes, int gameSpeed)
{
    curDifficulty = Difficulty(boardSize, numBoxes, gameSpeed);
}

bool Control::isGameWon()
{
    return gameWon;
}

void Control::setGameWon(bool newVal)
{
    gameWon = newVal;
}

bool Control::isGameLost()
{
    return gameLost;
}

void Control::isGameOver()
{
    if (snake->getX() >= curDifficulty.boardSize || snake->getX() < 0 || 
        snake->getY() >= curDifficulty.boardSize || snake->getY() < 0)
        gameLost = true;
    else
        gameLost = false;

    for (int i = 1; i < snake->getLength(); i++)
        if (snake->getXArr()[i] == snake->getX() && snake->getYArr()[i] == snake->getY())
            gameLost = true;
}

bool Control::didSnakeEatFood()
{
    if (snake->getX() == curPickup->getX() && snake->getY() == curPickup->getY())
    {
        score += curPickup->getGrowthSize();
        return true;
    }
    return false;
}

void Control::checkUserInput()
{
    if (_kbhit())
    {
        int recievedPlayerInput = _getch();
        int playerInput         = _getch();

        if (hasDifficultyBeenSet)
        {
            if (recievedPlayerInput == 0)
                switch(playerInput)
                {
                    case KEY_UP:
                        snake->setMoveDirection(MOVE_UP);
                        break;
                    case KEY_DOWN:
                        snake->setMoveDirection(MOVE_DOWN);
                        break;
                    case KEY_LEFT:
                        snake->setMoveDirection(MOVE_LEFT);
                        break;
                    case KEY_RIGHT:
                        snake->setMoveDirection(MOVE_RIGHT);
                        break;
                }
        }
        else
        {            
            if (recievedPlayerInput == 0)
                switch(playerInput)
                {
                    case KEY_RIGHT:
                        curDifficulty = Difficulty(400, 100, 40); // Medium Difficulty
                        hasDifficultyBeenSet = true;
                        break;
                    case KEY_LEFT:
                        curDifficulty = Difficulty(700, 400, 25); // Hard Difficulty
                        hasDifficultyBeenSet = true;
                        break;
                }
        }
    }
}