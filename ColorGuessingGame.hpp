#ifndef COLOR_GUESSING_GAME_HPP
#define COLOR_GUESSING_GAME_HPP

#include "Color.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>

class ColorGuessingGame {
private:
    Color target;
    const int MAX_GUESSES = 5;
    int guessCount = 0;
    
    void displayColor(const Color& color, const std::string& label);
    Color getRandomColor();
    int getValidColorValue(const std::string& colorName);
    Color getPlayerGuess();

public:
    ColorGuessingGame();
    void play();
};

#endif
