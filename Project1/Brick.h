#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//Base class (abstract class)
class Brick
{
protected:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite spp;
	


public:

	//Getters
	sf::Sprite getSprite();

	sf::FloatRect getPosition();

	
	//Virtual method, because each type of brick does something special
	//This line force each derived class to override own implementetion for method
	virtual void brick_power() = 0;

	//Constructor
	Brick(float startX = 0.0f, float startY = 0.0f);

	//Updating brick on screen
	void update(sf::Time dt);

};

//Derived brick classes (inheritance)

//#1
class AddingBallBrick : public Brick
{
public:
	
	//Override brick_power() implementation
	void brick_power()	override;
	
	//Constructor
	AddingBallBrick(float startX = 0.0f, float startY = 0.0f);
	
};

//#2
class PointBrick : public Brick
{
public:
	//Override brick_power() implementation
	void brick_power() override;
	

	//Constructor
	PointBrick(float startX = 0.0f, float startY = 0.0f);
	

};


