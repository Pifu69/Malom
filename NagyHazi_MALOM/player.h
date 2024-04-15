#ifndef NAGYHAZI_MALOM_PLAYER_H
#define NAGYHAZI_MALOM_PLAYER_H
#include <iostream>
#include "piece.h"
#include "name.h"
#include "colour.h"
#include <array>

class Player{
    //Name Player_Name;
    Colour Team_Color;
    int Num_Of_Pieces_On_Field;
    std::array<Piece, 9> Player_Pieces;
public:
    Player(Colour colour);

    Name get_Name() const;
    int get_num() const;
    std::array<Piece, 9> get_pieces() const;
    size_t search_selected_piece(const Position &position) const;

    void set_piece_on_field(const Position&);

};
#endif //NAGYHAZI_MALOM_PLAYER_H

