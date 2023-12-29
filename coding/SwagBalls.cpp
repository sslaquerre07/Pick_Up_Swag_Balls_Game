#include "SwagBalls.h"

SwagBalls::SwagBalls(const sf::RenderWindow& window)
{
    this->initShape(window);
}

SwagBalls::~SwagBalls()
{

}

const sf::CircleShape& SwagBalls::getShape() const
{
    return this->shape;
}

void SwagBalls::initShape(const sf::RenderWindow& window)
{
    this->shape.setRadius(static_cast<float>(rand() %10+10));
    sf::Color color(rand()%255+1, rand()%255+1, rand()%255+1);
    this->shape.setFillColor(color);
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
        )
    );
}

//Functions
void SwagBalls::update()
{

}

void SwagBalls::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}