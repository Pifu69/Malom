#include "position.h"

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