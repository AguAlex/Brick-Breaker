#include "Platform.h"

Platform::Platform(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(200, 15));
	shape.setFillColor(sf::Color::Black);
	shape.setPosition(position);
}

sf::RectangleShape Platform::getShape()
{
	return shape;
}

sf::FloatRect Platform::getPosition()
{
	return shape.getGlobalBounds();
}

void Platform::moveLeft()
{ 
	movingLeft = true;
}

void Platform::moveRight()
{
	movingRight = true;
}

void Platform::stopLeft()
{
	movingLeft = false;
}

void Platform::stopRight()
{
	movingRight = false;
}

void Platform::update(sf::Time dt)
{
	if (movingLeft)
	{
		position.x -= speed * dt.asSeconds();
	}
	if (movingRight)
	{
		position.x += speed * dt.asSeconds();
	}

	shape.setPosition(position);
}


