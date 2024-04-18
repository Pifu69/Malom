#include "game_mechanic.h"

Game_Mech::Game_Mech() : Malom_Game(), Game_Controller() {}

Game Game_Mech::get_game() const {
    return Malom_Game;
}

Controller Game_Mech::get_controller() const {
    return Game_Controller;
}

void Game_Mech::phase_control(sf::Vector2f click) {
    switch (Malom_Game.get_phase()) {
        case First: Game_Controller.first_phase_controller(Malom_Game, click); break;
        case Second: Game_Controller.second_phase_controller(Malom_Game, click); break;
        case Third: Game_Controller.third_phase_controller(Malom_Game, click); break;
        default: break;
    }
}