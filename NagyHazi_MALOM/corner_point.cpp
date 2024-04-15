#include "corner_point.h"

Corner_Point::Corner_Point(size_t shell_index, size_t index) : Point(shell_index, index) {}

bool Corner_Point::Checking_Neighbours(const Map &m) const {
    size_t s_index = Position.get_shell();
    size_t p_index = Position.get_point();
    Point *ep1 = m[s_index].operator[](p_index-1);
    Point *cp1 = m[s_index].operator[](p_index-2);
    Point *ep2 = m[s_index].operator[](p_index+1);
    Point *cp2 = m[s_index].operator[](p_index+2);
    bool statement1 = (ep1->get_state() == colour) && (cp1->get_state() == colour);
    bool statement2 = (ep2->get_state() == colour) && (cp2->get_state() == colour);
    return statement1 || statement2;
}