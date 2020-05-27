#pragma once

#include "includes.h"

class Entity
{
private:

protected:
	sf::RectangleShape shape; //for the collisions
	float mouvementSpeed;
	float angle;
public:
	Entity();
	Entity(float mouvementSpeed, float angle);
	virtual ~Entity();

	//void move(const sf::Time& dt);

	virtual void update(const sf::Time& dt, sf::VideoMode window_bounds) = 0;
	virtual void render(sf::RenderTarget *target) = 0;
};

