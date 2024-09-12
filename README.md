# Brick Pong Game

This is a **Brick Pong Game** built using **C++** and **SFML** (Simple and Fast Multimedia Library). The game follows Object-Oriented Programming (OOP) principles, offering a simple and interactive experience where the player controls a paddle to break bricks using a bouncing ball.

## Features

- **Paddle Movement**: The player controls the paddle using the keyboard to keep the ball in play and hit the bricks.
- **Brick Breaking**: The ball breaks bricks upon collision, and the goal is to break all the bricks.
- **Ball Physics**: The ball bounces off walls, bricks, and the paddle with realistic physics.
- **Score Tracking**: The game keeps track of the player's score as bricks are broken.

## Technologies Used

- **C++**: Programming language used to implement the game logic.
- **SFML**: Simple and Fast Multimedia Library used for rendering graphics, handling input, and managing game events.
- **OOP Principles**: Classes and objects are used to encapsulate game components such as the paddle, ball, and bricks.

## Game Structure

- **Paddle**: Represents the player's paddle, which can be moved left and right.
- **Ball**: Represents the ball that bounces around the screen and breaks bricks.
- **Brick**: Represents individual bricks that need to be destroyed by the ball.
- **Game Manager**: Handles the game loop, event handling, and rendering.

## Installation and Setup

To run the game locally, follow these steps:

1. **Clone the Repository**:

    ```bash
    git clone https://github.com/yourusername/brick-pong-game.git
    cd brick-pong-game
    ```

2. **Install SFML**:

    - You need to install the SFML library to run this game. You can find the installation instructions for your platform on the [official SFML website](https://www.sfml-dev.org/download.php).
    
    - On Linux (Debian-based distros):

        ```bash
        sudo apt-get install libsfml-dev
        ```

    - On macOS (using Homebrew):

        ```bash
        brew install sfml
        ```

    - On Windows: Download the appropriate version of SFML from the [SFML website](https://www.sfml-dev.org/download.php).

3. **Compile the Game**:

    After installing SFML, you can compile the game using a compiler such as `g++` or an IDE like Visual Studio or Code::Blocks.

    If you are using `g++`, run the following command in the project directory:

    ```bash
    g++ -std=c++17 -o brick_pong main.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```

    Make sure the `-lsfml-graphics`, `-lsfml-window`, and `-lsfml-system` flags are included to link SFML.

## How to Play

- **Paddle Control**: Use the **left** and **right arrow keys** to move the paddle horizontally.
- **Objective**: Use the paddle to keep the ball in play and break all the bricks.
- **Win Condition**: Destroy all the bricks to win the game.
- **Lose Condition**: Letting the ball fall below the paddle will result in a game over.

## Project Structure

- **`main.cpp`**: Contains the main game loop and event handling.
- **`Paddle.h`/`Paddle.cpp`**: Defines the `Paddle` class and its behavior.
- **`Ball.h`/`Ball.cpp`**: Defines the `Ball` class and its interactions with the environment.
- **`Brick.h`/`Brick.cpp`**: Defines the `Brick` class for individual bricks in the game.
- **`Game.h`/`Game.cpp`**: The game manager class that controls the game state, handles inputs, and manages collisions.

## Object-Oriented Design

- **Encapsulation**: The game objects (`Paddle`, `Ball`, `Brick`) are encapsulated into separate classes, managing their own behavior and state.
- **Abstraction**: The game's complexity is divided into simpler objects with clear responsibilities.
- **Inheritance and Polymorphism**: Can be applied if you extend the game with more game objects or behaviors in the future.
- **Modularity**: The game is divided into different modules for better code management and reusability.

## Future Improvements

- **Levels**: Add more levels with increasing difficulty.
- **Power-ups**: Introduce power-ups like paddle size increase, multiple balls, etc.
- **Sound Effects**: Add sound effects for collisions and game events.
- **High Score**: Implement a high score system.

## Contributing

Feel free to fork the repository and submit pull requests with new features, bug fixes, or optimizations. For major changes, please open an issue first to discuss your ideas.

## Acknowledgments

- **SFML**: For providing an easy-to-use library for 2D graphics, input handling, and window management.
- **C++ Community**: For resources and tutorials that guided the development of this game.
