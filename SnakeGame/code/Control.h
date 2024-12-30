#include "Snake.h"
#include "Pickup.h"

/**
 * The control class is in charge of handling all user input, game state (whether the game is won
 * or lost), and handling the game's difficulty.
 */
class Control
{
    /**
     * The Difficulty struct is designed to allow to easily set all variables that
     * relate to a game's difficulty (how large the board is, how many boxes will be on screen,
     * and how fast the game operates).
     */
    struct Difficulty
    {
        int boardSize; // The size of the board (width and height use the same number)
        int numBoxes; // The number of boxes that will be on screen
        int gameSpeed; // How long every delay is (how fast everything updates)

        Difficulty(int size, int numBoxes, int speed)
        {
            boardSize      = size;
            this->numBoxes = numBoxes;
            gameSpeed      = speed;
        }

        // The default game mode is the medium difficulty
        Difficulty()
        {
            boardSize = 400;
            numBoxes  = 100;
            gameSpeed = 40;
        }
    };

    public:
        /**
         * Creates a new Control object
         * @param snake A reference to the snake object that the player operates
         * @param pickup A reference to the pickup object that is on screen
         */
        Control(Snake* snake, Pickup* pickup);

        /**
         * Retrieves the score variable and returns it;
         */
        int getScore();

        /**
         * Adds to the player's current score
         * @param amount The amount of score to add to the player's current score
         */
        void addToScore(int amount);

        /**
         * Retrieves the gameWon variable and returns it
         */
        bool isGameWon();

        /**
         * Sets the gameWon variable to a given bool value
         * @param newVal the new value of the gameWon variable
         */
        void setGameWon(bool newVal);

        /**
         * Retrieves the gameLost variable and returns it
         */
        bool isGameLost();

        /**
         * Determines if the any game loss conditions have been met (if the snake head has gone over the
         * border of the game map or if the snake head has collided with any part of the snake tail)
         */
        void isGameOver();

        /**
         * Determines if the snake head has collided with the pickup object on screen
         */
        bool didSnakeEatFood();

        /**
         * Determines if the player has used the arrow keys to select a difficulty or
         * control the snake.
         */
        void checkUserInput();

        /**
         * Retrieves and returns the hasDifficultyBeenSet variable
         */
        bool seeIfDifficultyHasBeenSet();

        /**
         * Retrieves and returns the board size from the current difficulty
         */
        int getBoardSize();

        /**
         * Retrieves and returns the game speed from the current difficulty
         */
        int getGameSpeed();

        /**
         * Retrieves and returns the number of boxes on screen from the current difficulty
         */
        int getNumBoxes();

        /**
         * Sets the snake object taht the this->snake variable references
         * @param snake the new Snake variable this->snake references
         */
        void setSnakeRef(Snake* snake);

        /**
         * Sets the pickup object that the curPickup variable references
         * @param pickup the new Pickup variable that curPickup references
         */
        void setPickupRef(Pickup* pickup);

        /**
         * Sets the difficulty of the game
         * @param boardSize the size of one side of the game board
         * @param numBoxes the number of boxes that will be on the game board
         * @param gameSpeed how frequently the game updates
         */
        void setDifficulty(int boardSize, int numBoxes, int gameSpeed);

    private:
        //Fields
        int score; // The player's current score
        Snake* snake; // A reference to the snake object that the player controls
        Pickup* curPickup; // A reference to the current pickup object on screen
        Difficulty curDifficulty; // The current difficulty
        bool hasDifficultyBeenSet; // true if the player has choosen a difficulty, false otherwise
        bool gameWon; // True if the player has met the game win condition, false otherwise
        bool gameLost; // True if the player has met the game loss condition, false otherwise
};