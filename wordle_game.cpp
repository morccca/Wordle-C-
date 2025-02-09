#include "wordle_game.h"
#include <algorithm>
#include <iostream>

WordleGame::WordleGame() : 
    guesses(NUMBER_OF_GUESSES),
    matches(NUMBER_OF_GUESSES, std::vector<int>(WORD_LENGTH, NOT_MATCH)),
    targetWord("READY"),
    currentGuessCount(0) {}

bool WordleGame::makeGuess(const std::string& guess) 
{
    if (!isValidWord(guess)) return false;
    
    guesses[currentGuessCount] = guess;
    
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (targetWord[i] == guess[i]) {
            matches[currentGuessCount][i] = FULL_MATCH;
        } else {
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (targetWord[j] == guess[i]) {
                    matches[currentGuessCount][i] = PARTIAL_MATCH;
                    break;
                }
            }
        }
    }
    
    currentGuessCount++;
    return true;
}

void WordleGame::displayGame() const 
{
    for (int i = 0; i < currentGuessCount; i++) {
        for (int j = 0; j < WORD_LENGTH; j++) {
            switch (matches[i][j]) {
                case FULL_MATCH:
                    std::cout << "\033[32m" << guesses[i][j] << "\033[0m"; // Green
                    break;
                case PARTIAL_MATCH:
                    std::cout << "\033[33m" << guesses[i][j] << "\033[0m"; // Yellow
                    break;
                default:
                    std::cout << guesses[i][j];
            }
        }
        std::cout << std::endl;
    }
}

bool WordleGame::isGameWon() const 
{
    if (currentGuessCount == 0) return false;
    return guesses[currentGuessCount - 1] == targetWord;
}

bool WordleGame::isGameOver() const 
{
    return currentGuessCount >= NUMBER_OF_GUESSES || isGameWon();
}

bool WordleGame::isValidWord(const std::string& word) 
{
    return word.length() == WORD_LENGTH && 
           word.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

void WordleGame::toUpperCase(std::string& input) 
{
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
}
