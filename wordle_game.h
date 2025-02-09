
#ifndef wordle_game_h
#define wordle_game_h

#include <string>
#include <vector>
#include "constants.h"

class WordleGame 
{
private:

    std::vector<std::string> guesses;
    std::vector<std::vector<int>> matches;
    std::string targetWord;
    int currentGuessCount;

public:
    WordleGame();

    bool makeGuess(const std::string& guess);
    void displayGame() const;
    bool isGameWon() const;
    bool isGameOver() const;
    static bool isValidWord(const std::string& word);
    static void toUpperCase(std::string& input);
};

#endif