#include "Brick.h"

sf::Sprite Brick::getSprite()
{
	return spp;
}

sf::FloatRect Brick::getPosition()
{
	return spp.getGlobalBounds();
}

Brick::Brick(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	texture.loadFromFile("assets/brick.png");
	spp.setTexture(texture);
	spp.setPosition(position);
	spp.setScale(sf::Vector2f(0.2, 0.2));

}

void Brick::update(sf::Time dt)
{
	spp.setPosition(position);
}
