#ifndef NAGYHAZI_MALOM_PIECE_H
#define NAGYHAZI_MALOM_PIECE_H
#include <iostream>
#include <vector>
#include <string>
#include "position.h"

class Piece{
    Position Piece_Position;
public:
    Piece();

    Position get_position() const;

    void set_piece(const Position&);

    Piece& operator=(const Piece&);

};
#endif //NAGYHAZI_MALOM_PIECE_H

