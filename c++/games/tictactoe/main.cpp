#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class UI {
    sf::RenderWindow& window_ui;

    void draw_rectangle(sf::Vector2f size, sf::Vector2f position , sf::Color color) {
        sf::RectangleShape rectangle(size);
        rectangle.setPosition(position);
        rectangle.setFillColor(color);
        window_ui.draw(rectangle);
    }

public:
    UI(sf::RenderWindow& window) : window_ui(window) {}

    void draw_playing_field() {
        window_ui.clear(sf::Color(81, 85, 92));

        draw_rectangle({600, 5}, {100, 300}, sf::Color::White);
        draw_rectangle({600, 5}, {100, 500}, sf::Color::White);
        draw_rectangle({5, 600}, {300, 100}, sf::Color::White);
        draw_rectangle({5, 600}, {500, 100}, sf::Color::White);
    }
};


int main()
{

    sf::RenderWindow window(sf::VideoMode({800, 800}), "TicTacToe");
    UI ui(window);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        ui.draw_playing_field();

        window.display();


    }
}