#ifndef NAGYHAZI_MALOM_FIELD_H
#define NAGYHAZI_MALOM_FIELD_H
#include "colour.h"
#include "position.h"

class Point {
protected:
    Colour Point_Colour;
    Position Point_Position;
public:
    ///@brief Point osztály konstruktora
    ///@param shell_index az objektum pozíciójának első koordinátája
    ///@param index az objektum pozíciójának második koordinátája
    Point(size_t shell_index, size_t index);

    Position get_position() const;
    Colour get_state() const;
    void set_state(Colour);
};

#endif //NAGYHAZI_MALOM_FIELD_H
