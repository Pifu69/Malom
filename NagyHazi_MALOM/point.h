#ifndef NAGYHAZI_MALOM_FIELD_H
#define NAGYHAZI_MALOM_FIELD_H
#include "colour.h"
#include "position.h"
#include "map.h"

class Point {
protected:
    Colour colour;
    Position Point_Position;
public:
    Point(size_t shell_index, size_t index);

    Position get_position() const;
    Colour get_state() const;
    void set_state(Colour);

    virtual bool checking_neighbours(const Map&) const = 0;

    virtual ~Point() {}
};

#endif //NAGYHAZI_MALOM_FIELD_H
