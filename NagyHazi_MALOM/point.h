#ifndef NAGYHAZI_MALOM_FIELD_H
#define NAGYHAZI_MALOM_FIELD_H
#include "colour.h"
#include "piece.h"
#include "player.h"
#include "map.h"

class Point {
protected:
    Colour colour;
    Position Position;
public:
    Point(size_t shell_index, size_t index);
    Colour get_state() const;
    void set_state(Colour);

    virtual bool Checking_Neighbours(const Map&) const = 0;

    virtual ~Point() {}
};

#endif //NAGYHAZI_MALOM_FIELD_H
