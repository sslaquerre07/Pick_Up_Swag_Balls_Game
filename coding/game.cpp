#include "Game.h"

void Game::initVariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = 10;
    this->points = 0;
}

void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
}

void Game::initFont()
{
    if(!this->font.loadFromFile("Fonts/arial.ttf"))
    {
       std::cout << "Font failed to load"; 
    }
}

void Game::initText()
{
    this->guiText.setFont(this->font);
    this->guiText.setFillColor(sf::Color::White);
    this->guiText.setCharacterSize(30);

    this->endGameText.setFont(this->font);
    this->endGameText.setFillColor(sf::Color::Red);
    this->endGameText.setCharacterSize(40);
    this->endGameText.setPosition(sf::Vector2f(50.f, 300.f));
    this->endGameText.setString("GAME OVER");
}


//Constructors and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initFont();
    this->initText();
}

Game::~Game()
{
    delete this->window;

}

const bool& Game::getEndGame() const
{
    return this->endGame;
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
            //Picks from the enumerated list in SwagBallTypes, NROFTYPEs just gives you the number of types available
            this->swagBall_list.push_back(SwagBalls(*this->window, this->randomizeType()));
        }
    }
}

//Implemented in order to make the ball spawning a little less randomized, so we have a little more control
const int Game::randomizeType() const
{
    int type = SwagBallTypes::DEFAULT;
    int randValue = rand() % 100 + 1;
    if(randValue > 60 && randValue <= 80)
        type = SwagBallTypes::DAMAGING;
    else if(randValue > 80 && randValue <= 100)
        type = SwagBallTypes::HEALING;

    return type;
}

void Game::updatePlayer()
{
    this->player.update(this->window);
    if(this->player.getHp() <= 0)
        this->endGame = true;
}

void Game::updateCollision()
{
    //Check the collision
    for(size_t i= 0;i<swagBall_list.size();i++)
    {
        if(this->player.getShape().getGlobalBounds().intersects(this->swagBall_list[i].getShape().getGlobalBounds()))
        {
            switch(this->swagBall_list[i].getType())
            {
                case SwagBallTypes::DEFAULT:
                    //Add Points
                    this->points++;
                    break;
                case SwagBallTypes::DAMAGING:
                    this->player.takeDamage(1);
                    break;
                case SwagBallTypes::HEALING:
                    this->player.gainHealth(1);
                    break;
            }

            //Remove the ball
            this->swagBall_list.erase(this->swagBall_list.begin() + i);
        }
    }
}

void Game::updateGui()
{
    std::stringstream ss;
    ss << "Points: " << this->points << "\n"
        << "Health: " << this->player.getHp() << "/" << this->player.getHpMax() << "\n";

    this->guiText.setString(ss.str());
}

void Game::update()
{
    this->pollEvents();

    if(this->endGame == false)
    {
        this->spawnSwagBalls();
        this->updatePlayer();
        this->updateCollision();
        this->updateGui();
    }
}

void Game::renderGui(sf::RenderTarget* target)
{
   target->draw(this->guiText); 
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

    //Render GUI
    this->renderGui(this->window);

    if(this->endGame)
        this->window->draw(this->endGameText);

    this->window->display();
}