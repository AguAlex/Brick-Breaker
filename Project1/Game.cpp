#include "Game.h"
#include <iostream>
#include <time.h>

//Constructor & Destructor
Game::Game()
{
	initVariables();
	initWindow();

}
//Destructor for memory leaks, because i'm using some pointers in the game logic
Game::~Game()
{
	delete this->window;
    for (auto i : bricks)
    {
        delete i; 
    }
    delete this->platform;
    delete this->ball;
    
}

//Checking if the game is still running
bool Game::gameRunning()
{
	return window->isOpen();
}


//Functions

void Game::resetGame() {

   
    for (auto i : bricks)
    {
        delete i;
    }
    bricks.clear();
    delete this->platform;
    delete this->ball;

    
    initVariables();
    initWindow();
}

//For checking events
void Game::pollEvents()
{

    dt = clock.restart();
    bounceTimer -= dt.asSeconds();

    //Events polling

    while (window->pollEvent(event))
    {
        //For closing the window 
        switch (event.type)
        {
        //By clicking close
        case sf::Event::Closed:
            window->close();
            break;

        //By pressing escape button
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();

            break;
        }
    }

    //Restart the game
    if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::R) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && score_value == bricks_number)
    {
        resetGame();
    }

    //Moving the platform by pressing A or <- (to left) / D or -> (to right)
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && platform->getPosition().left > 0)
            platform->moveLeft();
        else
            platform->stopLeft();

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && platform->getPosition().left + platform->getPosition().width < 1280)
            platform->moveRight();
        else
            platform->stopRight();
       
        //The logic for collision ball-sides

        if (ball->getPosition().left < 0 || ball->getPosition().left + ball->getPosition().width > 1280)
        {
            ball->hitSides();
        }

        if (ball->getPosition().top < 0 && bounceTimer < 0)
        {
            ball->hitTop();
            bounceTimer = 0.10f;
        }

        if (ball->getPosition().top + ball->getPosition().height > 720)
        {
            ball->hitBottom();
        }

        //The logic for collision ball-platform

        if (ball->getPosition().intersects(platform->getPosition()))
        {
            if (bounceTimer < 0)
            {
                ball->hitPlatform();
                bounceTimer = 0.10f;
            }
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
   
    
    if (score_value == bricks_number)
    {
        endGame = true;
    }
    
    
    // Checking if all bricks have been removed and rendering the endscreen
    if (endGame)
    {
        window->clear();
        window->draw(endgameBackground);
        sf::Text endText;
        endText.setFont(font);
        endText.setString("Congratulations! Your Score: " + std::to_string(score_value) + "\n\n\nPress R or Space to Play Again !");
        endText.setCharacterSize(36);
        endText.setFillColor(sf::Color::White);
        endText.setPosition(1280/2.f, 720/2.f);
        endText.setOrigin(endText.getGlobalBounds().width / 2, endText.getGlobalBounds().height / 2);
        window->draw(endText);
        window->display();
        return; // Exit render() function to avoid rendering main screen objects
    }
    else
    {
        //Clear old frame and update ball and platform position
        window->clear(sf::Color(157, 43, 196, 90));

        ball->update(dt);

        platform->update(dt);



        //Render new frame

        window->draw(ball->getShape());
        window->draw(platform->getShape());

        //Check collision ball-bricks and update the bricks
        int cnt = 0;
        for (auto& i : bricks)
        {
            
            if (bricks_status[cnt] == true) {
                window->draw(i->getSprite());
            }

            if (ball->getPosition().intersects(i->getPosition()) && bricks_status[cnt] == true) {
                bricks_status[cnt] = false;

                sf::FloatRect ballBounds = ball->getPosition();
                sf::FloatRect brickBounds = i->getPosition();

                float ballLeft = ballBounds.left;
                float ballRight = ballBounds.left + ballBounds.width;
                float ballTop = ballBounds.top;
                float ballBottom = ballBounds.top + ballBounds.height;

                float brickLeft = brickBounds.left;
                float brickRight = brickBounds.left + brickBounds.width;
                float brickTop = brickBounds.top;
                float brickBottom = brickBounds.top + brickBounds.height;

                // Determine collision side
                float overlapLeft = ballRight - brickLeft;
                float overlapRight = brickRight - ballLeft;
                float overlapTop = ballBottom - brickTop;
                float overlapBottom = brickBottom - ballTop;

                bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
                bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

                float minOverlapX = fromLeft ? overlapLeft : overlapRight;
                float minOverlapY = fromTop ? overlapTop : overlapBottom;

                if (minOverlapX < minOverlapY) {
                    // Collision on the left or right side
                    ball->hitSides();
                }
                else {
                    // Collision on the top or bottom side
                    if (fromTop) {
                        ball->hitPlatform();
                    }
                    else {
                        ball->hitTop();
                    }
                }

                i->brick_power();

                // Update and show the score
                score_value++;
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

//Initialize the window
void Game::initWindow()
{
	videoMode.height = windowHeight;
	videoMode.width = windowWidth;
	
	window = new sf::RenderWindow(videoMode, "Brick Breaker!", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(140);
}

//Initialize the variables and objects
void Game::initVariables()
{
    window = nullptr;

    platform = new Platform(windowWidth / 2, 700);
    ball = new Ball(windowWidth/2, 680);
    

    srand(time(NULL));

    //Aux variables for updating bricks on screen
    int auxx = 120, auxy = 10;
    bricks_number = 0;

    for (int i = 1; i <= 5; i++)
    {
        auxx = 110;
        for (int j = 1; j <= 7; j++)
        {
            

            int randomNumber = std::rand() % 10 + 1;
            //There is a 33% chance to add the brick (this section randomize brick configuration)
            if (randomNumber % 3 == 0)
            {
                bricks_number++;

                //There is 80% chance to add a point brick and 20% chance to add an adding ball brick
                switch (randomNumber <= 8)
                {
                case true:
                    bricks.push_back(new PointBrick(auxx, auxy));
                    break;
                case false:
                    bricks.push_back(new AddingBallBrick(auxx, auxy));
                    break;
                default:
                    break;
                }
            }
            
            
            auxx += lung;
           
        }
            
        auxy += lung-100;
        
    }
    for (int i=0 ; i<=34; i++)
        bricks_status[i] = true;

    //Init score and text font
    font.loadFromFile("assets/Dogfiles.otf");
    score.setFont(font);
    score.setCharacterSize(24);
    score.setString("Score: 0");
    score.setOrigin(sf::Vector2f(-20.0f, -20.0f));
    score_value = 0;

    //Init endgame screen
    endgameTexture.loadFromFile("assets/endgame.jpg");
    endgameBackground.setTexture(endgameTexture);

    
    endGame = false;
    
   
}
