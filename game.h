#ifndef NAGYHAZI_MALOM_GAME_H
#define NAGYHAZI_MALOM_GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "map.h"
#include <iostream>
#include <array>
#include "phase.h"
#include "colour.h"


class Game {
    Colour Turn;
    Phase Game_Phase;
    int Game_Round;
    Player White_Player;
    Player Black_Player;
public:
    Game();

    Player& get_player(Colour);
    std::array<Piece, 18> get_view();
    Phase get_phase() const;
    Colour get_turn() const;

    void switch_turn();
    void step_phase();
    void step_round();
    void set_end_game();
};

#endif //NAGYHAZI_MALOM_GAME_H
