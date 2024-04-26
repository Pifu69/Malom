#ifndef NAGYHAZI_MALOM_POSITION_H
#define NAGYHAZI_MALOM_POSITION_H

#include <SFML/Graphics.hpp>

class Position {
    int Position_Shell;
    int Position_Point;
public:
    Position(int shell, int point);

    void set_position(int shell, int point);
    int get_shell() const;
    int get_point() const;

    //bool is_valid_move(const Map&, Colour);
    sf::Vector2f position_to_vector();

    Position& operator=(const Position&);
    bool operator==(const Position&);
};

#endif //NAGYHAZI_MALOM_POSITION_H
