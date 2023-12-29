#include "Player.h"

void Player::initVariables()
{
    this->movementSpeed = 10.f;
}

void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y)
{
    //Use x and y to set the position of the player
    this->shape.setPosition(x, y);
    this->initVariables();
    this->initShape();

}

Player::~Player()
{

}

void Player::updateInput()
{
    //Keyboard input

    //Left and right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed, 0.f);
    }
    
    //Up and down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f, -this->movementSpeed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movementSpeed);
    }    
}

void Player::update(sf::RenderTarget* target)
{
    //Window bounds collision

    this->updateInput();

}

//The arg in this function is necessary because this class has no access 
//to the window and must know where to render
void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}