#include "piece.h"
Piece::Piece() : Piece_Position() {}

Position Piece::get_position() const { return Piece_Position; }

void Piece::set_piece(const Position &p) {
    Piece_Position = p;
}

Piece& Piece::operator=(const Piece &p) {
    if (this != &p) {
        Piece_Position = p.Piece_Position;
    }
    return *this;
}
