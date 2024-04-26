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

    int get_game_round() const;
    Player& get_white_player();
    Player& get_black_player();
    Player& get_player(Colour);
    std::array<Piece, 18> get_view();
    Phase get_phase() const;
    Colour get_turn() const;
    bool Is_Trap(Colour) const;

    void switch_turn();
    void step_phase();
    void step_round();
    void set_end_game();

    bool first_phase() const;
    bool second_phase() const;
    bool third_phase() const;
};

#endif //NAGYHAZI_MALOM_GAME_H
