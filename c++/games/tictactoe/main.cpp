#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#define PLAYER_1 1
#define PLAYER_1_SYMBOL 1
#define PLAYER_2 2
#define PLAYER_2_SYMBOL 2

uint8_t current_player_symbol = 1;


class UI {
    sf::RenderWindow& window_ui;
    std::array<sf::RectangleShape, 9> squares;
    sf::Font font;
    int square_array[9] = { 0 };
    const float line_thickness = 5;

    void draw_rectangle(sf::Vector2f size, sf::Vector2f position , sf::Color color) {
        sf::RectangleShape rectangle(size);
        rectangle.setPosition(position);
        rectangle.setFillColor(color);
        window_ui.draw(rectangle);
    }

    void create_square(uint8_t index, sf::Vector2f size, sf::Vector2f position, sf::Color color) {
        squares[index] = sf::RectangleShape(size);
        squares[index].setPosition(position);
        squares[index].setFillColor(color);
        window_ui.draw(squares[index]);
    }

    void draw_grid() {
        sf::Color color = sf::Color::White;
        draw_rectangle({600, 5}, {100, 300}, color);
        draw_rectangle({600, 5}, {100, 500}, color);
        draw_rectangle({5, 600}, {300, 100}, color);
        draw_rectangle({5, 600}, {500, 100}, color);
    }

    void create_squares() {
        sf::Color color = (sf::Color(81, 85, 92));
        create_square(0, {200, 200}, {100, 100}, color);
        create_square(1, {200-line_thickness, 200}, {300+line_thickness, 100}, color);
        create_square(2, {200-line_thickness, 200},{500+line_thickness, 100}, color);
        create_square(3, {200, 200-line_thickness},{100, 300+line_thickness}, color);
        create_square(4, {200-line_thickness, 200-line_thickness},{300+line_thickness, 300+line_thickness}, color);
        create_square(5, {200-line_thickness, 200-line_thickness},{500+line_thickness, 300+line_thickness}, color);
        create_square(6, {200, 200-line_thickness},{100, 500+line_thickness}, color);
        create_square(7, {200-line_thickness, 200-line_thickness},{300+line_thickness, 500+line_thickness}, color);
        create_square(8, {200-line_thickness, 200-line_thickness},{500+line_thickness, 500+line_thickness}, color);
    }

public:
    UI(sf::RenderWindow& window) : window_ui(window) {
        if (!font.openFromFile("../assets/arial.ttf")) {
            std::cerr << "Error loading font" << std::endl;
        }
        create_squares();
        draw_grid();
    }

    void draw_player_turn() {
        sf::Text text(font);
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        if (current_player_symbol == PLAYER_1) {
            text.setString("Player 1 (X)");
        } else {
            text.setString("Player 2 (O)");
        }
        text.setPosition({270, 10});
        window_ui.draw(text);
    }

    // ToDo: Rewrite function to update the square based on the players symbol
    void update_square_color(int index, sf::Color color) {
        squares[index].setFillColor(color);
    }

    void draw_playing_field() {
        window_ui.clear(sf::Color(81, 85, 92));
        draw_grid();
        for (int i = 0; i < squares.size(); i++) {
            window_ui.draw(squares[i]);
        }
    }

    int get_clicked_square(sf::Vector2i mousePos) {
        for (int i = 0; i < squares.size(); i++) {
            if (squares[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                return i;
            }
        }
        return -1;
    }

};


class APP {
    int square_array[9] = { 0 };

public:
    int get_square_array_value(int index) {
        return square_array[index];
    }

    void update_square_array(int index) {
        square_array[index] = current_player_symbol;
        if (current_player_symbol == PLAYER_1) {
            current_player_symbol = PLAYER_2;
        } else {
            current_player_symbol = PLAYER_1;
        }
    }
};


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "TicTacToe");
    UI ui(window);
    APP app;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* mouse_button_pressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouse_button_pressed->button == sf::Mouse::Button::Left) {
                    // Handle mouse click
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int clicked_square = ui.get_clicked_square(mousePos);
                    if (clicked_square != -1) {
                        app.update_square_array(clicked_square);
                        std::cout << "Clicked square: " << clicked_square << std::endl;
                        ui.update_square_color(clicked_square, sf::Color::Red);
                    }
                }
            }
        }

        window.clear();

        ui.draw_playing_field();
        ui.draw_player_turn();
        window.display();

    }

}