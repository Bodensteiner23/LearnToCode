#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class UI {
    sf::RenderWindow& window_ui;
public:
    UI(sf::RenderWindow& window) : window_ui(window) {}

    void draw_playing_field() {
        sf::RectangleShape line1({150, 10});
        line1.setPosition({100, 100});
        line1.setFillColor(sf::Color::Red);
        line1.setRotation(sf::degrees(90));
        window_ui.draw(line1);
        sf::RectangleShape line2({150, 10});
        line2.setPosition({300, 100});
        line2.setFillColor(sf::Color::Red);
        line2.setRotation(sf::degrees(90));
        window_ui.draw(line2);




    }

};


int main()
{

    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
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