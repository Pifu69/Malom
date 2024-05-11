#include "point.h"

Point::Point(size_t shell_index, size_t index) : Point_Colour(None), Point_Position(shell_index, index) {}

Position Point::get_position() const {
    return Point_Position;
}

Colour Point::get_state() const {
    return Point_Colour;
}

void Point::set_state(Colour tc) {
    Point_Colour = tc;
}

