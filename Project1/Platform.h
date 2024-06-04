#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Platform
{
private:

	sf::Vector2f position;
	sf::Texture platformTexture;
	sf::Sprite shape;

	
	float speed = 1100.0f;

	bool movingLeft = false;
	bool movingRight = false;

public:
	//Constructor
	Platform(float startX = 0.0f, float startY = 0.0f);

	//Getters
	sf::Sprite getShape();
	sf::FloatRect getPosition();

	//Functions
	
	//For moving the platform
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	//For updating the platform each frame
	void update(sf::Time dt);

};

