#include "Tir.h"

Tir::Tir(float mouvementSpeed, float angle, sf::Vector2f pos)
	: Entity(mouvementSpeed, angle)
{
	this->shape.setSize(sf::Vector2f(5.f, 5.f));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setPosition(pos);
}

Tir::~Tir()
{
}

void Tir::move(const sf::Time& dt)
{
	float angleMove = this->angle - 3.141592653589793f / 2.f;
	sf::Vector2f dirNew(std::cos(angleMove), std::sin(angleMove));

	this->shape.move(dirNew * mouvementSpeed * dt.asSeconds() );

}

void Tir::update(const sf::Time& dt, sf::VideoMode window_bounds)
{
	sf::Vector2f pos = this->shape.getPosition();
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
	this->shape.setPosition(pos); 
}

void Tir::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
