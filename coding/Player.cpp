#include "Player.h"

void Player::initVariables()
{

}

void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player()
{
    this->initVariables();
    this->initShape();

}

Player::~Player()
{

}

void Player::update()
{

}

//The arg in this function is necessary because this class has no access 
//to the window and must know where to render
void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}