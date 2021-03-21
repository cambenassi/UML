#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "ps0");

    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    int x = 0, y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                x = 0;
                y = -10;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                x = -10;
                y = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                x = 0;
                y = 10;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                x = 10;
                y = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                sprite.rotate(45.f);
            }

            sprite.move(x, y);
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}