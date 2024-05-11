#include "position.h"

Position::Position(size_t shell, size_t point) : Position_Shell(shell), Position_Point(point) {}

size_t make_index_valid(int idx, int max) {
    if (idx < 0) idx += max;
    if (idx >= max) idx -= max;
    return idx;
}

size_t Position::get_shell() const {
    return Position_Shell;
}

size_t Position::get_point() const {
    return Position_Point;
}

Position& Position::operator=(const Position& p){
    if (this != &p){
        Position_Shell = p.Position_Shell;
        Position_Point = p.Position_Point;
    }
    return *this;
}

bool Position::operator==(const Position& position) const {
    if (Position_Shell == position.Position_Shell && Position_Point == position.Position_Point)
        return true;
    else
        return false;
}

sf::Vector2f Position::position_to_vector() const {
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

bool Position::is_move_valid(const Position& where_to) const {
    if (Position_Point % 2 != 0 && Position_Shell % 2 == 0) {
        if (where_to.get_shell() == 1 && where_to.get_point() == Position_Point) return true;
        if ((make_index_valid(where_to.get_point()+1, 8) == Position_Point
             || make_index_valid(where_to.get_point()-1, 8) == Position_Point)
            && where_to.get_shell() == Position_Shell) return true;
    }
    if (Position_Point % 2 != 0 && Position_Shell % 2 != 0) {
        if (where_to.get_point() == Position_Point
            && (make_index_valid(where_to.get_shell()+1, 3) == Position_Shell
                || make_index_valid(where_to.get_shell()-1, 3) == Position_Shell)) return true;
        if (where_to.get_shell() == Position_Shell
            && (make_index_valid(where_to.get_point()+1, 8) == Position_Point
                || make_index_valid(where_to.get_point()-1, 8) == Position_Shell)) return true;
    }
    if (Position_Point % 2 == 0) {
        if (where_to.get_shell() == Position_Shell
            && (make_index_valid(where_to.get_point()+1, 8) == Position_Point
                || make_index_valid(where_to.get_point()-1, 8) == Position_Point)) return true;
    }
    return false;
}