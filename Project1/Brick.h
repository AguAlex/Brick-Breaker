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

	virtual void brick_power() = 0;

	Brick(float startX = 0.0f, float startY = 0.0f);
	void update(sf::Time dt);

};

class AddingBallBrick : public Brick
{
public:
	void brick_power()	override
	{
		std::cout << "Adding Ball Brick"<<std::endl;
	}
	
	AddingBallBrick(float startX = 0.0f, float startY = 0.0f)
	{
		position.x = startX;
		position.y = startY;

		texture.loadFromFile("assets/brick.png");
		spp.setTexture(texture);
		spp.setPosition(position);
		spp.setScale(sf::Vector2f(0.2, 0.2));
	}

};

class PointBrick : public Brick
{
public:
	void brick_power() override
	{
		std::cout << "Point Brick" << std::endl;
	}

	PointBrick(float startX = 0.0f, float startY = 0.0f)
	{
		position.x = startX;
		position.y = startY;

		texture.loadFromFile("assets/brick.png");
		spp.setTexture(texture);
		spp.setPosition(position);
		spp.setScale(sf::Vector2f(0.2, 0.2));
	}

};


