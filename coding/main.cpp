#include <iostream>
#include "Game.h"

int main()
{   
    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    //Initialize Game Object
    Game game;

    //Game loop
    while(game.running())
    {
        game.update();
        game.render();
    }

    //End of application
    return 0;
}