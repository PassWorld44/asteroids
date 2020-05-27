#include "Asteroid.h"

void Asteroid::initPos(sf::VideoMode window_bounds)
{
	if (this->angle >= 3.141592653589793f / 4.f
		&& this->angle < 3 * 3.141592653589793f / 4)
	{ //then spawn in bottom
		unsigned y = genInt() % window_bounds.width;
		this->sprite.setOrigin(window_bounds.height, y);

		std::cout << "b: " << this->angle << std::endl;
	}
	if (this->angle >= 3 * 3.141592653589793f / 4.f
		&& this->angle < 5 * 3.141592653589793f / 4)
	{ //then spawn in the right
		unsigned x = genInt() % window_bounds.height;
		this->sprite.setOrigin(x, window_bounds.width);

		std::cout << "r: " << this->angle << std::endl; 
	}
	if (this->angle >= 5 * 3.141592653589793f / 4.f
		&& this->angle < 7 * 3.141592653589793f / 4)
	{ //then spawn in the top
		unsigned y = genInt() % window_bounds.width;
		this->sprite.setOrigin(0, y);

		std::cout << "t: " << this->angle << std::endl; 
	}
	else
	{ //then spaw in the left
		unsigned x = genInt() % window_bounds.height;
		this->sprite.setOrigin(x, 0);

		std::cout << "l: " << this->angle << std::endl; 
	}
}

void Asteroid::initSize()
{
	int rand = genInt() % 3 + 1;

	if (rand == 1)
	{
		this->size = Size::LITTLE;
		this->pointsVal = 100;
		this->mouvementSpeed *= 2;
	}
	if (rand == 2)
	{
		this->size = Size::MEDIUM;
		this->pointsVal = 50;
		this->sprite.setScale(2, 2);
	}
	if (rand == 3)
	{
		this->size = Size::BIG;
		this->pointsVal = 20;
		this->mouvementSpeed *= 0.75f;
		this->sprite.setScale(5, 5);
	}
}

Asteroid::Asteroid(sf::VideoMode window_bounds, std::mt19937& rand) : genInt(rand)
{
	if (!this->texture.loadFromFile("assets/asteroid.png"))
	{
		std::cout << "this isn't good" << std::endl;
	}
	this->sprite.setTexture(this->texture, true);

	this->angle = (genInt() % 3600) / 10.f;
	this->angle = degToRad(this->angle);
	this->sprite.setRotation(angle * 200); //we don't really care about this rotation
	this->wantQuit = false;

	initPos(window_bounds);

	this->mouvementSpeed = (genInt() % 100) + 50;

	initSize();
}

Asteroid::~Asteroid()
{
}

void Asteroid::move(const sf::Time& dt)
{
	float angleMove = this->angle;
	sf::Vector2f dirNew(std::cos(angleMove), std::sin(angleMove));

	this->sprite.move(dirNew * mouvementSpeed * dt.asSeconds());
}

void Asteroid::update(const sf::Time& dt, sf::VideoMode window_bounds)
{
	this->move(dt);
}

void Asteroid::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

bool Asteroid::getQuit()
{
	return wantQuit;
}
