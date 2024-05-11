#ifndef NAGYHAZI_MALOM_MAP_H
#define NAGYHAZI_MALOM_MAP_H
#include <iostream>
#include "shell.h"
#include "point.h"
#include <array>
#include <cmath>
#include <optional>

class Map {
    int Num_Of_Shells;
    std::array<Shell, 3> Game_Map;
public:
    Map();

    std::optional<Position> which_point_clicked(sf::Vector2f, Colour);

    bool is_there_move(const Position&) const;
    bool can_move(Colour) const;

    const Shell& operator[](int) const;
    Shell& operator[](int);

    bool checking_neighbours(const Point&) const;
};
int distance(sf::Vector2f, sf::Vector2f);



#endif //NAGYHAZI_MALOM_MAP_H
