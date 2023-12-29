#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    private:
        sf::RectangleShape shape;
        int hp;
        int hpMax;

        float movementSpeed;

        void initVariables();
        void initShape();

    public:
        Player(float x = 0.f, float y = 0.f);
        ~Player();

        //Accessors
        const sf::RectangleShape& getShape() const;
        const int& getHp() const;
        const int& getHpMax() const;

        //Functions
        void takeDamage(const int damage);
        void gainHealth(const int health);

        void updateInput();
        void updateWindowBoundsCollision(const sf::RenderTarget* target);
        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);

};


#endif