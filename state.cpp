#include "state.h"

State::State(unsigned& seed_, sf::RenderWindow* window) 
	: quit(false), seed(seed_)
{
	this->window = window;
}

State::~State()
{

}

const bool State::getQuit()
{
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}
