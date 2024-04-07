#include "map.h"

Shell& Map::operator[](int shell){
    if (shell < 0) shell = Num_Of_Shells + shell;
    return Game_Map[shell];
}

