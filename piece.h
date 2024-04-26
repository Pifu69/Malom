#ifndef NAGYHAZI_MALOM_PIECE_H
#define NAGYHAZI_MALOM_PIECE_H
#include <iostream>
#include <string>
#include "position.h"
#include "colour.h"
#include <SFML/Graphics.hpp>
#include <optional>

class Piece{
    Colour Team_Colour;
    std::optional<Position> Piece_Position;
    bool Is_Selected;
    static const int Radius = 50;
public:
    Piece(Colour = None);

    bool is_on_field() const;
    bool is_selected() const;
    int get_radius() const;
    Colour get_colour() const;
    Position get_position() const;

    void set_position(const Position&);
    void set_off_field();
    void set_selection_true();
    void set_selection_false();

    sf::Vector2f where_to_draw() const;

};
#endif //NAGYHAZI_MALOM_PIECE_H

