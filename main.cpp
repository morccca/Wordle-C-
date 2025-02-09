#include <iostream>
#include "wordle_game.h"

int main()
{
    WordleGame game;
    std::string input;

    while (!game.isGameOver())
    {
        game.displayGame();
        std::cout << "Enter a word (or 'Q' to quit): ";
        std::getline(std::cin, input);
        
        if (input == "Q" || input == "q")
        {
            std::cout << "Quitting the game." << std::endl;
            break;
        }

        WordleGame::toUpperCase(input);
        
        if (game.makeGuess(input))
        {
            if (game.isGameWon())
            {
                game.displayGame();
                std::cout << "Congratulations! You won!" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Invalid word. Try again." << std::endl;
        }
    }

    if (!game.isGameWon() && input != "Q" && input != "q")
    {
        std::cout << "Game Over! Better luck next time!" << std::endl;
    }

    return 0;
}