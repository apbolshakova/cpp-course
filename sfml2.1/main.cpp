#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving Ball");
    sf::Clock clock;

    sf::Vector2f position1 = {10, 20};

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::Vector2f speed = {500.f, 500.f};
    float wavePhase = 1;
    float yOffset = 200;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float time = clock.restart().asSeconds();
        position1.x += speed.x * time;

        wavePhase += time * float(2 * M_PI);
        position1.y = yOffset + amplitudeY * std::sin(wavePhase / periodY);

        if ((position1.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speed.x > 0))
        {
            speed.x = -speed.x;
        }
        if ((position1.x < 0) && (speed.x < 0))
        {
            speed.x = -speed.x;
        }

        ball.setPosition(position1);

        window.clear();
        window.draw(ball);
        window.display();
    }
}