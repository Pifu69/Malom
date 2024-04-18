#ifndef NAGYHAZI_MALOM_MAP_H
#define NAGYHAZI_MALOM_MAP_H
#include <iostream>
#include "shell.h"
#include "point.h"
#include <array>

class Map {
    int Num_Of_Shells;
    std::array<Shell, 3> Game_Map;
public:
    Map();

    const Shell& operator[](int) const;
    Shell& operator[](int);
};



#endif //NAGYHAZI_MALOM_MAP_H
