#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Player.h"
#include "SwagBalls.h"

class Game
{
    public:
        //Constructors and Destructors
        Game();
        ~Game();

        //Getters

        //Setters

        //Functions
        const bool running();
        void pollEvents();

        void spawnSwagBalls();
        void updateCollision();
        void updateGui();
        void update();

        void renderGui(sf::RenderTarget* target);
        void render();

    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        bool endGame;
        sf::Event sfmlEvent;

        Player player;

        int points;

        sf::Font font;
        sf::Text guiText;

        std::vector<SwagBalls> swagBall_list;
        float spawnTimerMax;
        float spawnTimer;
        int maxSwagBalls;

        //private Functions
        void initWindow();
        void initVariables();
        void initFont();
        void initText();


};

#endif