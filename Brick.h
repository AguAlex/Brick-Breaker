#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Brick
{
protected:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite spp;
	


public:

	sf::Sprite getSprite();

	sf::FloatRect getPosition();

	void test()
	{
		std::cout << getPosition().width << std::endl;
	}

	Brick(float startX = 0.0f, float startY = 0.0f);
	void update(sf::Time dt);

};

