#pragma once

#include "includes.h"

#include "state.h"
#include "gamestate.h"


class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	sf::Clock dtClock;
	sf::Time dt;
	unsigned int nbrFrames;

	std::map<enums::ActionKey,
		sf::Keyboard::Key> supportedKeys;

	std::stack<State*> states;
	sf::VideoMode window_bounds;

	unsigned seed;

private:
	// Initializer
	void initKeys();
	void initWindow();
	void initStates();

public:

	// Constructor / Destructor
	Game();
	~Game();
	Game(Game& game) = delete;

	// Functions

	//regular
	void endApplication();

	//update
	void updateDt();
	void updateEvents();

	//render
	void render();
	void update();

	//core
	void run();

};
