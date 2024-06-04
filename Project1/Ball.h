#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



class Ball
{
private:

	sf::Vector2f position;
	sf::CircleShape ballShape;

	float move_speed = 400;
	float move_directionX = 1.0f;
	float move_directionY = 1.0f;
	
public:
	//Constructor & Destructor
	Ball(float startX = 0.f, float startY = 0.f);

	//Getters & Setters

	sf::FloatRect getPosition();

	sf::CircleShape getShape();

	float getXValue();

	//Functions

	//For checking collisions ball - objects (bricks or window sides)
	void hitSides();

	void hitTop();

	void hitBottom();

	void hitPlatform();

	

	//For updating position in each frame
	void update(sf::Time dt);
};

