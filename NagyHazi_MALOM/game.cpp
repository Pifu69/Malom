#include "game.h"

Game::Game() : Black_Player(Black), White_Player(White){
    Window.create(sf::VideoMode(1080, 1080), "Malom", sf::Style::Close);
}

sf::RenderWindow& Game::get_window() {
    return Window;
}

Player Game::get_white_player() const {
    return White_Player;
}


Player Game::get_black_player() const {
    return Black_Player;
}

void Game::show() {
    sf::Texture texture;
    texture.loadFromFile("malomtabla.png");

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(1080, 1080));
    rect.setTexture(&texture);
    Window.clear(sf::Color::White);
    Window.draw(rect);
    for (size_t i = 0; i < 9; i++) {
        if (White_Player.get_pieces()[i].is_on_field()) White_Player.get_pieces()[i].draw_piece(Window);
    }
    Window.display();
}
