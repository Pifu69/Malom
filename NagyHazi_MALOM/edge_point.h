#ifndef NAGYHAZI_MALOM_EDGE_POINT_H
#define NAGYHAZI_MALOM_EDGE_POINT_H
#include "point.h"
#include "map.h"

class Edge_Point : public Point {
public:
    Edge_Point(size_t, size_t);

    bool checking_neighbours(const Map&) const;
};

#endif //NAGYHAZI_MALOM_EDGE_POINT_H
