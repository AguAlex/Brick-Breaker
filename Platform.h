#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Platform
{
private:

	sf::RectangleShape shape;
	sf::Vector2f position;
	float speed = 1100.0f;

	bool movingLeft = false;
	bool movingRight = false;

public:
	Platform(float startX = 0.0f, float startY = 0.0f);

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	void update(sf::Time dt);

};

