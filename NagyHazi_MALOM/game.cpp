#include "game.h"

Game::Game() : Turn(White), Game_Phase(First), Game_Round(1), Black_Player(Black), White_Player(White) {}

Player Game::get_white_player() const {
    return White_Player;
}

Player Game::get_black_player() const {
    return Black_Player;
}

std::array<Piece, 18> Game::get_view() const {
    std::array<Piece, 18> All_Pieces;
    size_t idx = 0;
    for (size_t i = 0; i < 9; i++) {
        All_Pieces[idx++] = White_Player.get_pieces()[i];
    }
    for (size_t i = 0; i < 9; i++) {
        All_Pieces[idx++] = Black_Player.get_pieces()[i];
    }
    return All_Pieces;
}

Phase Game::get_phase() const {
    return Game_Phase;
}

Colour Game::get_turn() const {
    return Turn;
}

void Game::switch_turn() {
    switch (Turn) {
        case White: Turn = Black; break;
        case Black: Turn = White; break;
        default: break;
    }
}

void Game::step_phase() {
    switch (Game_Phase) {
        case First:
            if (Game_Round > 9) Game_Phase = Second;
            break;
        case Second:
            if (White_Player.get_num() < 4 || Black_Player.get_num() < 4) Game_Phase = Third;
            break;
        case Third: if (White_Player.get_num() < 3 || Black_Player.get_num() < 3)  Game_Phase = End; break;
        default: break;
    }
}

bool Game::first_phase() const {
    return (Game_Phase == First);
}

bool Game::second_phase() const {
    return (Game_Phase == Second);
}

bool Game::third_phase() const {
    return (Game_Phase == Third);
}

