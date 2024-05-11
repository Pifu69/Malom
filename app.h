#ifndef NAGYHAZI_MALOM_APP_H
#define NAGYHAZI_MALOM_APP_H

#include <SFML/Graphics.hpp>
#include "piece.h"
#include <iostream>
#include <array>
#include "game_mechanic.h"

class App {
    float Window_Size;
    sf::Texture Window_Texture;
    sf::RenderWindow Window;
    sf::RectangleShape Board;
    sf::Texture White_Piece;
    sf::Texture Black_Piece;
    Game_Mech Malom;
public:
    App(float);

    void draw_piece(const Piece&);
    void show();

    void app();
};

#endif //NAGYHAZI_MALOM_APP_H
