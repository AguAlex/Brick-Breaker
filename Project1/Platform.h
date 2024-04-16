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
	Platform(float startX = 0.0f, float startY = 0.0f);

	sf::Sprite getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	void update(sf::Time dt);

};

