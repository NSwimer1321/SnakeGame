/**
 * Author- Nathaniel Taylor
 * Description- The player uses the arrow keys to move around a chain of white circles (the snake) to collect
 * green (or blue) circles to increase the snake's size. If the snake collides with itself, the game will be lost.
 * If the player makes a snake so large that it takes up the entire board, then the game will be won.
 */

#include <conio.h>
#include <graphics.h>
#include <iostream>
#include "Map.h"
#include "Snake.h"
#include "NormalPickup.h"
#include "LargePickup.h"
#include "Control.h"

int main()
{
    int delayTime;
    int pickupsUntilLargePickup = 5;
    int width, height, page, random;
    width = height = 400;
    bool validPosition = false;


    initwindow(width, height, "Set Difficulty");
    Control* cont  = new Control(nullptr, nullptr);

    page = 0;
    while(!cont->seeIfDifficultyHasBeenSet()) // Draw the difficulty screen
    {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        cont->checkUserInput();

        char firstLine[]   = "For Medium Difficulty: Press -> arrow";
        char secondLine[]  = "For Hard Difficulty: Press <- arrow  ";
        outtextxy(width/4, height/3, firstLine);
        outtextxy(width/4, height/3 + 50, secondLine);

        page = 1-page;
    }

    closegraph();

    Map* map       = new Map(cont->getBoardSize(), 0, 0, cont->getNumBoxes());
    Snake* player  = new Snake(map);
    random         = rand() % (map->getNumBoxes());
    Pickup* pickup = new NormalPickup(map->getXAtIndex(random), map->getYAtIndex(random), BLUE, map);
    delayTime = cont->getGameSpeed();
    cont->setSnakeRef(player);
    cont->setPickupRef(pickup);

    initwindow(cont->getBoardSize(), cont->getBoardSize(), "Snake Game");

    // Gameplay loop
    while(!cont->isGameLost() && !cont->isGameWon())
    {
        // Having two different pages keeps the screen from flickering when it is redrawn
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        for (int i = 0; i < 10; i++) // 10 * delayTime = desired total delay
        {
            cont->checkUserInput();
            delay(delayTime); 
        }

        player->moveSnake();
        cont->isGameOver();

        // Determines if the player has eaten any food
        if (cont->didSnakeEatFood())
        {
            player->addToLength(pickup->getGrowthSize()); // Add to the player length
            delete(pickup);

            // Figure out where to spawn a new food
            random = rand() % (map->getNumBoxes());
            while (!validPosition)
            {
                random = rand() % map->getNumBoxes();
                validPosition = true;

                // Check if the position is not on the snake's body
                for (int i = 0; i < player->getLength(); i++)
                {
                    if (map->getXAtIndex(random) == player->getXArr()[i] &&
                        map->getYAtIndex(random) == player->getYArr()[i])
                    {
                        validPosition = false;
                        break; // Exit the loop early if a collision is detected
                    }
                }
            }
            
            // Figure out which pickup to spawn
            if (pickupsUntilLargePickup == 0)
            {
                pickup = new LargePickup(map->getXAtIndex(random), map->getYAtIndex(random), RED, map);
                pickupsUntilLargePickup = 5;
            }
            else
            {
                pickup = new NormalPickup(map->getXAtIndex(random), map->getYAtIndex(random), BLUE, map);
                pickupsUntilLargePickup--;
            }
            cont->setPickupRef(pickup);
            player->drawSnake();
        }

        if (player->getLength() >= cont->getNumBoxes() * 0.75) // If the snake takes up at least 75% of the board
            cont->setGameWon(true); // The player wins

        // Redraw the screen
        map->drawEmptyMap();
        pickup->drawPickup();
        player->drawSnake();
        page = 1 - page;
    }
    
    closegraph();

    // Print a message telling the player if they won or lost and their score
    if (cont->isGameWon())
        std::cout << "You Won!" << " You got a score of " << cont->getScore() << std::endl;
    else
        std::cout << "You Lost..." << " You got a score of " << cont->getScore() << std::endl;

    // Free all of the unused pointers
    delete(map);
    delete(cont);
    delete(player);
    delete(pickup);

    return 0;
}