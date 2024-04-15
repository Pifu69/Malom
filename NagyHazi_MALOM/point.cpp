#include "point.h"

Point::Point(size_t shell_index, size_t index) : colour(None), Position(shell_index, index) {}

Colour Point::get_state() const {
    return colour;
}

void Point::set_state(Colour tc) {
    colour = tc;
}
