#include "game.h"

// Constructor / Destructor

Game::Game() : nbrFrames( 0 ), dt()
{
    initWindow();
    initKeys();
    initStates();
    this->dtClock.restart();

    std::random_device rd;
    this->seed = rd();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        states.pop();
    }
}

// Initializer

void Game::initKeys()
{
    this->supportedKeys.emplace(enums::ActionKey::DOWN,
        sf::Keyboard::Key::S);
    this->supportedKeys.emplace(enums::ActionKey::LEFT,
        sf::Keyboard::Key::Q);
    this->supportedKeys.emplace(enums::ActionKey::RIGHT,
        sf::Keyboard::Key::D);
    this->supportedKeys.emplace(enums::ActionKey::UP,
        sf::Keyboard::Key::Z);
}

void Game::initWindow()
{
    std::ifstream ifs{ "config/window.ini" };

    std::string title{ "none" };
    this->window_bounds = sf::VideoMode{ 800, 600 };
    unsigned int framerate_limit{ 120 };
    bool verticatSyncEnabled{ false };

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> this->window_bounds.width >> this->window_bounds.height;
        ifs >> framerate_limit;
        ifs >> verticatSyncEnabled;
    }


    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(verticatSyncEnabled);
}

void Game::initStates()
{
    this->states.push(new GameState(this->seed, this->window));
}

// Update function

void Game::endApplication()
{
    std::cout << "ending app" << std::endl;
}

void Game::updateDt()
{  
    this->dt = this->dtClock.getElapsedTime();
    this->dtClock.restart();
    ++(this->nbrFrames);

    //system("cls");
    //std::cout << "> DeltaTime : " << this->dt.asSeconds() << std::endl;
    //std::cout << "> nbr Frame : " << nbrFrames << std::endl;
}

void Game::updateEvents()
{
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window->close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                this->states.top()->shot();
            }
        }
    }

}

void Game::update()
{
    this->updateEvents();

    if (!states.empty())
    {
        this->states.top()->update(this->dt, this->window_bounds);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    if (!states.empty())
    {
        this->states.top()->render(this->window);
    }

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}