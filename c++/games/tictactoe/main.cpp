#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class UI {
    sf::RenderWindow& window_ui;
    std::array<sf::RectangleShape, 9> squares;
    int square_array[9] = { 0 };
    const float line_thickness = 5;

    void draw_grid_rectangle(sf::Vector2f size, sf::Vector2f position , sf::Color color) {
        sf::RectangleShape rectangle(size);
        rectangle.setPosition(position);
        rectangle.setFillColor(color);
        window_ui.draw(rectangle);
    }

    void create_squares(uint8_t index, sf::Vector2f size, sf::Vector2f position, sf::Color color) {
        squares[index] = sf::RectangleShape(size);
        squares[index].setPosition(position);
        squares[index].setFillColor(color);
        window_ui.draw(squares[index]);
    }

    void draw_squares() {
        sf::Color color = sf::Color(81, 85, 92);
        create_squares(0, {200, 200}, {100, 100}, color);
        create_squares(1, {200-line_thickness, 200}, {300+line_thickness, 100}, color);
        create_squares(2, {200-line_thickness, 200},{500+line_thickness, 100}, color);
        create_squares(3, {200, 200-line_thickness},{100, 300+line_thickness}, color);
        create_squares(4, {200-line_thickness, 200-line_thickness},{300+line_thickness, 300+line_thickness}, color);
        create_squares(5, {200-line_thickness, 200-line_thickness},{500+line_thickness, 300+line_thickness}, color);
        create_squares(6, {200, 200-line_thickness},{100, 500+line_thickness}, color);
        create_squares(7, {200-line_thickness, 200-line_thickness},{300+line_thickness, 500+line_thickness}, color);
        create_squares(8, {200-line_thickness, 200-line_thickness},{500+line_thickness, 500+line_thickness}, color);
    }

public:
    UI(sf::RenderWindow& window) : window_ui(window) {}

    void draw_playing_field() {
        window_ui.clear(sf::Color(81, 85, 92));
        // draw the grid
        draw_grid_rectangle({600, 5}, {100, 300}, sf::Color::White);
        draw_grid_rectangle({600, 5}, {100, 500}, sf::Color::White);
        draw_grid_rectangle({5, 600}, {300, 100}, sf::Color::White);
        draw_grid_rectangle({5, 600}, {500, 100}, sf::Color::White);

        draw_squares();
    }

    void check_square_clicked(sf::Vector2i mousePos) {
        for (size_t i = 0; i < squares.size(); i++) {
            if (squares[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                square_array[i] = 1;
                std::cout << "Square " << i << " clicked!" << std::endl;
                break;
            }
        }
    }

    int get_square_array_value(int index) {
        return square_array[index];
    }
};


class APP {


public:
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

        while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {

            // Handle mouse click
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            ui.check_square_clicked(mousePos);
            //delay
            sf::sleep(sf::milliseconds(200));


        }


    }
}