#include "gamestate.h"

GameState::GameState(unsigned& seed, sf::RenderWindow* window)
	: player(), State(seed, window)
{
	this->genInt.seed(seed);

	this->listAsteroids.reserve(100);

	sf::Vector2u size = window->getSize();

	sf::VideoMode v{ size.x, size.y};

	for (int i = 0; i < 5; i++)
	{
		this->listAsteroids.push_back(Asteroid{ v, genInt });
	}
}

GameState::~GameState()
{
}

void GameState::shot()
{
	player.shot();
}

void GameState::endState()
{
	std::cout << "endState" << std::endl;
}

void GameState::updateInput(const sf::Time& dt)
{
	this->checkForQuit();

}

void GameState::update(const sf::Time& dt, sf::VideoMode window_bounds)
{
	this->updateInput(dt);
	this->player.update(dt, window_bounds);

	for (Asteroid& as : this->listAsteroids)
	{
		as.update(dt, window_bounds);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	this->player.render(target);

	for (Asteroid& as : this->listAsteroids)
	{
		as.render(target);
	}
}
