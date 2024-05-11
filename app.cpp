#include "app.h"

App::App(float size) : Window_Size(size), Malom() {
    Window.create(sf::VideoMode(Window_Size, Window_Size), "Malom", sf::Style::Close);
    Window_Texture.loadFromFile("C:/Users/Zsombi/program/egyetem/C++/NagyHazi_MALOM/graph/malomtabla.png");
    Board.setSize(sf::Vector2f(Window_Size, Window_Size));
    Board.setTexture(&Window_Texture);
    White_Piece.loadFromFile("C:/Users/Zsombi/program/egyetem/C++/NagyHazi_MALOM/graph/white_piece.png");
    Black_Piece.loadFromFile("C:/Users/Zsombi/program/egyetem/C++/NagyHazi_MALOM/graph/black_piece.png");
}

void App::draw_piece(const Piece& piece) {
    if (piece.is_on_field()) {
        sf::CircleShape circle;
        if (piece.get_colour() == White) circle.setTexture(&White_Piece);
        if (piece.get_colour() == Black) circle.setTexture(&Black_Piece);
        circle.setRadius(Window_Size/20);
        circle.setPosition(piece.where_to_draw(Window_Size/20));
        if (piece.is_selected()) {
            circle.setOutlineThickness(4.f);
            circle.setOutlineColor(sf::Color::Red);
        }
        Window.draw(circle);
    }
}

void App::show() {
    Window.clear(sf::Color::White);
    Window.draw(Board);
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