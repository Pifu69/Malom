#ifndef NAGYHAZI_MALOM_APP_H
#define NAGYHAZI_MALOM_APP_H

#include <SFML/Graphics.hpp>
#include "piece.h"
#include <iostream>
#include <array>
#include "game_mechanic.h"

class App {
    sf::RenderWindow Window;
    Game_Mech Malom;
public:
    App();

    void draw_piece(const Piece&);
    void show();

    void app();
};

#endif //NAGYHAZI_MALOM_APP_H
