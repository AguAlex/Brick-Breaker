#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setPosition(position);
	ballShape.setSize(sf::Vector2f(30, 30));
	ballShape.setFillColor(sf::Color(100, 100, 100, 255));
}

//Getters & Setters
sf::FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return ballShape;
}

//??????????????????
float Ball::getXValue()
{
	return move_directionX;
}

//Functions
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

void Ball::hitPlatformLeft()
{
	move_directionY = -move_directionY;
	if (move_directionX > 0)
		move_directionX = -move_directionX;
}

void Ball::hitPlatformRight()
{
	move_directionY = -move_directionY;
	if (move_directionX < 0)
		move_directionX = -move_directionX;
}

void Ball::update(sf::Time dt)
{
	position.x += move_directionX * move_speed * dt.asSeconds();
	position.y += move_directionY * move_speed * dt.asSeconds();
	
	ballShape.setPosition(position);
}
