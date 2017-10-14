#include <iostream>
#include <cmath>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians)
{
    float result = double(radians) * 180.0 / M_PI;
    if (result < 0)
    {
        result = 360 + result;
    }
    return result;
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x),
                     float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock &clock)
{
    const float deltaTime = clock.restart().asSeconds();
    float speed = 150;
    const sf::Vector2f offset = mousePosition - pointer.getPosition();
    float newAngle = toDegrees(std::atan2(offset.y, offset.x));
    float rotation = pointer.getRotation();
    float deltaAngle = newAngle - rotation;

    float newRotation = std::min(fabs(speed * deltaTime), fabs(deltaAngle));

    if (newRotation > 180)
    {
        newRotation = 360 - newRotation;
    }

    if ((deltaAngle < 0) !=
        ((rotation > 270 && rotation < 360 && newAngle > 0 && newAngle < 90) ||
         (newAngle > 270 && newAngle < 360 && rotation > 0 && rotation < 90)))
    {
        newRotation = -newRotation;
    }
    pointer.rotate(newRotation);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse", sf::Style::Default, settings);

    sf::Clock clock;
    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    };
}