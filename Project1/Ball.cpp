#include "Ball.h"


//Constructor & Destructor
Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setPosition(position);
	ballShape.setRadius(15);
	ballShape.setFillColor(sf::Color::White);
}

//Getters & Setters
sf::FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

sf::CircleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXValue() 
{
	return move_directionX;
}

//Functions

//For checking collisions ball - objects (bricks or window sides)
void Ball::hitSides() 
{
	move_directionX = -move_directionX;
}

void Ball::hitTop()
{
	move_directionY = -move_directionY;
}

void Ball::hitBottom() {
	position.x = 1280 / 2;
	position.y = 0;
}

void Ball::hitPlatform()
{
	move_directionY = -move_directionY;
}

//For updating position in each frame
void Ball::update(sf::Time dt)
{
	position.x += move_directionX * move_speed * dt.asSeconds();
	position.y += move_directionY * move_speed * dt.asSeconds();
	
	ballShape.setPosition(position);
}
