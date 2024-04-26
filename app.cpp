#include "app.h"

App::App() : Malom() {
    Window.create(sf::VideoMode(1080, 1080), "Malom", sf::Style::Close);
}

void App::draw_piece(const Piece& piece) {
    if (piece.is_on_field()) {
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
}

void App::show() {
    sf::Texture texture;
    texture.loadFromFile("malomtabla.png");
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(1080, 1080));
    rect.setTexture(&texture);
    Window.clear(sf::Color::White);
    Window.draw(rect);
    std::array<Piece, 18> All_Pieces = Malom.get_game().get_view();
    for (size_t i = 0; i < 18; i++) {
        draw_piece(All_Pieces[i]);
    }
    Window.display();
}
//#define TEST

void App::app() {
    while(Window.isOpen()) {
        sf::Event Event;
        while(Window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                Window.close();
#ifndef TEST
            if (Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) {
                std::cout << Event.mouseButton.x << ' ' << Event.mouseButton.y << std::endl;
                sf::Vector2f click(Event.mouseButton.x, Event.mouseButton.y);
                Malom.phase_control(click);
            }
#endif
        }
#ifdef TEST
        sf::Vector2f click1(110, 104);
        Malom.phase_control(click1);
        sf::Vector2f click2(537, 257);
        Malom.phase_control(click2);
        sf::Vector2f click3(536, 110);
        Malom.phase_control(click3);
        sf::Vector2f click4(977, 109);
        Malom.phase_control(click4);
        sf::Vector2f click5(828, 253);
        Malom.phase_control(click5);
        sf::Vector2f click6(827, 545);
        Malom.phase_control(click6);
        sf::Vector2f click7(252, 262);
        Malom.phase_control(click7);
        sf::Vector2f click8(257, 542);
        Malom.phase_control(click8);
        sf::Vector2f click9(108, 549);
        Malom.phase_control(click9);
        sf::Vector2f click10(107, 969);
        Malom.phase_control(click10);
        sf::Vector2f click11(393, 534);
        Malom.phase_control(click11);
        sf::Vector2f click12(396, 394);
        Malom.phase_control(click12);
        sf::Vector2f click13(539, 396);
        Malom.phase_control(click13);
        sf::Vector2f click14(392, 688);
        Malom.phase_control(click14);
        sf::Vector2f click15(259, 830);
        Malom.phase_control(click15);
        sf::Vector2f click16(688, 397);
        Malom.phase_control(click16);
        sf::Vector2f click17(830, 832);
        Malom.phase_control(click17);
        sf::Vector2f click18(540, 829);
        Malom.phase_control(click18);
        sf::Vector2f click19(387, 544);
        Malom.phase_control(click19);
#endif
        show();
    }
}