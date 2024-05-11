#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Yellow circle");
    sf::CircleShape circle(25);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                    circle.move(50, 0);
                else if (event.key.code == sf::Keyboard::Left)
                    circle.move(-50, 0);
                else if (event.key.code == sf::Keyboard::Down)
                    circle.move(0, 50);
                else if (event.key.code == sf::Keyboard::Up)
                    circle.move(0, -50);
            }
        }
        window.clear();

        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                sf::RectangleShape cell(sf::Vector2f(50, 50));
                cell.setFillColor(sf::Color::Black);
                cell.setOutlineThickness(2);
                cell.setOutlineColor(sf::Color::White);
                cell.setPosition(i * 50, j * 50);
                window.draw(cell);
            }
        }

        window.draw(circle);
        window.display();
    }
    return 0;
}