#include "player.h"
#include "piece.h"

Player::Player(Colour colour) : Team_Color(colour), Num_Of_Pieces_On_Field(0){
    for (size_t i = 0; i < 9; i++){
        Player_Pieces[i] = Piece(Team_Color);
    }
}

int Player::get_num() const {
    return Num_Of_Pieces_On_Field;
}

std::array<Piece, 9>& Player::get_pieces(){
    return Player_Pieces;
}

bool Player::is_there_selected() const {
    for (size_t i = 0; i < 9; i++) {
        if (Player_Pieces[i].is_selected()) return true;
    }
    return false;
}

bool Player::is_all_in_trap(const Map& map) const {
    for (size_t i = 0; i < 9; i++) {
        if (Player_Pieces[i].is_on_field()) {
            if (!map.checking_neighbours(map[Player_Pieces[i].get_position().get_shell()][Player_Pieces[i].get_position().get_point()]))
                return false;
        }
    }
    return true;
}

bool Player::has_trap() const {
    return Trap;
}

size_t Player::search_piece(const Position &position) {
    for (size_t i = 0; i < 9; i++) {
        if (Player_Pieces[i].is_on_field() && Player_Pieces[i].get_position() == position) return i;
    }
    return -1;
}

size_t Player::search_selected() const {
    for (size_t i = 0; i < 9; i++) {
        if (Player_Pieces[i].is_selected()) return i;
    }
    return -1;
}

void Player::set_all_piece_unselected() {
    for (size_t i = 0; i < 9; i++)
        Player_Pieces[i].set_selection_false();
}

void Player::set_piece_selected(size_t i) {
    Player_Pieces[i].set_selection_true();
}

void Player::set_trap_true() {
    Trap = true;
}

void Player::set_trap_false() {
    Trap = false;
}

void Player::increase_num() {
    Num_Of_Pieces_On_Field += 1;
}

void Player::decrease_num() {
    Num_Of_Pieces_On_Field -= 1;
}

void Player::set_piece_on_field(const Position& position) {
    for (size_t i = 0; i < 9; i++) {
        if (!Player_Pieces[i].is_on_field()) {
            Player_Pieces[i].set_position(position);
            increase_num();
            return;
        }
    }
}

void Player::set_piece_off_field(size_t idx) {
    Player_Pieces[idx].set_off_field();
    decrease_num();
}

