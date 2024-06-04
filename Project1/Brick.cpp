#include "Brick.h"

//Getters
sf::Sprite Brick::getSprite()
{
	return spp;
}

sf::FloatRect Brick::getPosition()
{
	return spp.getGlobalBounds();
}

//Constructor
Brick::Brick(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	texture.loadFromFile("assets/brick.png");
	spp.setTexture(texture);
	spp.setPosition(position);
	spp.setScale(sf::Vector2f(0.2, 0.2));

}

//Updating brick on screen
void Brick::update(sf::Time dt)
{
	spp.setPosition(position);
}

//Derived brick classes (inheritance)

//#1 AddingBallBrick Class

//Override brick_power() implementation
void AddingBallBrick::brick_power()	
{
	std::cout << "Adding Ball Brick" << std::endl;
}

//Constructor
AddingBallBrick::AddingBallBrick(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	texture.loadFromFile("assets/brick.png");
	spp.setTexture(texture);
	spp.setPosition(position);
	spp.setScale(sf::Vector2f(0.2, 0.2));
}

//#2 PointBrick Class

//Override brick_power() implementation
void PointBrick::brick_power()
{
	std::cout << "Point Brick" << std::endl;
}

//Constructor
PointBrick::PointBrick(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	texture.loadFromFile("assets/brick.png");
	spp.setTexture(texture);
	spp.setPosition(position);
	spp.setScale(sf::Vector2f(0.2, 0.2));
}