#include "piece.h"
Piece::Piece(Colour colour) : Team_Colour(colour), Is_Selected(false) {}

bool Piece::is_on_field() const {
    return Piece_Position.has_value();
}

bool Piece::is_selected() const {
    return Is_Selected;
}

Colour Piece::get_colour() const {
    return Team_Colour;
}

Position Piece::get_position() const {
    if (Piece_Position.has_value())
        return Piece_Position.value();
    else
        throw "No Piece There";
}

void Piece::set_position(const Position &p) {
    Piece_Position.emplace(p);
}

void Piece::set_off_field() {
    Piece_Position.reset();
}

void Piece::set_selection_true() {
    Is_Selected = true;
}

void Piece::set_selection_false() {
    Is_Selected = false;
}

sf::Vector2f Piece::where_to_draw(float r) const {
    sf::Vector2f res = Piece_Position->position_to_vector();
    return sf::Vector2f(res.x-r, res.y-r);
}



