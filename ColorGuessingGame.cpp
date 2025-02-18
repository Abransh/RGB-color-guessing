#include "colorGuessingGame.hpp"

ColorGuessingGame::ColorGuessingGame() {
    srand(time(0));
}

void ColorGuessingGame::displayColor(const Color& color, const std::string& label) {
    std::cout << "\n" << label;
    if (!label.empty()) std::cout << ": ";
    std::cout << "\033[48;2;" << color.r << ";" << color.g << ";" << color.b << "m";
    for (int i = 0; i < 3; i++) {
        std::cout << "                    \n                    ";
    }
    std::cout << "\033[0m\n";
    std::cout << "RGB(" << color.r << ", " << color.g << ", " << color.b << ")\n";
}

Color ColorGuessingGame::getRandomColor() {
    return Color(rand() % 256, rand() % 256, rand() % 256);
}

int ColorGuessingGame::getValidColorValue(const std::string& colorName) {
    int value;
    bool validInput = false;
    
    while (!validInput) {
        std::cout << colorName << " (0-255): ";
        if (std::cin >> value) {
            if (value >= 0 && value <= 255) {
                validInput = true;
            } else {
                std::cout << "Value must be between 0 and 255!\n";
            }
        } else {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}

Color ColorGuessingGame::getPlayerGuess() {
    Color guess;
    
    while (true) {
        std::cout << "\nEnter RGB values to see the color:\n";
        guess.r = getValidColorValue("Red");
        guess.g = getValidColorValue("Green");
        guess.b = getValidColorValue("Blue");
        
        std::cout << "\nYour color preview:";
        displayColor(guess, "");
        
        char confirm;
        std::cout << "Use this guess? (y/n): ";
        std::cin >> confirm;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (tolower(confirm) == 'y') {
            break;
        }
        std::cout << "\nLet's try different values.\n";
    }
    
    return guess;
}

void ColorGuessingGame::play() {
    target = getRandomColor();
    guessCount = 0;
    
    std::cout << "\033[2J\033[H"; // Clear screen
    std::cout << "=== Color Guessing Game ===\n";
    std::cout << "Try to guess this color!\n";
    std::cout << "\nTarget color:";
    displayColor(target, "");
    
    while (guessCount < MAX_GUESSES) {
        guessCount++;
        std::cout << "\nAttempt " << guessCount << "/" << MAX_GUESSES << "\n";
        
        Color guess = getPlayerGuess();
        
        if (guess == target) {
            std::cout << "\nCongratulations! You've guessed the correct color!\n";
            return;
        }
        
        std::cout << "\nHints:\n";
        std::cout << "Red: " << (guess.r < target.r ? "Too low" : guess.r > target.r ? "Too high" : "Correct!") << "\n";
        std::cout << "Green: " << (guess.g < target.g ? "Too low" : guess.g > target.g ? "Too high" : "Correct!") << "\n";
        std::cout << "Blue: " << (guess.b < target.b ? "Too low" : guess.b > target.b ? "Too high" : "Correct!") << "\n";
        
        if (guessCount < MAX_GUESSES) {
            std::cout << "\nTries remaining: " << MAX_GUESSES - guessCount << "\n";
        }
    }
    
    std::cout << "\nGame Over! The correct color was:";
    displayColor(target, "");
}
