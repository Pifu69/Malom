#ifndef NAGYHAZI_MALOM_EDGE_POINT_H
#define NAGYHAZI_MALOM_EDGE_POINT_H
#include "point.h"

class Edge_Point : public Point {
public:
    Edge_Point(size_t shell_index, size_t index) : Point(shell_index, index) {}

    bool Checking_Neighbours(const Map&) const;
};

#endif //NAGYHAZI_MALOM_EDGE_POINT_H
