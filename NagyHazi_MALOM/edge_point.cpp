#include "edge_point.h"

bool Edge_Point::Checking_Neighbours(const Map &m) const {
    size_t s_index = Position.get_shell();
    size_t p_index = Position.get_point();
    Point *ep1 = m[s_index-1].operator[](p_index);
    Point *ep2 = m[s_index+1].operator[](p_index);
    Point *cp1 = m[s_index].operator[](p_index-1);
    Point *cp2 = m[s_index].operator[](p_index+1);
    bool statement1 = (ep1->get_state() == colour) && (ep2->get_state() == colour);
    bool statement2 = (cp1->get_state() == colour) && (cp2->get_state() == colour);
    return statement1 || statement2;
}