// It's Pong.

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

int main()
{
    // -------------- SETUP --------------
    // Window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Tragic Trojan", sf::Style::Close);
    window.setFramerateLimit(60);

    // Clock
    sf::Clock deltaTime;

    // Variables
    int leftScore = 0;
    int rightScore = 0;
    bool right = false;
    float BALL_SPEED = 10.f;
    float BALL_Y_VELOCITY = 0.f;
    float PLAYER_SPEED = 10.f;
    // -----------------------------------
    
    // ------------- AUDIO ---------------
    sf::SoundBuffer hitBuff;
    hitBuff.loadFromFile("assets/hit.wav");

    sf::SoundBuffer wallBuff;
    wallBuff.loadFromFile("assets/wall.wav");

    sf::SoundBuffer scoreBuff;
    scoreBuff.loadFromFile("assets/score.wav");

    sf::Sound hitSound;
    hitSound.setBuffer(hitBuff);
    hitSound.setVolume(75);

    sf::Sound wallSound;
    wallSound.setBuffer(wallBuff);

    sf::Sound scoreSound;
    scoreSound.setBuffer(scoreBuff);
    scoreSound.setVolume(40);
    // -----------------------------------

    // --------------- UI ----------------
    sf::Font font;
    font.loadFromFile("assets/ARCADE.TTF");

    sf::Text left_score;
    left_score.setStyle(sf::Text::Bold);
    left_score.setFont(font);
    left_score.setFillColor(sf::Color::White);
    left_score.setOrigin(50.f, 50.f);
    left_score.setCharacterSize(100);
    left_score.setPosition(100.f, 50.f);
    std::string score = std::to_string(leftScore);
    left_score.setString(score);

    sf::Text right_score;
    right_score.setStyle(sf::Text::Bold);
    right_score.setFont(font);
    right_score.setFillColor(sf::Color::White);
    right_score.setOrigin(50.f, 50.f);
    right_score.setCharacterSize(100);
    right_score.setPosition(window.getSize().x-50.f, 50.f);
    score = std::to_string(rightScore);
    right_score.setString(score);
    // -----------------------------------

    // ------------- OBJECTS -------------
    // BALL
    sf::CircleShape ball(20.f);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(20.f, 20.f);
    ball.setPosition(950.f , window.getSize().y / 2.f);    

    // DIVIDER
    sf::RectangleShape divider(sf::Vector2f(2.f, window.getSize().y));
    divider.setFillColor(sf::Color::White);
    divider.setOrigin(0.f, window.getSize().y / 2.f);
    divider.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // BACKGROUND
    sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(sf::Color::Blue);
    background.setOrigin(window.getSize().x / 2.f, window.getSize().y / 2.f);
    background.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // PLAYER LEFT
    sf::RectangleShape player_left(sf::Vector2f(20.f, 200.f));
    player_left.setFillColor(sf::Color::White);
    player_left.setOrigin(10.f, 100.f);
    player_left.setPosition(225.f , window.getSize().y / 2.f);

    // PLAYER RIGHT
    sf::RectangleShape player_right(sf::Vector2f(20.f, 200.f));
    player_right.setFillColor(sf::Color::White);
    player_right.setOrigin(10.f, 100.f);
    player_right.setPosition(window.getSize().x - 225.f, window.getSize().y / 2.f);
    // -----------------------------------

    // ------------ GAME LOOP ------------
    while (window.isOpen())
    {   
        // Tick Clock
        sf::Time dt = deltaTime.restart();

        // ---------- HANDLE EVENTS ----------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }else if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                    return 0;
                }else if(event.key.code == sf::Keyboard::R){
                    // Reset
                    leftScore = 0;
                    rightScore = 0;
                    score = std::to_string(leftScore);
                    left_score.setString(score);
                    score = std::to_string(rightScore);
                    right_score.setString(score);
                    ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                    BALL_Y_VELOCITY = 0;
                }
            }
        }
        // -----------------------------------

        // ----------- KEY PRESSES -----------
        // Left Player
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            player_left.setPosition(player_left.getPosition().x , player_left.getPosition().y - (PLAYER_SPEED * dt.asSeconds() * 100));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            player_left.setPosition(player_left.getPosition().x , player_left.getPosition().y + (PLAYER_SPEED * dt.asSeconds() * 100));
        }

        // Right Player
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            player_right.setPosition(player_right.getPosition().x , player_right.getPosition().y - (PLAYER_SPEED * dt.asSeconds() * 100));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            player_right.setPosition(player_right.getPosition().x , player_right.getPosition().y + (PLAYER_SPEED * dt.asSeconds() * 100));
        }
        // -----------------------------------

        // ---------- CLAMP POSTION ----------
        //Left Player
        if(player_left.getPosition().y < 125.f){
            player_left.setPosition(player_left.getPosition().x, 125.f);
        }

        if(player_left.getPosition().y > 775.f){
            player_left.setPosition(player_left.getPosition().x, 775.f);
        }

        // Right Player
        if(player_right.getPosition().y < 125.f){
            player_right.setPosition(player_right.getPosition().x, 125.f);
        }

        if(player_right.getPosition().y > 775.f){
            player_right.setPosition(player_right.getPosition().x, 775.f);
        }
        // -----------------------------------

        // ------------ COLLISIONS -----------
        // Player hitting ball
        if(player_left.getGlobalBounds().intersects(ball.getGlobalBounds())){
            right = true;
            float diff = ball.getPosition().y - player_left.getPosition().y;
            BALL_Y_VELOCITY = diff / 10;
            hitSound.play();
        }else if(player_right.getGlobalBounds().intersects(ball.getGlobalBounds())){
            right = false;
            float diff = ball.getPosition().y - player_right.getPosition().y;
            BALL_Y_VELOCITY = diff / 10;
            hitSound.play();
        }

        // Ball bouncing off walls
        if(ball.getPosition().y < 10.f){
            BALL_Y_VELOCITY *= -1;
            wallSound.play();
        }else if(ball.getPosition().y > 890){
            BALL_Y_VELOCITY *= -1;
            wallSound.play();
        }
        // -----------------------------------

        // ---------- SCORE UPDATE -----------
        if(ball.getPosition().x > (window.getSize().x - 50.f)){
            leftScore++;
            score = std::to_string(leftScore);
            left_score.setString(score);
            ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            right = false;
            BALL_Y_VELOCITY = 0;
            scoreSound.play();
        }else if(ball.getPosition().x < 50.f){
            rightScore++;
            score = std::to_string(rightScore);
            right_score.setString(score);
            ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            right = true;
            BALL_Y_VELOCITY = 0;
            scoreSound.play();
        }
        // -----------------------------------

        // ------------ MOVE BALL ------------
        if(ball.getPosition().x < 1600 & ball.getPosition().x > 0){
            if(right){
                ball.setPosition(ball.getPosition().x + (BALL_SPEED * dt.asSeconds() * 100), ball.getPosition().y + (BALL_Y_VELOCITY * dt.asSeconds() * 100));
            }else{
                ball.setPosition(ball.getPosition().x - (BALL_SPEED * dt.asSeconds() * 100), ball.getPosition().y + (BALL_Y_VELOCITY * dt.asSeconds() * 100));
            }
        }
        // -----------------------------------

        // ---------- UPDATE WINDOW ----------
        window.clear();
        window.draw(background);
        window.draw(divider);
        window.draw(ball);
        window.draw(player_left);
        window.draw(player_right);
        window.draw(left_score);
        window.draw(right_score);
        window.display();
        // -----------------------------------
    }
    // -----------------------------------

    return 0;
}
