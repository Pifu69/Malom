#include "point.h"

Team_Colour Point::get_state() const {
    return colour;
}

void Point::set_state(Team_Colour tc) {
    colour = tc;
}
