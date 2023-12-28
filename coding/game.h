#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

class Game
{
    public:
        //Constructors and Destructors
        Game();
        ~Game();

        //Getters

        //Setters

        //Functions
        void update();
        void render();

    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        bool endGame;

        //private Functions
        void initWindow();
        void initVariables();


};

#endif