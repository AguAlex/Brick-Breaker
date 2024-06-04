#include <iostream>
#include "Game.h"
#include "Ball.h"

constexpr int windowWidth = 1280;
constexpr int windowHeight = 720;

int main() {
    //Init Game
    Game game = Game();
    

    

    //Game Loop
    while (game.gameRunning())
    {
        
        //Game Update
        game.update();

        //Game Render
        game.render();

    }

	return 0;
}