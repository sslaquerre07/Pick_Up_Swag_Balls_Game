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

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
    //Only problem with this code is that it does not handle being in the corners well

    //Left
    if(this->shape.getGlobalBounds().left <= 0.f)
        this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
    //right
    if((this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width) >= target->getSize().x)
        this->shape.setPosition((target->getSize().x - this->shape.getGlobalBounds().width), this->shape.getGlobalBounds().top);

    //top
    if(this->shape.getGlobalBounds().top <= 0.f)
        this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
    //bottom
    if((this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height) >= target->getSize().y)
        this->shape.setPosition(this->shape.getGlobalBounds().left, (target->getSize().y - this->shape.getGlobalBounds().height));

}

void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();
    //Window bounds collision
    this->updateWindowBoundsCollision(target);

}

//The arg in this function is necessary because this class has no access 
//to the window and must know where to render
void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}