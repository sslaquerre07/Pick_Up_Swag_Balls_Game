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
        const bool& getEndGame() const;

        //Setters

        //Functions
        const bool running();
        void pollEvents();

        void spawnSwagBalls();
        const int randomizeType() const;
        void updatePlayer();
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
        sf::Text endGameText;

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