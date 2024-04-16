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
    delete platform;
    
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
    if (ball.getPosition().intersects(platform->getPosition()))
    {   
        if (bounceTimer < 0)
        {
            ball.hitPlatform(); // Coliziune cu partea stângă a platformei
            bounceTimer = 0.10f;
        }
    }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && platform->getPosition().left > 0)
            platform->moveLeft();
        else
            platform->stopLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && platform->getPosition().left + platform->getPosition().width < 1280)
            platform->moveRight();
        else
            platform->stopRight();
       
    
    

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
    for (int i = 0; i <= 6; i++)
        if (bricks_status[i] == true)
            check = true;
    if (!check)
    {
        endGame = true;
    }
    
    
    // Dacă jocul a fost încheiat, afișează ecranul de sfârșit de joc
    if (endGame)
    {
        window->clear();
        window->draw(endgameBackground);
        sf::Text endText;
        endText.setFont(font);
        endText.setString("Congratulations! Your Score: " + std::to_string(score_value));
        endText.setCharacterSize(36);
        endText.setFillColor(sf::Color::White);
        endText.setPosition(1280/2.f, 720/2.f);
        endText.setOrigin(endText.getGlobalBounds().width / 2, endText.getGlobalBounds().height / 2);
        window->draw(endText);
        window->display();
        return; // Ieși din funcția de render pentru a evita afișarea altor obiecte de joc
    }
    else
    {
        window->clear(sf::Color(157, 43, 196, 90));
        ball.update(dt);
        platform->update(dt);


        window->draw(ball.getShape());
        window->draw(platform->getShape());
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
                score_value++;
                //std::cout << score_value << std::endl;
                score.setString("Score: " + std::to_string(score_value));

            }

            cnt++;

        }
        window->draw(score);

    }
        

    //Draw objects
    window->display();
}

//Private Functions
void Game::initWindow()
{
	videoMode.height = windowHeight;
	videoMode.width = windowWidth;
	
	window = new sf::RenderWindow(videoMode, "Brick Breaker!", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(140);
}

void Game::initVariables()
{
    window = nullptr;
    ball = Ball(windowWidth/2, 680);
    platform = new Platform(windowWidth / 2, 700);
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

    font.loadFromFile("Dogfiles.otf");
    score.setFont(font);
    score.setCharacterSize(24);
    score.setString("Score: 0");
    score.setOrigin(sf::Vector2f(-20.0f, -20.0f));

    endgameTexture.loadFromFile("endgame.jpg");
    endgameBackground.setTexture(endgameTexture);
    
   
}
