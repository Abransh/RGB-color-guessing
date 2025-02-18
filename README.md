# Color Guessing Game

## Description
The **Color Guessing Game** is a fun console-based game where players try to guess a randomly generated RGB color. Players receive hints after each attempt to help them get closer to the correct color.

## Features
- Randomly generated target color
- Player input for RGB values
- Color preview using ANSI escape codes (for supported terminals)
- Hints provided after each guess
- Limited number of attempts

## How to Play
1. Run the game.
2. The game generates a random color, which remains hidden.
3. Enter RGB values (0-255) to guess the color.
4. The game provides hints after each guess:
   - "Too high" if the guessed value is greater than the target.
   - "Too low" if the guessed value is lower than the target.
   - "Correct!" if the guessed value matches the target.
5. The game continues until you guess correctly or run out of attempts.

## Installation & Compilation
### Prerequisites
- A C++ compiler (G++ or Clang++)
- Terminal with ANSI color support

### Compile the Game
Run the following command to compile the game:
```sh
 g++ -std=c++11 main.cpp Color.cpp ColorGuessingGame.cpp -o game
```

### Run the Game
```sh
 ./game
```

## File Structure
```
/color-game
│── main.cpp               # Entry point of the program
│── Color.hpp              # Color struct definition
│── Color.cpp              # Color struct implementation
│── ColorGuessingGame.hpp  # Game class definition
│── ColorGuessingGame.cpp  # Game logic implementation
│── README.md              # Project documentation
```

## Future Improvements
- Add difficulty levels
- Improve UI with better color display
- Implement a graphical version

## License
This project is open-source and free to use.

