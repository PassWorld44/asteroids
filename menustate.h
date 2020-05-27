#pragma once

#include "state.h"

class MenuState :
	public State
{
private:

public:
	virtual void endState() override;
	virtual void updateInput(const sf::Time& dt) override;
	virtual void update(const sf::Time& dt, sf::VideoMode window_bounds) override;
	virtual void render(sf::RenderTarget* target = nullptr) override;
};

