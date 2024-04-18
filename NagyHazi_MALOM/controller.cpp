#include "controller.h"

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
    if (expected == None) max = 5;
    else max = 20;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if (Game_State[i][j].get_state() == expected) {
                int d = distance(click, Game_State[i][j].get_position().position_to_vector());
                if (d < max) pos = Game_State[i][j].get_position();
            }
        }
    }
    return pos;
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

void Controller::first_phase_controller(const Game& game, sf::Vector2f click) {
    Colour on_turn = game.get_turn();
    if (!which_point_clicked(click, None).has_value()) return;
    Position clicked = which_point_clicked(click, None).value();
    switch (on_turn) {
        case White:
            Game_State[clicked.get_shell()][clicked.get_point()].set_state(White);
            game.get_white_player().set_piece_on_field(clicked);
            game.get_white_player().increase_num();
            if (Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()]))
                game.get_white_player().set_trap_true();
            break;
        case Black:
            Game_State[clicked.get_shell()][clicked.get_point()].set_state(Black);
            game.get_black_player().set_piece_on_field(clicked);
            game.get_black_player().increase_num();
            if (Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()]))
                game.get_black_player().set_trap_true();
            break;
        default: break;
    }
}

void Controller::second_phase_controller(const Game& game, sf::Vector2f click) {
    Colour on_turn = game.get_turn();
    Colour expected = game.get_turn();
    switch (on_turn) {
        case White:
            if (game.get_white_player().is_there_selected()) expected = None;
            break;
        case Black:
            if (game.get_black_player().is_there_selected()) expected = None;
            break;
        default: break;
    }
    if (!which_point_clicked(click, expected).has_value()) {
        if (on_turn == White) game.get_white_player().set_all_piece_unselected();
        if (on_turn == Black) game.get_black_player().set_all_piece_unselected();
        return;
    }
    Position clicked = which_point_clicked(click, expected).value();
    if (expected == None && on_turn == White) {
        size_t idx = game.get_white_player().search_selected();
        if (is_move_valid(game.get_white_player().get_pieces()[idx].get_position(), clicked)) {
            Game_State[game.get_white_player().get_pieces()[idx].get_position().get_shell()][game.get_white_player().get_pieces()[idx].get_position().get_point()].set_state(None);
            Game_State[clicked.get_shell()][clicked.get_point()].set_state(White);
            game.get_white_player().get_pieces()[idx].set_position(clicked);
            game.get_white_player().get_pieces()[idx].set_selection_false();
            if (Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()]))
                game.get_white_player().set_trap_true();
        }
    }
    if (expected == None && on_turn == Black) {
        size_t idx = game.get_black_player().search_selected();
        if (is_move_valid(game.get_white_player().get_pieces()[idx].get_position(), clicked)) {
            Game_State[game.get_black_player().get_pieces()[idx].get_position().get_shell()][game.get_black_player().get_pieces()[idx].get_position().get_point()].set_state(None);
            Game_State[clicked.get_shell()][clicked.get_point()].set_state(Black);
            game.get_black_player().get_pieces()[idx].set_position(clicked);
            game.get_black_player().get_pieces()[idx].set_selection_false();
            if (Game_State.checking_neighbours(Game_State[clicked.get_shell()][clicked.get_point()]))
                game.get_black_player().set_trap_true();
        }
    }
    if (expected == White) {
        size_t idx = game.get_white_player().search_piece(clicked);
        game.get_white_player().get_pieces()[idx].set_selection_true();
    }
    if (expected == Black) {
        size_t idx = game.get_black_player().search_piece(clicked);
        game.get_black_player().get_pieces()[idx].set_selection_true();
    }
}

void Controller::third_phase_controller(const Game &, sf::Vector2f) {
    return;
}

