#pragma once

#include "Entity.h"
#include "OtherStuff.h"

class Asteroid :
	public Entity
{
private:
	enum class Size {LITTLE, MEDIUM, BIG};

	sf::Texture texture;
	sf::Sprite sprite;
	int nbrLife;
	int pointsVal;
	Size size;

	std::mt19937& genInt;

	bool wantQuit;

	void initPos(sf::VideoMode window_bounds);
	void initSize();

public:
	Asteroid(sf::VideoMode window_bounds, std::mt19937& rand);
	~Asteroid();
	
	void move(const sf::Time& dt);

	void update(const sf::Time& dt, sf::VideoMode window_bounds);
	void render(sf::RenderTarget* target);
	bool getQuit();
};

