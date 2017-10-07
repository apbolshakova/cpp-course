#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

int main()
{
    constexpr int pointCount = 200;
    const sf::Vector2f ellipseRadius = {200.f, 200.f};
    sf::Vector2f position = {200, 400};
    sf::Vector2f speed = {1, 1};

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 800}), "Ellipse",
        sf::Style::Default, settings);

    sf::ConvexShape ellipse;
    ellipse.setFillColor(sf::Color(0xFF, 0x09, 0x80));
    ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::cos(6 * angle) * std::sin(angle),
            ellipseRadius.y * std::cos(6 * angle) * std::cos(angle)};
        ellipse.setPoint(pointNo, point);
    };

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

        if ((position.x >= 600) && (speed.x > 0))
        {
            speed.x = -speed.x;
        }
        if ((position.x < 200) && (speed.x < 0))
        {
            speed.x = -speed.x;
        }
        if ((position.y >= 600) && (speed.y > 0))
        {
            speed.y = -speed.y;
        }
        if ((position.y < 200) && (speed.y < 0))
        {
            speed.y = -speed.y;
        }

        position.x += speed.x;
        position.y += speed.y;

        ellipse.setPosition(position);

        window.clear();
        window.draw(ellipse);
        window.display();
    }
}