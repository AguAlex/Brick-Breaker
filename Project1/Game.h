#pragma once
#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Ball.h"
#include "Platform.h"
#include "Brick.h"

//Main Game Class
class Game
{
private:
	//Game Variables

	//For game characteristics
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	sf::Time dt;
	sf::Clock clock;
	float bounceTimer = 0.10f; //for some bugs

	//For scoreboard
	sf::Font font;
	sf::Text score;
	int score_value;

	//For endgame screen
	bool endGame;
	sf::Texture endgameTexture;
	sf::Sprite endgameBackground;

	//For making the bricks symmetric on the screen
	int lung = 82 * 2;

	const int windowWidth = 1280;
	const int windowHeight = 720;


	//Game objects
	Ball* ball;
	Platform* platform;
	std::list<Brick*> bricks;
	bool bricks_status[35] = {};
	int bricks_number;
	


public:
	//Constructor & Destructor
	Game();
	~Game();

	//Checking if the game is still running
	bool gameRunning();

	//Functions

	//For checking events
	void pollEvents();

	//For updating frames
	void update();

	//For rendering frames (drawing on screen)
	void render();

private:

	//The constructor is implicit

	//Init the game
	
	void initWindow();
	void initVariables();

	
	void resetGame();


};

