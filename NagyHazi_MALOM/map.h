#ifndef NAGYHAZI_MALOM_MAP_H
#define NAGYHAZI_MALOM_MAP_H
#include <iostream>
#include "shell.h"
#include <array>

class Map {
    int Num_Of_Shells;
    std::array<Shell, 3> Game_Map;
public:
    Map() : Num_Of_Shells(3) {
        for (size_t i = 0; i < Num_Of_Shells; i++){
            Game_Map[i] = Shell(i);
        }
    }

    Shell& operator[](int);
};



#endif //NAGYHAZI_MALOM_MAP_H
