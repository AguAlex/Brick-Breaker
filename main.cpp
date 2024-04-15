#include <iostream>
#include "Game.h"
#include "Ball.h"

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