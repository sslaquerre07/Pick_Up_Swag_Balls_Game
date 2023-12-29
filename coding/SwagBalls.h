#ifndef SWAGBALLS_H
#define SWAGBALLS_H

#include <SFML/Graphics.hpp>

class SwagBalls
{
    public:
        //Constructors and Destructors
        SwagBalls();
        ~SwagBalls();

        //Functions
        void update();
        void render(sf::RenderTarget& target);

    private:
        sf::CircleShape shape;

        //private Functions
        void initShape();

};

#endif