#pragma once
#include "Entity.h"
class Tir :
	public Entity
{
private:
	//sf::RectangleShape renderable;
	
public:
	Tir(float mouvementSpeed, float angle, sf::Vector2f pos);
	virtual ~Tir();

	void move(const sf::Time& dt);

	virtual void update(const sf::Time& dt, sf::VideoMode window_bounds) override;
	virtual void render(sf::RenderTarget* target) override;
};

