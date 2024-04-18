#include "map.h"

Map::Map() : Num_Of_Shells(3), Game_Map({Shell(0), Shell(1), Shell(2)}) {}

const Shell& Map::operator[](int shell) const {
    if (shell < 0) shell = Num_Of_Shells + shell;
    if (shell >= Num_Of_Shells) shell = shell - Num_Of_Shells;
    return Game_Map[shell];
}

Shell& Map::operator[](int shell) {
    if (shell < 0) shell = Num_Of_Shells + shell;
    if (shell >= Num_Of_Shells) shell = shell - Num_Of_Shells;
    return Game_Map[shell];
}

bool Map::checking_neighbours(const Point& New_Point) const {
    Colour colour = New_Point.get_state();
    int shell = New_Point.get_position().get_shell();
    int point = New_Point.get_position().get_point();
    if (point % 2 != 0) {
        if (Game_Map[shell][point-1].get_state() == colour && Game_Map[shell][point-2].get_state() == colour) return true;
        if (Game_Map[shell][point+1].get_state() == colour && Game_Map[shell][point+2].get_state() == colour) return true;
    }
    if (point % 2 == 0) {
        if (Game_Map[shell][point-1].get_state() == colour && Game_Map[shell][point+1].get_state() == colour) return true;
        if (Game_Map[shell-1][point].get_state() == colour && Game_Map[shell+1][point].get_state() == colour) return true;
    }
    return false;
}

