#ifndef NAGYHAZI_MALOM_CORNER_POINT_H
#define NAGYHAZI_MALOM_CORNER_POINT_H
#include "point.h"
#include "map.h"

class Corner_Point : public Point {
public:
    Corner_Point(size_t shell_index, size_t index);

    bool checking_neighbours(const Map&) const;

};

#endif //NAGYHAZI_MALOM_CORNER_POINT_H
