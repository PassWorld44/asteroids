#pragma once

#include "includes.h"
#include "Entity.h"
#include "Tir.h"
#include "OtherStuff.h"

class Player : public Entity
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int nbrLife;
	int score;
	sf::Vector2f dirMove;
	std::deque<Tir> listTir;

public:
	Player();
	~Player();

	void move(const sf::Time& dt) ;

	void shot();

	virtual void update(const sf::Time& dt, sf::VideoMode window_bounds) override;
	virtual void render(sf::RenderTarget* target) override;

};

