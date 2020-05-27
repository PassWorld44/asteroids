#pragma once

#include "state.h"
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"

class GameState :
	public State
{
private:
	Player player;
	std::vector<Asteroid> listAsteroids;
	std::mt19937 genInt;

public:
	GameState(unsigned& seed, sf::RenderWindow* window = nullptr);
	virtual ~GameState();

	virtual void shot() override;

	virtual void endState() override;
	virtual void updateInput(const sf::Time& dt) override;
	virtual void update(const sf::Time& dt, sf::VideoMode window_bounds) override;
	virtual void render(sf::RenderTarget* target = nullptr) override;
};

