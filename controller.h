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

    bool is_there_move(const Position&) const;
    bool can_move(Colour) const;

    bool is_player_blocked(Colour) const;
    bool is_move_valid(const Position&, const Position&) const;
    bool valid_move_condition(Game&, Colour, size_t, Position&) const;

    bool click_control(Game&, Colour, Colour, Position);
    bool trap_control(Game&, Colour, sf::Vector2f);

    bool first_phase_controller(Game&, sf::Vector2f);
    bool second_and_third_phase_controller(Game&, sf::Vector2f);
};

#endif //NAGYHAZI_MALOM_CONTROLLER_H
