#include "app.h"

App::App() : Malom() {
    Window.create(sf::VideoMode(1080, 1080), "Malom", sf::Style::Close);
}

void App::draw_piece(const Piece& piece) {
    sf::Texture t;
    if (piece.get_colour() == White) t.loadFromFile("white_piece.png");
    if (piece.get_colour() == Black) t.loadFromFile("black_piece.png");
    sf::CircleShape circle;
    circle.setTexture(&t);
    circle.setRadius(piece.get_radius());
    circle.setPosition(piece.where_to_draw());
    if (piece.is_selected()) {
    circle.setOutlineThickness(4.f);
    circle.setOutlineColor(sf::Color::Red);
    }
    Window.draw(circle);
}

void App::show() {
    sf::Texture texture;
    texture.loadFromFile("malomtabla.png");
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(1080, 1080));
    rect.setTexture(&texture);
    std::array<Piece, 18> All_Pieces = Malom.get_game().get_view();
    for (size_t i = 0; i < 18; i++) {
        draw_piece(All_Pieces[i]);
    }
}

void App::app() {
    while(Window.isOpen()) {
        sf::Event Event;
        while(Window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                Window.close();
            if (Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Right) {
                sf::Vector2f click(Event.mouseButton.x, Event.mouseButton.y);
                Malom.phase_control(click);
            }
        }
        show();
    }
}