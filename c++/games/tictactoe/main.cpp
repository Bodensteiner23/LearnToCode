#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class UI {
    sf::RenderWindow& window_ui;
public:
    UI(sf::RenderWindow& window) : window_ui(window) {}

    void draw_playing_field() {
        sf::RectangleShape line_horiz_1({600, 5});
        line_horiz_1.setPosition({100, 300});
        line_horiz_1.setFillColor(sf::Color::Red);
        window_ui.draw(line_horiz_1);
        sf::RectangleShape line_horiz_2({600, 5});
        line_horiz_2.setPosition({100, 500});
        line_horiz_2.setFillColor(sf::Color::Red);
        window_ui.draw(line_horiz_2);

        sf::RectangleShape line_vert_1({600, 5});
        line_vert_1.setPosition({300, 100});
        line_vert_1.setFillColor(sf::Color::Red);
        line_vert_1.rotate(sf::degrees(90));
        window_ui.draw(line_vert_1);
        sf::RectangleShape line_vert_2({600, 5});
        line_vert_2.setPosition({500, 100});
        line_vert_2.setFillColor(sf::Color::Red);
        line_vert_2.rotate(sf::degrees(90));
        window_ui.draw(line_vert_2);
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