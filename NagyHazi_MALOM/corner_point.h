#ifndef NAGYHAZI_MALOM_CORNER_POINT_H
#define NAGYHAZI_MALOM_CORNER_POINT_H
#include "point.h"

class Corner_Point : public Point {
public:
    Corner_Point() : Point() {}

    bool Checking_Neighbours(const Map&) const;

};

#endif //NAGYHAZI_MALOM_CORNER_POINT_H
