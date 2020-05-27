#pragma once

#include "includes.h"

class State
{
private :

protected :
	sf::RenderWindow* window;
	std::vector<sf::Texture> listTextures;
	bool quit;

	unsigned& seed;

public:
	State(unsigned& seed, sf::RenderWindow* window = nullptr);
	virtual ~State();

	const bool getQuit();

	virtual void shot() = 0;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateInput(const sf::Time& dt) = 0;
	virtual void update(const sf::Time & dt, sf::VideoMode window_bounds) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

