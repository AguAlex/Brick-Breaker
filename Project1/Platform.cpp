#include "Platform.h"

Platform::Platform(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	platformTexture.loadFromFile("assets/platform.png");
	shape.setTexture(platformTexture);


	shape.setPosition(position);
	
	shape.setScale(sf::Vector2f(0.5f, 0.5f));
}

sf::Sprite Platform::getShape()
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


