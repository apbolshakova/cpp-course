#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({25, 90});
    shape1.setRotation(0);
    shape1.setPosition({210, 110});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    sf::CircleShape shape2(25);
    shape2.setPosition({215, 110});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(25);
    shape3.setPosition({215, 150});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({10, 85});
    shape4.setRotation(20);
    shape4.setPosition({310, 115});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({10, 85});
    shape5.setRotation(-20);
    shape5.setPosition({310, 120});
    shape5.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({38, 10});
    shape6.setRotation(0);
    shape6.setPosition({292, 165});
    shape6.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({20, 90});
    shape7.setRotation(0);
    shape7.setPosition({365, 110});
    shape7.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape7);

    sf::CircleShape shape8(25);
    shape8.setPosition({365, 110});
    shape8.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape8);

    sf::CircleShape shape9(15);
    shape9.setPosition({225, 120});
    shape9.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(shape9);

    sf::CircleShape shape10(15);
    shape10.setPosition({225, 160});
    shape10.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(shape10);

    sf::CircleShape shape11(15);
    shape11.setPosition({375, 120});
    shape11.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(shape11);

    sf::CircleShape shape12(5);
    shape12.setPosition({309, 113});
    shape12.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape12);

    window.display();

    sf::sleep(sf::seconds(5));
}