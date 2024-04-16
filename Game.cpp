#include "Game.h"
#include <iostream>
#include <time.h>

//Constructor & Destructor
Game::Game()
{
	initVariables();
	initWindow();

}

Game::~Game()
{
	delete this->window;
    for (auto i : bricks)
    {
        delete i;
    }
    
}


//Accessors
bool Game::gameRunning()
{
	return window->isOpen();
}


//Functions
void Game::pollEvents()
{

    dt = clock.restart();
    bounceTimer -= dt.asSeconds();
    //Events polling
    while (window->pollEvent(event))
    {
        
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();

            break;
        }
    }
    //Logica coliziunii ball-platform
    if (ball.getPosition().intersects(platform.getPosition()))
    {   /*
        // Verifică coliziunea cu partea stângă a platformei
        if (ball.getPosition().left <= platform.getPosition().left + platform.getPosition().width / 2)
        {
            if (bounceTimer < 0)
            {
                ball.hitPlatformLeft(); // Coliziune cu partea stângă a platformei
                bounceTimer = 0.10f;
            }
        }
        // Verifică coliziunea cu partea dreaptă a platformei
        else if (ball.getPosition().left > platform.getPosition().left + platform.getPosition().width / 2)
        {
            if (bounceTimer < 0)
            {
                ball.hitPlatformRight(); // Coliziune cu partea dreaptă a platformei
                bounceTimer = 0.10f;
            }
        }
        */
        if (bounceTimer < 0)
        {
            ball.hitPlatform(); // Coliziune cu partea stângă a platformei
            bounceTimer = 0.10f;
        }
    }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && platform.getPosition().left > 0)
            platform.moveLeft();
        else
            platform.stopLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && platform.getPosition().left + platform.getPosition().width < 1280)
            platform.moveRight();
        else
            platform.stopRight();
       
    
    

    if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > 1280)
    {
        ball.hitSides();
    }

    if (ball.getPosition().top < 0 && bounceTimer < 0)
    {
        ball.hitTop();
        bounceTimer = 0.10f;
    }

    if (ball.getPosition().top + ball.getPosition().height > 720)
    {
        ball.hitBottom();
    }
}

void Game::update()
{
    pollEvents();
    
}


void Game::render()
{
    /*
        - clear old frame
        - render objects
        - display new frame in window
    */
   
    bool check = false;
    for (int i = 0; i <= 20; i++)
        if (i == true)
            check = true;
    if (check == true)
    {
        window->clear(sf::Color(255, 100, 100, 255));
        ball.update(dt);
        platform.update(dt);


        window->draw(ball.getShape());
        window->draw(platform.getShape());
        int cnt = 0;
        for (auto i : bricks)
        {

            if (bricks_status[cnt] == true)
                window->draw(i->getSprite());
            if (ball.getPosition().intersects(i->getPosition()) && bricks_status[cnt] == true)
            {
                bricks_status[cnt] = false;
                //Coliziune pe stanga sau dreapta brick
                if (ball.getPosition().left + ball.getPosition().width <= i->getPosition().left + (i->getPosition().width / 2)
                    || ball.getPosition().left >= i->getPosition().left + (i->getPosition().width / 2))
                    ball.hitSides();

                //Coliziune sus
                if (ball.getPosition().top + ball.getPosition().height <= i->getPosition().top + (i->getPosition().height / 2))
                    ball.hitPlatform();

                if (ball.getPosition().top >= i->getPosition().top + (i->getPosition().height / 2))
                    ball.hitTop();

                i->brick_power();

            }

            cnt++;

        }
   

    }
    else
    {
        window->clear(sf::Color(125, 150, 150, 255));
    }

    

    
    
        

    //Draw objects
    window->display();
}

//Private Functions
void Game::initWindow()
{
	videoMode.height = 720;
	videoMode.width = 1280;
	
	window = new sf::RenderWindow(videoMode, "First Game!", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(140);
}

void Game::initVariables()
{
    window = nullptr;
    ball = Ball(1280/2, 500);
    platform = Platform(1280 / 2, 700);
    srand(time(NULL));
    int auxx = 120, auxy = 10;
    
    for (int i = 1; i <= 1; i++)
    {
        auxx = 110;
        for (int j = 1; j <= 7; j++)
        {
            //PointBrick aux = PointBrick(auxx, auxy);

            int randomNumber = std::rand() % 10 + 1;
            //std::cout << randomNumber << " ";

            switch (randomNumber % 2)
            {
            case 1:
                bricks.push_back(new PointBrick(auxx, auxy));
                break;
            case 0:
                bricks.push_back(new AddingBallBrick(auxx, auxy));
                break;
            default:
                break;
            }
            
            auxx += lung;
           
        }
            
        auxy += lung;
        
    }
    for (int i=0 ; i<=20; i++)
        bricks_status[i] = true;

    
   
}
