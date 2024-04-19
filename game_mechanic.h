#ifndef NAGYHAZI_MALOM_GAME_MECHANIC_H
#define NAGYHAZI_MALOM_GAME_MECHANIC_H

#include "game.h"
#include "controller.h"

class Game_Mech {
    Game Malom_Game;
    Controller Game_Controller;
public:
    Game_Mech();

    Game get_game() const;
    Controller get_controller() const;

    void phase_control(sf::Vector2f);
};

#endif //NAGYHAZI_MALOM_GAME_MECHANIC_H
