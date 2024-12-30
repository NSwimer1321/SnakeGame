#ifndef SNAKECLASS
#define SNAKECLASS

#include "Map.h"
#include <list>
using std::list;

#define MOVE_UP    0 // Denotes the Snake is trying to move up
#define MOVE_DOWN  1 // Denotes the Snake is trying to move down
#define MOVE_LEFT  2 // Denotes the Snake is trying to move to the left
#define MOVE_RIGHT 3 // Denotes the Snake is trying to move to the right

/**
 * The Snake class denotes the object that the player controls. The player
 * is able to move the Snake up, down, left, and right to try and collect food (Pickup objects)
 * and avoid the border of the game as well as the Snake itself.
 */
class Snake
{
    public:
        //Methods
        /**
         * Creates a new Snake object by creating new int arrays (for the xArr and yArr variables)
         * and giving them a size equal to the number of boxes on screen. Also sets the current move
         * direction to MOVE_UP by default and sets the length of the Snake to 3.
         * @param map A reference to the Map object
         */
        Snake(Map* map);

        /**
         * Adjusts all x and y coordinates of every piece of the snake based on the direction the
         * Snake is moving.
         */
        void moveSnake();

        /**
         * Retrieves and returns the x coordinate of the head of the Snake
         */
        int getX();

        /**
         * Retrieves and returns the y coordinate of the head of the Snake
         */
        int getY();

        /**
         * Retrieves and returns the length of the Snake
         */
        int getLength();

        /**
         * Adds a certain amount to the length of the Snake
         * @param amount the amount to add to the Snake length
         */
        void addToLength(int amount);

        /**
         * Retrieves and returns the array that holds all x coordinates of all Snake pieces
         */
        int* getXArr();

        /**
         * Retrieves and returns the array that holds all y coordinates of all Snake pieces
         */
        int* getYArr();

        /**
         * Sets the curMoveDirection variable to a new direction
         * @param newDir the new direction to set the curMoveDirection variable to
         */
        void setMoveDirection(int newDir);
        

        //Drawing
        /**
         * Draws each piece of the Snake
         */
        void drawSnake();

    private:
        //Fields
        int* xArr; // An array that denotes the x positions of every piece of the Snake
        int* yArr; // An array that denotes the y positions of every piece of the Snake (x[i] and y[i] both refer to the ith piece of the snake)
        Map* map; // A reference to the map that the Snake traverses
        int x; // The x position of the head of the Snake
        int y; // The y position of the head of the Snake
        int curMoveDir; // The way that the Snake is currently moving
        int numPieces; // The number of pieces of the Snake (length of the Snake)
        
};

#endif