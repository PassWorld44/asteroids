#include "Player.h"

Player::Player()
{
	//system("dir");
	if (!this->texture.loadFromFile("assets/ship.png"))
	{
		std::cout << "this isn't good" << std::endl;
	}
	//sf::Vector2u coord = texture.getSize();
	this->sprite.setTexture(this->texture, true);
	//this->sprite.setTextureRect(sf::IntRect(0, 0, coord.x, coord.y));
	this->sprite.setPosition(300, 200);
	this->sprite.setOrigin(8, 11);

	this->mouvementSpeed = 25.f;
	this->score = 0;
	this->nbrLife = 3;

	
}

Player::~Player()
{
}


void Player::move(const sf::Time& dt)
{
	this->sprite.move(this->dirMove );

	for (Tir &a : listTir)
	{
		a.move(dt);
	}
}

void Player::shot()
{
	if (this->listTir.size() == 4)
	{
		this->listTir.pop_front();
	}

	this->listTir.push_back(Tir(mouvementSpeed * 50, angle,
		sprite.getPosition()));
}

void Player::update(const sf::Time& dt, sf::VideoMode window_bounds)
{
	this->move(dt);

	this->sprite.setRotation(radToDeg(this->angle));

	this->dirMove = this->dirMove * 0.98f; //reducing the actual speed

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float angleMove = this->angle - 3.141592653589793f / 2.f;
		sf::Vector2f dirNew(std::cos(angleMove), std::sin(angleMove));
		this->dirMove += dirNew * this->mouvementSpeed * dt.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->angle -= 0.1f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->angle += 0.1f;
	}
	

	sf::Vector2f pos = this->sprite.getPosition();
	if (pos.x < 0)
	{
		pos.x = window_bounds.width;
	}
	if (pos.y < 0)
	{
		pos.y = window_bounds.height;
	}
	if (pos.x > window_bounds.width)
	{
		pos.x = 0;
	}
	if (pos.y > window_bounds.height)
	{
		pos.y = 0;
	}

	this->sprite.setPosition(pos);

	for (Tir& a : listTir)
	{
		a.update(dt, window_bounds);
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(sprite);

	for (Tir &a : listTir)
	{
		a.render(target);
	}
}
