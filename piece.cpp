#include "piece.h"
Piece::Piece(Colour colour) : Team_Colour(colour), Is_Selected(false) {}

bool Piece::is_on_field() const {
    return Piece_Position.has_value();
}

bool Piece::is_selected() const {
    return Is_Selected;
}

int Piece::get_radius() const {
    return Radius;
}

Colour Piece::get_colour() const {
    return Team_Colour;
}

Position Piece::get_position() const { return Piece_Position.value(); }

void Piece::set_position(const Position &p) {
    Piece_Position.emplace(p);
}

void Piece::set_selection_true() {
    Is_Selected = true;
}

void Piece::set_selection_false() {
    Is_Selected = false;
}

sf::Vector2f Piece::where_to_draw() const {
    sf::Vector2f res;
    float d = (3 - Piece_Position->get_shell()) * 144;;
    res.x = 108 + Piece_Position->get_shell() * 144;
    res.y = 108 + Piece_Position->get_shell() * 144;
    int point = Piece_Position->get_point();

    if (point == 1 or point == 5) res.x += d;
    if (point < 5 and point > 1) res.x += 2 * d;

    if (point == 3 or point == 7) res.y += d;
    if (point < 7 and point > 3) res.y += 2 * d;

    res.x -= Radius;
    res.y -= Radius;
    return res;
}

