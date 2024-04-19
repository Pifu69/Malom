#ifndef NAGYHAZI_MALOM_CONTROLLER_H
#define NAGYHAZI_MALOM_CONTROLLER_H

#include "map.h"
#include "position.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include "colour.h"

class Controller {
    Map Game_State;
public:
    Controller();

    int make_index_valid(int, int) const;

    int distance(sf::Vector2f, sf::Vector2f);

    std::optional<Position> which_point_clicked(sf::Vector2f, Colour);

    bool is_move_valid(const Position&, const Position&) const;

    void first_phase_controller(Game&, sf::Vector2f);
    void second_phase_controller(const Game&, sf::Vector2f);
    void third_phase_controller(const Game&, sf::Vector2f);
};

#endif //NAGYHAZI_MALOM_CONTROLLER_H
