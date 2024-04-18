#ifndef NAGYHAZI_MALOM_APP_H
#define NAGYHAZI_MALOM_APP_H

#include "game.h"
#include <SFML/Graphics.hpp>
#include "piece.h"
#include <iostream>
#include <array>
#include "controller.h"

class App {
    sf::RenderWindow Window;
    Game Malom_Game;
    Controller Game_Controller;
public:
    App();

    void draw_piece(const Piece&);
    void show();

    void app();
};

#endif //NAGYHAZI_MALOM_APP_H
