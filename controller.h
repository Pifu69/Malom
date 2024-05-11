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

    static bool valid_move_condition(Game&, Colour, size_t, Position&);

    bool click_control(Game&, Colour, Colour, Position);
    bool trap_control(Game&, Colour, sf::Vector2f);

    bool first_phase_controller(Game&, sf::Vector2f);
    bool second_and_third_phase_controller(Game&, sf::Vector2f);
};

#endif //NAGYHAZI_MALOM_CONTROLLER_H
