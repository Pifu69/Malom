#include "map.h"

Map::Map() : Num_Of_Shells(3), Game_Map({Shell(0), Shell(1), Shell(2)}) {}

int distance(sf::Vector2f v1, sf::Vector2f v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

std::optional<Position> Map::which_point_clicked(sf::Vector2f click, Colour expected) {
    std::optional<Position> pos;
    int max;
    if (expected == None) max = 30;
    else max = 45;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if (Game_Map[i][j].get_state() == expected) {
                int d = distance(click, Game_Map[i][j].get_position().position_to_vector());
                if (d < max) {
                    pos = Game_Map[i][j].get_position();
                    return pos;
                }
            }
        }
    }
    return pos;
}

bool Map::is_there_move(const Position& pos) const {
    int shell = pos.get_shell();
    int point = pos.get_point();
    if (point % 2 == 0) {
        if (Game_Map[shell][(point+1)%8].get_state() == None
            || Game_Map[shell][(point+8-1)%8].get_state() == None) return true;
    }
    if (point % 2 != 0) {
        if (Game_Map[(shell+1)%3][point].get_state() == None
            || Game_Map[(shell+3-1)%3][point].get_state() == None
            || Game_Map[shell][(point+1)%8].get_state() == None
            || Game_Map[shell][(point+3-1)%8].get_state() == None) return true;
    }
    return false;
}

bool Map::can_move(Colour colour) const {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (Game_Map[i][j].get_state() == colour)
                if (is_there_move(Position(i, j))) return true;
        }
    }
    return false;
}

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
    if (shell % 2 != 0 && point % 2 != 0) {
        if (Game_Map[shell-1][point].get_state() == colour && Game_Map[shell+1][point].get_state() == colour) return true;
        if (Game_Map[shell][point-1].get_state() == colour && Game_Map[shell][point+1].get_state() == colour) return true;
    }
    if (shell % 2 == 0 && point % 2 != 0) {
        if (Game_Map[(shell+1)%3][point].get_state() == colour && Game_Map[(shell+3-1)%3][point].get_state() == colour) return true;
        if (Game_Map[shell][(point+8-1)%8].get_state() == colour && Game_Map[shell][(point+1)%8].get_state() == colour) return true;
    }
    if (point % 2 == 0) {
        if (Game_Map[shell][(point+1)%8].get_state() == colour && Game_Map[shell][(point+2)%8].get_state() == colour) return true;
        if (Game_Map[shell][(point+8-1)%8].get_state() == colour && Game_Map[shell][(point+8-2)%8].get_state() == colour) return true;
    }
    return false;
}
