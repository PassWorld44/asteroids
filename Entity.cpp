#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->mouvementSpeed = 100.f;
	this->angle = 0;
}

Entity::Entity(float mouvementSpeed, float angle)
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->mouvementSpeed = mouvementSpeed;
	this->angle = angle;
}

Entity::~Entity()
{
}
/*void Entity::move(const sf::Time& dt, sf::Vector2f dir)
{
	this->shape.move(dir * this->mouvementSpeed * dt.asSeconds());
} 

void Entity::update(const sf::Time& dt)
{
}

void Entity::render(sf::RenderTarget *target)
{
	target->draw(this->shape);
} */
