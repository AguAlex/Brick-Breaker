#pragma once
#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Ball.h"
#include "Platform.h"
#include "Brick.h"

//Main Game Class
class Game
{
private:
	//Game Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	sf::Time dt;
	sf::Clock clock;
	float bounceTimer = 0.10f; //for some bugs
	sf::Font font;
	sf::Text score;
	int score_value = 0;
	bool endGame = false;
	sf::Texture endgameTexture;
	sf::Sprite endgameBackground;

	const int windowHeight = 720;
	const int windowWidth = 1280;
	


	//Game objects
	Ball ball;
	Platform *platform;
	std::list<Brick*> bricks;
	bool bricks_status[30] = {};
	int lung = 82*2;


public:
	//Constructor & Destructor
	Game();
	~Game();

	//Accessors
	bool gameRunning();

	//Functions
	void pollEvents();
	void update();
	void render();

private:
	//Private Functions
	void initWindow();
	void initVariables();

};

