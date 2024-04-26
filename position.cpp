#include "position.h"

Position::Position(int shell, int point) : Position_Shell(shell), Position_Point(point) {}

void Position::set_position(int shell, int point) {
    Position_Shell = shell;
    Position_Point = point;
}

int Position::get_shell() const {
    return Position_Shell;
}

int Position::get_point() const {
    return Position_Point;
}

Position& Position::operator=(const Position& p){
    if (this != &p){
        Position_Shell = p.Position_Shell;
        Position_Point = p.Position_Point;
    }
    return *this;
}

bool Position::operator==(const Position& position) {
    if (Position_Shell == position.Position_Shell && Position_Point == position.Position_Point)
        return true;
    else
        return false;
}

sf::Vector2f Position::position_to_vector() {
    sf::Vector2f res;
    float d = (3 - Position_Shell) * 144;;
    res.x = 108 + Position_Shell * 144;
    res.y = 108 + Position_Shell * 144;
    int point = Position_Point;

    if (point == 1 or point == 5) res.x += d;
    if (point < 5 and point > 1) res.x += 2*d;

    if (point == 3 or point == 7) res.y += d;
    if (point < 7 and point > 3) res.y += 2*d;

    return res;
}

/*
bool Position::is_valid_move(const Map& map, Colour colour) {
    int shell = Position_Shell;
    int point = Position_Point;
    if (point % 2)
}
 */