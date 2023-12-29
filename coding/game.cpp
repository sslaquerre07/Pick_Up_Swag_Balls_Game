#include "Game.h"

void Game::initVariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = 10;
}

void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
}


//Constructors and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;

}

//Functions
const bool Game::running(){
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->sfmlEvent))
    {
        switch(this->sfmlEvent.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->sfmlEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        } 
    }
}

void Game::spawnSwagBalls()
{
    if(this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else
    {
        if(this->swagBall_list.size() < this->maxSwagBalls)
        {
            this->spawnTimer = 0.f;
            this->swagBall_list.push_back(SwagBalls(*this->window));
        }
    }
}

void Game::update()
{
    this->pollEvents();


    this->spawnSwagBalls();
    this->player.update(this->window);
}

void Game::render()
{
    //Clear the old frame to make room for the new one
    this->window->clear();

    //Render Stuff
    this->player.render(this->window);

    for(auto i:this->swagBall_list)
    {
        i.render(*this->window);
    }

    this->window->display();
}