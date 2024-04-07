#ifndef NAGYHAZI_MALOM_PLAYER_H
#define NAGYHAZI_MALOM_PLAYER_H
#include <iostream>
#include "piece.h"
#include "name.h"
#include <array>

class Player{
    Name Player_Name;
    int Num_Of_Pieces_On_Field;
    std::array<Piece, 9> Player_Pieces;
public:
    Player(Name name);

    Name get_Name() const;
    int get_num() const;
    size_t search_piece(const Position &position) const;

};
#endif //NAGYHAZI_MALOM_PLAYER_H

