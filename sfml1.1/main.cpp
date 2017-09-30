#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({140, 320}), "Traffic light", sf::Style::Default, settings);

    window.clear();

    sf::RectangleShape body;
    body.setSize({100, 280});
    body.setRotation(0);
    body.setPosition({20, 20});
    body.setFillColor(sf::Color(0x30, 0x0, 0x0));
    window.draw(body);

    sf::CircleShape greenCircle(40);
    greenCircle.setPosition({30, 25});
    greenCircle.setFillColor(sf::Color(0x6B, 0xB8, 0x56));
    window.draw(greenCircle);

    sf::CircleShape yellowCircle(40);
    yellowCircle.setPosition({30, 115});
    yellowCircle.setFillColor(sf::Color(0xFD, 0xE8, 0x00));
    window.draw(yellowCircle);

    sf::CircleShape redCircle(40);
    redCircle.setPosition({30, 205});
    redCircle.setFillColor(sf::Color(0xFF, 0x00, 0x00));
    window.draw(redCircle);

    window.display();

    sf::sleep(sf::seconds(5));
}