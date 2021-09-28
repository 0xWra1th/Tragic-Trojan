// It's Pong.

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // -------------- SETUP --------------
    // Window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Tragic Trojan", sf::Style::Close);
    window.setFramerateLimit(60);

    // Clock
    sf::Clock deltaTime;
    // -----------------------------------

    // ------------- OBJECTS -------------
    // BALL
    sf::CircleShape ball(20.f);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(20.f, 20.f);
    ball.setPosition(950.f , window.getSize().y / 2.f);
    bool right = false;
    bool down = false;
    float SPEED = 10.f;

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
    std::cout << "Hello World!" << std::endl;
    float PLAYER_SPEED = 10.f;

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
                if(event.key.code == sf::Keyboard::P){
                    std::cout << "Pausing..." << std::endl;
                }else if(event.key.code == sf::Keyboard::Escape){
                    std::cout << "Exiting Game." << std::endl;
                    window.close();
                    return 0;
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

        // ------------ MOVE BALL ------------
        if(right){
            ball.setPosition(ball.getPosition().x + (SPEED * dt.asSeconds() * 100), ball.getPosition().y);
        }else{
            ball.setPosition(ball.getPosition().x - (SPEED * dt.asSeconds() * 100), ball.getPosition().y);
        }

        if(!right & ball.getPosition().x < 250.f){
            right = true;
        }else if(right & ball.getPosition().x > window.getSize().x - 250.f){
            right = false;
        }
        // -----------------------------------

        // ---------- UPDATE WINDOW ----------
        window.clear();
        window.draw(background);
        window.draw(divider);
        window.draw(ball);
        window.draw(player_left);
        window.draw(player_right);
        window.display();
        // -----------------------------------
    }
    // -----------------------------------

    return 0;
}
