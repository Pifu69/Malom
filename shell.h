#ifndef NAGYHAZI_MALOM_SHELL_H
#define NAGYHAZI_MALOM_SHELL_H

#include <iostream>
#include "point.h"
#include <memory>
#include <array>


class Shell{
    int Num_Of_Points;
    std::array<Point, 8> Shell_Points;
public:
    ///@brief shell osztály konstruktora
    ///@param index a shellen található pontok első koordinátája
    Shell(size_t index);

    ///@brief indexelő operátorok
    ///@param idx a shell ennyiedik pontját adja vissza
    ///@return az adott indexen lévő Point objektum
    const Point& operator[](size_t) const;
    Point& operator[](size_t);
};

#endif //NAGYHAZI_MALOM_SHELL_H
