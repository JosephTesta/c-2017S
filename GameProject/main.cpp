#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    std::cout << "1" << std::endl;
    sf::CircleShape shape(100.f);
    std::cout << "2" << std::endl;
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        std::cout << "3" << std::endl;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << "4" << std::endl;

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}