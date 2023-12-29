#ifndef SWAGBALLS_H
#define SWAGBALLS_H

#include <SFML/Graphics.hpp>

enum SwagBallTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPEs};

class SwagBalls
{
    public:
        //Constructors and Destructors
        SwagBalls(const sf::RenderWindow& window, int type);
        ~SwagBalls();

        const sf::CircleShape& getShape() const;
        const int& getType() const;

        //Functions
        void update();
        void render(sf::RenderTarget& target);

    private:
        sf::CircleShape shape;
        int type;

        //private Functions
        void initShape(const sf::RenderWindow& window);

};

#endif