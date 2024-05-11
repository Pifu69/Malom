#include "controller.h"
#include <cmath>

Controller::Controller() : Game_State() {}

bool Controller::valid_move_condition(Game& game, Colour on_turn, size_t idx, Position& clicked) {
    return ((game.get_player(on_turn).get_num() > 3
            && game.get_player(on_turn).get_pieces()[idx].get_position().is_move_valid(clicked))
           || game.get_player(on_turn).get_num() == 3);
}

bool Controller::click_control(Game& game, Colour expected, Colour on_turn, Position clicked) {
    if (expected != None) {
        size_t idx = game.get_player(expected).search_piece(clicked).value();
        game.get_player(expected).set_piece_selected(idx);
        return false;
    }
    size_t idx = game.get_player(on_turn).search_selected().value();
    if (valid_move_condition(game, on_turn, idx, clicked)) {
        Game_State[game.get_player(on_turn).get_pieces()[idx].get_position().get_shell()][game.get_player(on_turn).get_pieces()[idx].get_position().get_point()].set_state(None);
        Game_State[clicked.get_shell()][clicked.get_point()].set_state(on_turn);
        game.get_player(on_turn).get_pieces()[idx].set_position(clicked);
        game.get_player(on_turn).get_pieces()[idx].set_selection_false();
        if (Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()])) {
            game.get_player(on_turn).set_trap_true();
            return false;
        }
        return true;
    }
    game.get_player(on_turn).get_pieces()[idx].set_selection_false();
    return false;
}

bool Controller::trap_control(Game& game, Colour on_turn, sf::Vector2f click) {
    Colour other;
    if (on_turn == White) other = Black;
    if (on_turn == Black) other = White;
    if (!Game_State.which_point_clicked(click, other).has_value()) return false;
    Position clicked = Game_State.which_point_clicked(click, other).value();
    if (!game.get_player(other).is_all_in_trap(Game_State) && Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()])) return false;
    size_t idx = game.get_player(other).search_piece(clicked).value();
    game.get_player(other).set_piece_off_field(idx);
    Game_State[clicked.get_shell()][clicked.get_point()].set_state(None);
    game.get_player(on_turn).set_trap_false();
    return true;
}

/////////////////////////////////////////First_Phase//////////////////////////////////////////////////////
bool Controller::first_phase_controller(Game& game, sf::Vector2f click) {
    Colour on_turn = game.get_turn();
    if (game.get_player(on_turn).has_trap()) {
        return trap_control(game, on_turn, click);
    }
    if (!Game_State.which_point_clicked(click, None).has_value()) return false;
    Position clicked = Game_State.which_point_clicked(click, None).value();
    Game_State[clicked.get_shell()][clicked.get_point()].set_state(on_turn);
    game.get_player(on_turn).set_piece_on_field(clicked);
    if (Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()])) {
        game.get_player(on_turn).set_trap_true();
        return false;
    }
    return true;
}
///////////////////////////////Second_And_Third_Phase////////////////////////////////////////////////////////////
bool Controller::second_and_third_phase_controller(Game& game, sf::Vector2f click) {
    Colour on_turn = game.get_turn();
    if (!Game_State.can_move(on_turn)) {
        game.set_end_game();
        return false;
    }
    if (game.get_player(on_turn).has_trap()) {
        return trap_control(game, on_turn, click);
    }
    Colour expected = game.get_turn();
    if (game.get_player(on_turn).is_there_selected()) expected = None;
    if (!Game_State.which_point_clicked(click, expected).has_value()) {
        game.get_player(on_turn).set_all_piece_unselected();
        return false;
    }
    Position clicked = Game_State.which_point_clicked(click, expected).value();
    return click_control(game, expected, on_turn, clicked);
}

