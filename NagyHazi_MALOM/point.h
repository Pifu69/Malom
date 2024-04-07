#ifndef NAGYHAZI_MALOM_FIELD_H
#define NAGYHAZI_MALOM_FIELD_H
#include "colour.h"
#include "piece.h"
#include "player.h"
#include "map.h"

class Point {
protected:
    Player Piece_Owner;
    Team_Colour colour;
    size_t Point_Index;
public:
    Point() : colour(None), Piece_Owner(Name()) {}
    Team_Colour get_state() const;
    void set_state(Team_Colour);

    virtual bool Checking_Neighbours(const Map&) = 0;
};

#endif //NAGYHAZI_MALOM_FIELD_H
