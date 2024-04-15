#ifndef NAGYHAZI_MALOM_PIECE_H
#define NAGYHAZI_MALOM_PIECE_H
#include <iostream>
#include <vector>
#include <string>
#include "position.h"
#include "colour.h"
#include <SFML/Graphics.hpp>

class Piece{
    Colour Team_Colour;
    std::optional<Position> Piece_Position;
    static const int Radius = 20;
public:
    Piece(Colour = None);

    bool is_on_field() const;

    Position get_position() const;

    void set_position(const Position&);

    sf::Vector2f where_to_draw() const;

    void draw_piece(sf::RenderWindow& w) const ;

};
#endif //NAGYHAZI_MALOM_PIECE_H

