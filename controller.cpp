#include "controller.h"
#include <cmath>

Controller::Controller() : Game_State() {}

int Controller::make_index_valid(int idx, int max) const {
    if (idx < 0) idx += max;
    if (idx >= max) idx -= max;
    return idx;
}

int Controller::distance(sf::Vector2f v1, sf::Vector2f v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

std::optional<Position> Controller::which_point_clicked(sf::Vector2f click, Colour expected) {
    std::optional<Position> pos;
    int max;
    if (expected == None) max = 30;
    else max = 45;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if (Game_State[i][j].get_state() == expected) {
                int d = distance(click, Game_State[i][j].get_position().position_to_vector());
                if (d < max) {
                    pos = Game_State[i][j].get_position();
                    return pos;
                }
            }
        }
    }
    return pos;
}

bool Controller::is_there_move(const Position& pos) const {
    int shell = pos.get_shell();
    int point = pos.get_point();
    if (point % 2 == 0) {
        if (Game_State[shell][(point+1)%8].get_state() == None
        || Game_State[shell][(point+8-1)%8].get_state() == None) return true;
    }
    if (point % 2 != 0) {
        if (Game_State[(shell+1)%3][point].get_state() == None
        || Game_State[(shell+3-1)%3][point].get_state() == None
        || Game_State[shell][(point+1)%8].get_state() == None
        || Game_State[shell][(point+3-1)%8].get_state() == None) return true;
    }
    return false;
}

bool Controller::can_move(Colour colour) const {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (Game_State[i][j].get_state() == colour)
                if (is_there_move(Position(i, j))) return true;
        }
    }
    return false;
}

bool Controller::is_move_valid(const Position& selected, const Position& where_to) const {
    int selected_shell = selected.get_shell();
    int selected_point = selected.get_point();
    if (selected_point % 2 != 0 && selected_shell % 2 == 0) {
        if (where_to.get_shell() == 1 && where_to.get_point() == selected_point) return true;
        if ((make_index_valid(where_to.get_point()+1, 8) == selected_point
        || make_index_valid(where_to.get_point()-1, 8) == selected_point)
        && where_to.get_shell() == selected_shell) return true;
    }
    if (selected_point % 2 != 0 && selected_shell % 2 != 0) {
        if (where_to.get_point() == selected_point
        && (make_index_valid(where_to.get_shell()+1, 3) == selected_shell
        || make_index_valid(where_to.get_shell()-1, 3) == selected_shell)) return true;
        if (where_to.get_shell() == selected_shell
        && (make_index_valid(where_to.get_point()+1, 8) == selected_point
            || make_index_valid(where_to.get_point()-1, 8) == selected_point)) return true;
    }
    if (selected_point % 2 == 0) {
        if (where_to.get_shell() == selected_shell
        && (make_index_valid(where_to.get_point()+1, 8) == selected_point
        || make_index_valid(where_to.get_point()-1, 8) == selected_point)) return true;
    }
    return false;
}

bool Controller::valid_move_condition(Game& game, Colour on_turn, size_t idx, Position& clicked) const {
    return (game.get_player(on_turn).get_num() > 3
            && is_move_valid(game.get_player(on_turn).get_pieces()[idx].get_position(), clicked))
            || game.get_player(on_turn).get_num() == 3;
}

bool Controller::click_control(Game& game, Colour expected, Colour on_turn, Position clicked) {
    if (expected != None) {
        size_t idx = game.get_player(expected).search_piece(clicked);
        game.get_player(expected).set_piece_selected(idx);
        return false;
    }
    size_t idx = game.get_player(on_turn).search_selected();
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
    if (!which_point_clicked(click, other).has_value()) return false;
    Position clicked = which_point_clicked(click, other).value();
    if (!game.get_player(other).is_all_in_trap(Game_State) && Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()])) return false;
    size_t idx = game.get_player(other).search_piece(clicked);
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
    if (!which_point_clicked(click, None).has_value()) return false;
    Position clicked = which_point_clicked(click, None).value();
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
    if (!can_move(on_turn)) {
        game.set_end_game();
        return false;
    }
    if (game.get_player(on_turn).has_trap()) {
        return trap_control(game, on_turn, click);
    }
    Colour expected = game.get_turn();
    if (game.get_player(on_turn).is_there_selected()) expected = None;
    if (!which_point_clicked(click, expected).has_value()) {
        game.get_player(on_turn).set_all_piece_unselected();
        return false;
    }
    Position clicked = which_point_clicked(click, expected).value();
    return click_control(game, expected, on_turn, clicked);
}

