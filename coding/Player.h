#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    private:
        sf::RectangleShape shape;

        void initVariables();
        void initShape();

    public:
        Player();
        ~Player();

        void update();
        void render(sf::RenderTarget* target);

};


#endif