#include "map.h"

Map::Map() : Num_Of_Shells(3), Game_Map({Shell(0), Shell(1), Shell(2)}) {}

const Shell& Map::operator[](int shell) const {
    if (shell < 0) shell = Num_Of_Shells + shell;
    return Game_Map[shell];
}

Shell& Map::operator[](int shell) {
    if (shell < 0) shell = Num_Of_Shells + shell;
    return Game_Map[shell];
}

